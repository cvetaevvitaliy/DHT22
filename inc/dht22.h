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
typedef enum{
	DHT22_OK,
	DHT22_ERROR,
	DHT22_CRC_ERROR
} DHT22_RESULT;

/**
 * Describes the state of the sensor
 */
typedef enum{
	DHT22_RECEIVED,		/*< Data have been received but not yet processed */
	DHT22_RECEIVING,	/*< Data from sensor are currently being received */
	DHT22_READY	/*< The sensor has finished all operations and is in wait state */
} DHT22_STATE;

/**
 * This structure hold all the variables necessary for communication with the sensor
 */
typedef struct{
	uint8_t				bitsRX[5];
	float 				temp;
	float				hum;
	uint8_t				crcErrorFlag;
	DHT22_STATE			state;
	TIM_HandleTypeDef	timHandle;
	TIM_IC_InitTypeDef	timICHandle;
	uint32_t			timChannel;
	uint16_t			gpioPin;
	GPIO_TypeDef*		gpioPort;
	int					bitPos;
	IRQn_Type			timerIRQn;
	uint32_t			gpioAlternateFunction; // TODO not needed for STM32F1
	uint16_t			lastVal;
	void				(*errorCallback)(DHT22_RESULT);
} DHT22_HandleTypeDef;

/**
 * Initializes the DHT22 communication
 * @param	handle - a pointer to the DHT22 handle
 * @return	whether the function was successful or not
 */
DHT22_RESULT DHT22_Init(DHT22_HandleTypeDef* handle);

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