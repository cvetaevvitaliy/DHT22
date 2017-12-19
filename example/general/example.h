#include "dht22.h"

#ifdef STM32F1
extern TIM_HandleTypeDef  htim3;
extern UART_HandleTypeDef huart1;
#define PIN GPIO_PIN_6
#define PORT GPIOA
#define TIMER &htim3
#define TIMER_CHANNEL TIM_CHANNEL_1
#endif

void example();
