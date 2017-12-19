#include "example.h"

dht22 dht;

static void error() {
    while (1) {}
}

void example() {

    dht22_config dht_config;

    dht_config.gpio_pin      = PIN;
    dht_config.gpio_port     = PORT;
    dht_config.timer         = TIMER;
    dht_config.timer_channel = TIMER_CHANNEL;

    if (dht22_init(&dht_config, &dht) != DHT22_OK) error();

    while (1) {
        if (dht22_read_data(&dht) != DHT22_OK) error();

        float temp = dht.temp;
        float hum  = dht.hum;

        UNUSED(temp);
        UNUSED(hum);

        // int data[2] = {dht.temp * 1000, dht.hum * 1000};
        // HAL_UART_Transmit_DMA(&huart1, (uint8_t*)data, 8);
        // HAL_Delay(3000);
    }
}