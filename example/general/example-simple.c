#include "example.h"
#include "example_defs.h"

dht22 dht;

void example() {

    dht22_config dht_config;

    dht_config.type          = DHT22;
    dht_config.gpio_pin      = PIN;
    dht_config.gpio_port     = PORT;
    dht_config.timer         = TIMER;
    dht_config.timer_channel = TIMER_CHANNEL;

    dht22_init(&dht_config, &dht);

    while (1) {
        dht22_read_data(&dht);

        // To access measurements in tenths of their respective units
        // (0.1 degC, 0.1 %RH) use temp and hum fields from the dht22 struct
        // f(dht.temp, dht.hum);

        // Or get measurements as floats
        float temp = dht22_get_temp(&dht);
        float hum  = dht22_get_hum(&dht);

        HAL_Delay(3000);
    }
}
