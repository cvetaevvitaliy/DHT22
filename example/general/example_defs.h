#ifndef EXAMPLE_DEFS_H
#define EXAMPLE_DEFS_H

#include "dht22.h"

#if defined STM32F0

extern TIM_HandleTypeDef  htim14;
extern UART_HandleTypeDef huart1;
#define PIN GPIO_PIN_4
#define PORT GPIOA
#define TIMER &htim14
#define TIMER_CHANNEL TIM_CHANNEL_1
#define UART &huart1

#elif defined STM32F1

extern TIM_HandleTypeDef  htim3;
extern UART_HandleTypeDef huart1;
#define PIN GPIO_PIN_6
#define PORT GPIOA
#define TIMER &htim3
#define TIMER_CHANNEL TIM_CHANNEL_1
#define UART &huart1

#endif

#endif // EXAMPLE_DEFS_H
