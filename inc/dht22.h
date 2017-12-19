#ifndef DHT22_H
#define DHT22_H

#ifdef STM32F1
#include "stm32f1xx_hal.h"
#endif

#ifdef STM32F4
#include "stm32f4xx_hal.h"
#endif

/**
 * Possible return values of the functions
 */
typedef enum { DHT22_OK, DHT22_ERROR, DHT22_CRC_ERROR } DHT22_RESULT;

/**
 * Describes the state of the sensor
 */
typedef enum {
    DHT22_RECEIVED,  /*< Data have been received but not yet processed */
    DHT22_RECEIVING, /*< Data from sensor are currently being received */
    DHT22_READY /*< The sensor has finished all operations and is in wait state
                   */
} DHT22_STATE;

/**
 * This structure is for initializing the sensor handle
 */
typedef struct {
    uint16_t      gpioPin;
    GPIO_TypeDef *gpioPort;
#ifdef STM32F4
    uint32_t gpioAlternateFunction;
#endif
    TIM_TypeDef *timer;
    uint32_t     timerChannel;
    void (*errorCallback)(DHT22_RESULT);
} DHT22_InitTypeDef;

/**
 * This structure is the sensor handle
 */
typedef struct {
    // RX buffer
    uint8_t  bitsRX[5];
    int      bitPos;
    uint16_t lastVal;

    // Readings
    float temp;
    float hum;

    // State
    uint8_t     crcErrorFlag;
    DHT22_STATE state;

    // Configuration
    TIM_HandleTypeDef  timHandle;
    TIM_IC_InitTypeDef timICHandle;
    uint32_t           timChannel;
    uint16_t           gpioPin;
    GPIO_TypeDef *     gpioPort;
    IRQn_Type          timerIRQn;
#ifdef STM32F4
    uint32_t gpioAlternateFunction;
#endif
    void (*errorCallback)(DHT22_RESULT);
} DHT22_HandleTypeDef;

/**
 * Initializes the DHT22 communication
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_Init(DHT22_HandleTypeDef *handle);

/**
 * Deinitializes the DHT22 communication
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_DeInit(DHT22_HandleTypeDef *handle);

/**
 * Reads the current temperature and humidity from the sensor
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_ReadData(DHT22_HandleTypeDef *handle);

/**
 * Handles the pin interrupt
 * @param	handle - a pointer to the DHT22 handle
 */
void DHT22_InterruptHandler(DHT22_HandleTypeDef *handle);

#endif /* DHT22_H */
