#include "dht22.h"

/**
 * Sets up the pin as an output
 * @param	handle - a pointer to the DHT22 handle
 */
static void set_pin_out(DHT22_HandleTypeDef* handle) {
    HAL_NVIC_DisableIRQ(handle->config.timer_irqn);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin  = handle->config.gpio_pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
#ifdef STM32F1
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
#else
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
#endif
    HAL_GPIO_Init(handle->config.gpio_port, &GPIO_InitStruct);
}

/**
 * Sets up the pin as an input
 * @param	handle - a pointer to the DHT22 handle
 */
static void set_pin_in(DHT22_HandleTypeDef* handle) {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin  = handle->config.gpio_pin;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
#ifdef STM32F1
    GPIO_InitStruct.Mode  = GPIO_MODE_AF_INPUT;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
#else
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = handle->config.gpio_alternate_function;
#endif
    HAL_GPIO_Init(handle->config.gpio_port, &GPIO_InitStruct);
    // TODO: maybe optional vvv
    HAL_NVIC_SetPriority(handle->config.timer_irqn, 0, 0);
    HAL_NVIC_EnableIRQ(handle->config.timer_irqn);
}

DHT22_RESULT DHT22_ReadData(DHT22_HandleTypeDef* handle) {
    if (handle->state != DHT22_READY) return DHT22_ERROR;

    handle->state = DHT22_BUSY;

    // clear previous state
    handle->bit_pos            = -1;
    handle->last_val           = 0;
    handle->error_flags.parity = false;
    handle->error_flags.timing = false;
    for (int i = 0; i < 5; i++) handle->rx_buffer[i] = 0;

    // generate the start sequence
    set_pin_out(handle);
    HAL_GPIO_WritePin(handle->config.gpio_port, handle->config.gpio_pin,
                      GPIO_PIN_RESET);
    HAL_Delay(2);
    set_pin_in(handle);

    __HAL_TIM_SET_COUNTER(handle->config.timer, 0);

    // enable the timer interrupts
    if (HAL_TIM_IC_Start_IT(handle->config.timer,
                            handle->config.timer_channel) != HAL_OK)
        return DHT22_ERROR;

    uint32_t startTick = HAL_GetTick();

    // wait for the state machine to finish
    while (handle->state != DHT22_FINISHED &&
           HAL_GetTick() - startTick < 1000) {}

    // disable the timer interrupts
    if (HAL_TIM_IC_Stop_IT(handle->config.timer,
                           handle->config.timer_channel) != HAL_OK)
        return DHT22_ERROR;

    if (handle->error_flags.timing) return DHT22_TIMING_ERROR;
    if (handle->error_flags.parity) return DHT22_CHECKSUM_ERROR;

    if (handle->state == DHT22_FINISHED) {
        handle->state = DHT22_READY;
        return DHT22_OK;
    }
    return DHT22_ERROR;
}

DHT22_RESULT DHT22_Init(DHT22_Config* config, DHT22_HandleTypeDef* handle) {
    handle->config = *config;
    return DHT22_OK;
}

DHT22_RESULT DHT22_DeInit(DHT22_HandleTypeDef* handle) { return DHT22_OK; }

static void write_bit(DHT22_HandleTypeDef* handle, bool bit) {
    uint8_t byten = handle->bit_pos / 8;
    uint8_t bitn  = 7 - handle->bit_pos % 8;
    if (bit) {
        handle->rx_buffer[byten] |= 1 << bitn;
    } else {
        handle->rx_buffer[byten] &= ~(1 << bitn);
    }
}

static float get_float(uint8_t* dht_data) {
    uint16_t v = 0;
    v |= (dht_data[0] & 0x7F) << 8;
    v |= dht_data[1];

    float value = 0.1f * v;
    if (dht_data[0] & 0x80) value *= -1.0f;
    return value;
}

static void finish_rx(DHT22_HandleTypeDef* handle) {
    uint8_t sum = 0;
    for (int i = 0; i < 4; i++) sum += handle->rx_buffer[i];

    if (sum == handle->rx_buffer[4]) { // checksums match
        handle->hum  = get_float(&handle->rx_buffer[0]);
        handle->temp = get_float(&handle->rx_buffer[2]);
    } else {
        handle->error_flags.parity = true;
    }
    handle->state = DHT22_FINISHED;
}

#define BETWEEN(a, b) (dt >= a && dt <= b)

void DHT22_InterruptHandler(DHT22_HandleTypeDef* handle) {
    uint16_t val = HAL_TIM_ReadCapturedValue(handle->config.timer,
                                             handle->config.timer_channel);

    uint16_t dt = val - handle->last_val;

    if (handle->bit_pos == -1) { // start bit
        if (BETWEEN(150, 170)) {
            handle->bit_pos++;
        } else {
            handle->error_flags.timing = true;
            handle->state              = DHT22_FINISHED;
        }
    } else {                   // data bits
        if (BETWEEN(70, 90)) { // zero
            write_bit(handle, false);
            handle->bit_pos++;
        } else if (BETWEEN(110, 130)) { // one
            write_bit(handle, true);
            handle->bit_pos++;
        } else { // invalid
            handle->error_flags.timing = true;
            handle->state              = DHT22_FINISHED;
        }
    }

    if (handle->bit_pos == 40) { // finished
        finish_rx(handle);
    }

    handle->last_val = val;
}
