#include "dht22.h"

#define DHT22_StartIT()                                                 \
    if (HAL_TIM_IC_Start_IT(&handle->timHandle, handle->tim_channel) != \
        HAL_OK)                                                         \
    return DHT22_ERROR
#define DHT22_StopIT()                                                         \
    if (HAL_TIM_IC_Stop_IT(&handle->timHandle, handle->tim_channel) != HAL_OK) \
    return DHT22_ERROR

/**
 * Sets up the pin as an output
 * @param	handle - a pointer to the DHT22 handle
 */
void DHT22_SetPinOUT(DHT22_HandleTypeDef *handle) {

#ifdef STM32F1
    HAL_NVIC_DisableIRQ(handle->timer_irqn);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin   = handle->gpio_pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(handle->gpio_port, &GPIO_InitStruct);
#endif

#ifdef STM32F4
    HAL_NVIC_DisableIRQ(handle->timer_irqn);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin   = handle->gpio_pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(handle->gpio_port, &GPIO_InitStruct);
#endif
}

/**
 * Sets up the pin as an input
 * @param	handle - a pointer to the DHT22 handle
 */
void DHT22_SetPinIN(DHT22_HandleTypeDef *handle) {

#ifdef STM32F1
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin   = handle->gpio_pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_AF_INPUT;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(handle->gpio_port, &GPIO_InitStruct);
    HAL_NVIC_EnableIRQ(handle->timer_irqn);
    HAL_NVIC_SetPriority(handle->timer_irqn, 0, 0);
#endif

#ifdef STM32F4
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin       = handle->gpio_pin;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = handle->gpio_alternate_function;
    HAL_GPIO_Init(handle->gpioPort, &GPIO_InitStruct);
    HAL_NVIC_EnableIRQ(handle->timer_irqn);
    HAL_NVIC_SetPriority(handle->timer_irqn, 0, 0);
#endif
}

/**
 * Initiates a transfer of sensor data
 * @param	handle - a pointer to the DHT22 handle
 */
DHT22_RESULT DHT22_InitiateTransfer(DHT22_HandleTypeDef *handle) {

    DHT22_SetPinOUT(handle);
    HAL_GPIO_WritePin(handle->gpio_port, handle->gpio_pin, GPIO_PIN_RESET);
    HAL_Delay(2);
    DHT22_SetPinIN(handle);

    handle->bit_pos = -1;
    for (int i = 0; i < 5; i++) {
        handle->rx_buffer[i] = 0;
    }
    handle->state = DHT22_RECEIVING;
    DHT22_StartIT();

    return DHT22_OK;
}

DHT22_RESULT DHT22_Init(DHT22_InitTypeDef *init, DHT22_HandleTypeDef *handle) {
    handle->gpio_pin  = init->gpio_pin;
    handle->gpio_port = init->gpio_port;
#ifdef STM32F4
    handle->gpio_alternate_function = init->gpio_alternate_function;
#endif

    handle->timHandle.Instance = init->timer;
    handle->tim_channel        = init->timer_channel;

    handle->timHandle.Init.Period        = 0xFFFF;
    handle->timHandle.Init.Prescaler     = 0;
    handle->timHandle.Init.ClockDivision = 0;
    handle->timHandle.Init.CounterMode   = TIM_COUNTERMODE_UP;
    if (HAL_TIM_IC_Init(&handle->timHandle) != HAL_OK) {
        return DHT22_ERROR;
    }
    handle->timICHandle.ICPolarity  = TIM_ICPOLARITY_FALLING;
    handle->timICHandle.ICSelection = TIM_ICSELECTION_DIRECTTI;
    handle->timICHandle.ICPrescaler = TIM_ICPSC_DIV1;
    handle->timICHandle.ICFilter    = 0;
    if (HAL_TIM_IC_ConfigChannel(&handle->timHandle, &handle->timICHandle,
                                 handle->tim_channel) != HAL_OK) {
        return DHT22_ERROR;
    }
    return DHT22_OK;
}

DHT22_RESULT DHT22_DeInit(DHT22_HandleTypeDef *handle) { return DHT22_OK; }

void DHT22_InterruptHandler(DHT22_HandleTypeDef *handle) {

    uint16_t val =
        HAL_TIM_ReadCapturedValue(&handle->timHandle, handle->tim_channel);

    uint32_t freq = HAL_RCC_GetPCLK2Freq();

    uint16_t val2;
    if (val > handle->last_val)
        val2 = val - handle->last_val;
    else
        val2 = 65535 + val - handle->last_val;

    handle->last_val = val;

    float time = 1000000.0 * val2 / freq;

    if (handle->bit_pos < 0) {
        if (time > 155.0 && time < 165.0) {
            handle->bit_pos = 0;
        }
    } else if (handle->bit_pos >= 0 && handle->bit_pos < 40) {
        if (time > 78.0 && time < 97.0) {
            handle->rx_buffer[handle->bit_pos / 8] &=
                ~(1 << (7 - handle->bit_pos % 8));
            handle->bit_pos++;
        } else if (time > 120.0 && time < 145.0) {
            handle->rx_buffer[handle->bit_pos / 8] |=
                1 << (7 - handle->bit_pos % 8);
            handle->bit_pos++;
        } else {
            handle->bit_pos = -1;
            HAL_TIM_IC_Stop_IT(&handle->timHandle, handle->tim_channel);
            handle->state = DHT22_READY;
        }
    }

    if (handle->bit_pos == 40) {
        handle->bit_pos = -1;
        HAL_TIM_IC_Stop_IT(&handle->timHandle, handle->tim_channel);
        uint8_t sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += handle->rx_buffer[i];
        }
        if (sum == handle->rx_buffer[4]) {
            handle->crc_error_flag = 0;

            int16_t temp10 = 0;
            if ((handle->rx_buffer[2] & 0x80) == 0x80) {
                temp10 |= (handle->rx_buffer[2] & 0x7F) << 8;
                temp10 |= handle->rx_buffer[3];
                temp10 *= -1;
            } else {
                temp10 |= handle->rx_buffer[2] << 8;
                temp10 |= handle->rx_buffer[3];
            }
            handle->temp = 0.1 * temp10;

            int16_t hum10 = 0;
            if ((handle->rx_buffer[0] & 0x80) == 0x80) {
                hum10 |= (handle->rx_buffer[0] & 0x7F) << 8;
                hum10 |= handle->rx_buffer[1];
                hum10 *= -1;
            } else {
                hum10 |= handle->rx_buffer[0] << 8;
                hum10 |= handle->rx_buffer[1];
            }
            handle->hum = 0.1 * hum10;
        } else {
            handle->crc_error_flag = 1;
        }
        handle->state = DHT22_RECEIVED;
    }
}

DHT22_RESULT DHT22_ReadData(DHT22_HandleTypeDef *handle) {
    DHT22_InitiateTransfer(handle);
    uint32_t startTick = HAL_GetTick();
    while (handle->state == DHT22_RECEIVING && HAL_GetTick() - startTick < 1000)
        ;
    if (handle->crc_error_flag == 1) {
        return DHT22_CRC_ERROR;
    }
    if (handle->state != DHT22_RECEIVED) {
        return DHT22_ERROR;
    } else {
        handle->state = DHT22_READY;
    }
    return DHT22_OK;
}
