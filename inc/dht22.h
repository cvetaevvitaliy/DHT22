#ifndef DHT22_H
#define DHT22_H

#if defined STM32F0
#include "stm32f0xx_hal.h"
#elif defined STM32F1
#include "stm32f1xx_hal.h"
#elif defined STM32F4
#include "stm32f4xx_hal.h"
#endif

#include <stdbool.h>

/**
 * Type of sensor
 */
typedef enum {
    /**
     * Supports: DHT11
     */
    DHT11,
    /**
     * Supports: DHT22, AM2302, AM2320
     */
    DHT22
} DHT_TYPE;

/**
 * Possible return values of the functions
 */
typedef enum {
    /**
     * Function call was successful
     */
    DHT22_OK,
    /**
     * Device busy (already reading data)
     */
    DHT22_ERROR_BUSY,
    /**
     * Timer could not be started
     */
    DHT22_ERROR_TIMER_START,
    /**
     * Timer could not be stopped
     */
    DHT22_ERROR_TIMER_STOP,
    /**
     * Protocol timing error. Look at timer calibration setup section in README
     */
    DHT22_ERROR_TIMING,
    /**
     * Data received is corrupted
     */
    DHT22_ERROR_CHECKSUM,
    /**
     * Device did not respond in time
     */
    DHT22_ERROR_TIMEOUT
} DHT22_RESULT;

/**
 * Describes the state of the sensor
 */
typedef enum {
    /**
     * The sensor is ready for next measurement
     */
    DHT22_READY,
    /**
     * The sensor is currently receiving data
     */
    DHT22_BUSY,
    /**
     * The sensor finished receiving data, data are awaiting processing
     */
    DHT22_FINISHED
} DHT22_STATE;

/**
 * This structure is for initializing the sensor handle
 */
typedef struct {
    /**
     * Type of the DHT sensor (DHT11/DHT22)
     */
    DHT_TYPE type;
    /**
     * GPIO pin connected to the DHT22 sensor
     */
    uint16_t gpio_pin;
    /**
     * GPIO port associated with the `gpio_pin`
     */
    GPIO_TypeDef* gpio_port;
    /**
     * Calibrated timer used for time measurements
     */
    TIM_HandleTypeDef* timer;
    /**
     * Input capture channel of the timer to be used for time measurements
     */
    uint32_t timer_channel;

#ifdef STM32F4
    /**
     * Alternate function of the GPIO pin when it is used by timer input channel
     */
    uint32_t gpio_alternate_function;
#endif
} dht22_config;

/**
 * This structure is the sensor handle
 */
typedef struct {
    /**
     * Buffer for receiving data (40bits = 5bytes)
     */
    uint8_t rx_buffer[5];

    /**
     * Current position of the bit being received (from -1 to 40)
     * -1 = start bit
     *  0 = 0th bit
     *  ...
     */
    int8_t bit_pos;

    /**
     * Timestamp of the last input capture. Used for calculating duration
     * between input captures and therefore the pulse length.
     */
    uint16_t last_val;

    /**
     * Temperature reading in tenths of a degree (152 => 15.2 degC)
     */
    int16_t temp;

    /**
     * Humidity reading in tenths of a percent (0-1000 => 0-100 %RH)
     */
    uint16_t hum;

    /**
     * Current state of the sensor
     */
    volatile DHT22_STATE state;

    /**
     * Error flags
     */
    struct {
        /**
         * Set when the checksum is incorrent
         */
        bool parity : 1;

        /**
         * Set when the timing of the pulses coming from the sensor is invalid
         */
        bool timing : 1;
    } error_flags;

    /**
     * Configuration of the sensor
     */
    dht22_config config;
} dht22;

/**
 * Initializes the DHT22 handle using the provided configuration
 * @param   config - a pointer to the initialization structure
 * @param	handle - a pointer to the DHT22 handle you want to initialize
 * @return	whether the function was successful or not
 */
DHT22_RESULT dht22_init(dht22_config* config, dht22* handle);

/**
 * Deinitializes the DHT22 communication
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT dht22_deinit(dht22* handle);

/**
 * Reads the current temperature and humidity from the sensor
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT dht22_read_data(dht22* handle);

/**
 * Extract the current temperature as a float
 * @param  handle - a pointer to the DHT22 handle
 * @return  temperature in degrees Celsius
 */
float dht22_get_temp(dht22* handle);

/**
 * Extract the current humidity as a float
 * @param  handle - a pointer to the DHT22 handle
 * @return  relative humidity in percent
 */
float dht22_get_hum(dht22* handle);

/**
 * Handles the timer interrupt
 * @param	handle - a pointer to the DHT22 handle
 */
void dht22_interrupt_handler(dht22* handle);

#endif /* DHT22_H */
