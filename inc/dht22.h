#ifndef DHT22_H
#define DHT22_H

#ifdef STM32F1
#include "stm32f1xx_hal.h"
#endif

#ifdef STM32F4
#include "stm32f4xx_hal.h"
#endif

#include <stdbool.h>

/**
 * Possible return values of the functions
 */
typedef enum {
    DHT22_OK,
    DHT22_ERROR,
    DHT22_TIMING_ERROR,
    DHT22_CHECKSUM_ERROR
} DHT22_RESULT;

/**
 * Describes the state of the sensor
 */
typedef enum {
    DHT22_READY,   /*< The sensor is ready for a next reading */
    DHT22_BUSY,    /*< Data from sensor are currently being received */
    DHT22_FINISHED /*< Data have been received but not yet processed */
} DHT22_STATE;

/**
 * This structure is for initializing the sensor handle
 */
typedef struct {
    uint16_t           gpio_pin;
    GPIO_TypeDef*      gpio_port;
    TIM_HandleTypeDef* timer;
    uint32_t           timer_channel;
    IRQn_Type          timer_irqn;

#ifdef STM32F4
    uint32_t gpio_alternate_function;
#endif
} DHT22_Config;

/**
 * This structure is the sensor handle
 */
typedef struct {
    // RX buffer
    uint8_t  rx_buffer[5];
    int      bit_pos;
    uint16_t last_val;

    // Readings
    float temp;
    float hum;

    // State
    DHT22_STATE state;
    struct {
        bool parity : 1;
        bool timing : 1;
    } error_flags;

    // config
    DHT22_Config config;
} DHT22_HandleTypeDef;

/**
 * Initializes the DHT22 communication
 * @param   config - a pointer to the initialization structure
 * @param	handle - a pointer to the DHT22 handle you want to initialize
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_Init(DHT22_Config* config, DHT22_HandleTypeDef* handle);

/**
 * Deinitializes the DHT22 communication
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_DeInit(DHT22_HandleTypeDef* handle);

/**
 * Reads the current temperature and humidity from the sensor
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_ReadData(DHT22_HandleTypeDef* handle);

/**
 * Handles the pin interrupt
 * @param	handle - a pointer to the DHT22 handle
 */
void DHT22_InterruptHandler(DHT22_HandleTypeDef* handle);

#endif /* DHT22_H */
