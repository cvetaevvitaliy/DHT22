#include "example.h"
#include "example_defs.h"

dht22 dht;

void example() {

    dht22_config dht_config;

    dht_config.gpio_pin      = PIN;
    dht_config.gpio_port     = PORT;
    dht_config.timer         = TIMER;
    dht_config.timer_channel = TIMER_CHANNEL;

    dht22_init(&dht_config, &dht);

    while (1) {
        dht22_read_data(&dht);

        // Use temp and hum fields from the dht struct
        // f(dht.temp, dht.hum);

        HAL_Delay(3000);
    }
}
