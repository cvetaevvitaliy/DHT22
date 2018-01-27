#include "example.h"
#include "example_defs.h"
#include <string.h>

dht22 dht;

static void error(DHT22_RESULT res, int bit_pos) {
    char msg[64];
    snprintf(msg, 64, "Error occured %d (bit_pos=%d)\r\n", res, bit_pos);
    HAL_UART_Transmit_DMA(UART, (uint8_t*)msg, strlen(msg));
    while (1) {}
}

void example() {

    dht22_config dht_config;

    dht_config.gpio_pin      = PIN;
    dht_config.gpio_port     = PORT;
    dht_config.timer         = TIMER;
    dht_config.timer_channel = TIMER_CHANNEL;

    char         str[32];
    DHT22_RESULT r;

    if ((r = dht22_init(&dht_config, &dht)) != DHT22_OK) error(r, -10);

    while (1) {
        if ((r = dht22_read_data(&dht)) != DHT22_OK) error(r, dht.bit_pos);

        float temp = dht.temp;
        float hum  = dht.hum;

        snprintf(str, 32, "temp: %d, hum: %d\r\n", (int)(temp * 10),
                 (int)(hum * 10));
        HAL_UART_Transmit_DMA(UART, (uint8_t*)str, strlen(str));

        HAL_Delay(3000);
    }
}
