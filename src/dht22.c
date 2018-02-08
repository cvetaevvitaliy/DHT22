#include "dht22.h"

/**
 * Sets up the pin as an output
 * @param	handle - a pointer to the DHT22 handle
 */
static void set_pin_out(dht22* handle) {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin  = handle->config.gpio_pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
#if defined STM32F0 || defined STM32F1
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
static void set_pin_in(dht22* handle) {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin  = handle->config.gpio_pin;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
#if defined STM32F0
    GPIO_InitStruct.Mode  = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
#elif defined STM32F1
    GPIO_InitStruct.Mode  = GPIO_MODE_AF_INPUT;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
#else
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = handle->config.gpio_alternate_function;
#endif
    HAL_GPIO_Init(handle->config.gpio_port, &GPIO_InitStruct);
}

float dht22_get_temp(dht22* handle) { return handle->temp * 0.1f; }

float dht22_get_hum(dht22* handle) { return handle->hum * 0.1f; }

DHT22_RESULT dht22_read_data(dht22* handle) {
    if (handle->state != DHT22_READY) return DHT22_ERROR_BUSY;

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
                            handle->config.timer_channel) != HAL_OK) {
        return DHT22_ERROR_TIMER_START;
    }

    uint32_t start_tick = HAL_GetTick();

    // wait for the state machine to finish
    while (handle->state != DHT22_FINISHED &&
           HAL_GetTick() - start_tick < 1000) {}

    // disable the timer interrupts
    if (HAL_TIM_IC_Stop_IT(handle->config.timer,
                           handle->config.timer_channel) != HAL_OK) {
        return DHT22_ERROR_TIMER_STOP;
    }

    if (handle->error_flags.timing) return DHT22_ERROR_TIMING;
    if (handle->error_flags.parity) return DHT22_ERROR_CHECKSUM;

    if (handle->state == DHT22_FINISHED) {
        handle->state = DHT22_READY;
        return DHT22_OK;
    }
    return DHT22_ERROR_TIMEOUT;
}

DHT22_RESULT dht22_init(dht22_config* config, dht22* handle) {
    handle->config = *config;
    return DHT22_OK;
}

DHT22_RESULT dht22_deinit(dht22* handle) { return DHT22_OK; }

/**
 * Writes 1 to the current bit position (bit_pos)
 * @param handle DHT22 handle
 * @param bit    bit to store
 */
static inline void write_one(dht22* handle) {
    uint8_t byten = handle->bit_pos / 8;
    uint8_t bitn  = 7 - handle->bit_pos % 8;
    handle->rx_buffer[byten] |= 1 << bitn;
}

/**
 * Perform last steps of reception like parity check, etc.
 * @param handle DHT22 handle
 */
static inline void finish_rx(dht22* handle) {
    uint8_t sum = 0;
    for (int i = 0; i < 4; i++) sum += handle->rx_buffer[i];

    handle->state = DHT22_FINISHED;

    if (sum != handle->rx_buffer[4]) { // checksums do not match
        handle->error_flags.parity = true;
        return;
    }

    // convert big endian to native endianness
    if (handle->config.type == DHT11) {
        // assuming rx_buffer[1] & rx_buffer[3] are always zero
        // limits the range of temperature to only non-negative values
        handle->hum  = handle->rx_buffer[0] * 10;
        handle->temp = handle->rx_buffer[2] * 10;
    } else {
        handle->hum = (handle->rx_buffer[0] << 8) | handle->rx_buffer[1];
        handle->temp =
            ((handle->rx_buffer[2] & 0x7F) << 8) | handle->rx_buffer[3];

        if (handle->rx_buffer[2] & 0x80) { // sign bit
            handle->temp *= -1;            // negative result
        }
    }
}

/**
 * Set dht22 fields to represent a timing error
 * @param handle DHT22 handle
 */
static inline void timing_error(dht22* handle) {
    handle->error_flags.timing = true;
    handle->state              = DHT22_FINISHED;
}

/**
 * Calculates the pulse length of the current pulse
 * @param  handle DHT22 handle
 * @return pulse length in microseconds
 */
static inline uint16_t get_pulse_length(dht22* handle) {
    uint16_t current_val = HAL_TIM_ReadCapturedValue(
        handle->config.timer, handle->config.timer_channel);
    uint16_t dt      = current_val - handle->last_val;
    handle->last_val = current_val;
    return dt;
}

#define BETWEEN(a, b) (dt >= a && dt <= b)

void dht22_interrupt_handler(dht22* handle) {
    uint16_t dt = get_pulse_length(handle);

    if (handle->bit_pos == -1) { // end of the start bit
        if (BETWEEN(120, 200)) { // [20 to 40]us + 80us + 80us - CPU time
            handle->bit_pos++;
        } else if (BETWEEN(0, 40)) { // [20-40]us - CPU time
            // fast CPU, caught beginning of the start bit
            // do nothing
        } else {
            timing_error(handle);
        }
    } else {                    // data bits
        if (BETWEEN(70, 100)) { // zero: 50us + [26-28]us
            // no need to write zero because the rx_buffer is zeroed in the
            // dht22_read_data call
            handle->bit_pos++;
        } else if (BETWEEN(110, 150)) { // one: 50us + 70us
            write_one(handle);
            handle->bit_pos++;
        } else { // invalid
            timing_error(handle);
        }
    }

    if (handle->bit_pos == 40) { // finished
        finish_rx(handle);
    }
}
