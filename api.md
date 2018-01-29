# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)            | Possible return values of the functions.
`enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)            | Describes the state of the sensor.
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`dht22_init`](#dht22_8h_1ab1c585a3f37b65ba94f3b6d0d95c548b)`(`[`dht22_config`](#structdht22__config)` * config,`[`dht22`](#structdht22)` * handle)`            | Initializes the DHT22 handle using the provided configuration.
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`dht22_deinit`](#dht22_8h_1af88e368924c132ae5b1dc20205019207)`(`[`dht22`](#structdht22)` * handle)`            | Deinitializes the DHT22 communication.
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`dht22_read_data`](#dht22_8h_1a4bc9e0ef8d5951f1da6c527096d0389c)`(`[`dht22`](#structdht22)` * handle)`            | Reads the current temperature and humidity from the sensor.
`public float `[`dht22_get_temp`](#dht22_8h_1a8e7d4088235734416133d613076292b0)`(`[`dht22`](#structdht22)` * handle)`            | Extract the current temperature as a float.
`public float `[`dht22_get_hum`](#dht22_8h_1a3c3a8020a175b494867bedd8af785224)`(`[`dht22`](#structdht22)` * handle)`            | Extract the current humidity as a float.
`public void `[`dht22_interrupt_handler`](#dht22_8h_1a6119816d8ad1b38b7c732472bba7b0ec)`(`[`dht22`](#structdht22)` * handle)`            | Handles the timer interrupt.
`struct `[`dht22`](#structdht22) | This structure is the sensor handle.
`struct `[`dht22_config`](#structdht22__config) | This structure is for initializing the sensor handle.

## Members

#### `enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633) 

Possible return values of the functions.

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
DHT22_OK            | Function call was successful.
DHT22_ERROR            | Function call was unsuccessful.
DHT22_TIMING_ERROR            | Timing error was detected.
DHT22_CHECKSUM_ERROR            | Checksum error was detected.

#### `enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79) 

Describes the state of the sensor.

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
DHT22_READY            | The sensor is ready for next measurement.
DHT22_BUSY            | The sensor is currently receiving data.
DHT22_FINISHED            | The sensor finished receiving data, data are awaiting processing.

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`dht22_init`](#dht22_8h_1ab1c585a3f37b65ba94f3b6d0d95c548b)`(`[`dht22_config`](#structdht22__config)` * config,`[`dht22`](#structdht22)` * handle)` 

Initializes the DHT22 handle using the provided configuration.

#### Parameters
* `config` - a pointer to the initialization structure 

* `handle` - a pointer to the DHT22 handle you want to initialize 

#### Returns
whether the function was successful or not

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`dht22_deinit`](#dht22_8h_1af88e368924c132ae5b1dc20205019207)`(`[`dht22`](#structdht22)` * handle)` 

Deinitializes the DHT22 communication.

#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
whether the function was successful or not

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`dht22_read_data`](#dht22_8h_1a4bc9e0ef8d5951f1da6c527096d0389c)`(`[`dht22`](#structdht22)` * handle)` 

Reads the current temperature and humidity from the sensor.

#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
whether the function was successful or not

#### `public float `[`dht22_get_temp`](#dht22_8h_1a8e7d4088235734416133d613076292b0)`(`[`dht22`](#structdht22)` * handle)` 

Extract the current temperature as a float.

#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
temperature in degrees Celsius

#### `public float `[`dht22_get_hum`](#dht22_8h_1a3c3a8020a175b494867bedd8af785224)`(`[`dht22`](#structdht22)` * handle)` 

Extract the current humidity as a float.

#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
relative humidity in percent

#### `public void `[`dht22_interrupt_handler`](#dht22_8h_1a6119816d8ad1b38b7c732472bba7b0ec)`(`[`dht22`](#structdht22)` * handle)` 

Handles the timer interrupt.

#### Parameters
* `handle` - a pointer to the DHT22 handle

# struct `dht22` 

This structure is the sensor handle.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint8_t `[`rx_buffer`](#structdht22_1a47f38aa1f777ab5c907ec0375eae1344) | Buffer for receiving data (40bits = 5bytes)
`public int8_t `[`bit_pos`](#structdht22_1aa5c499727bc97d11b526ea2dc1eec4fb) | Current position of the bit being received (from -1 to 40)
`public uint16_t `[`last_val`](#structdht22_1a866a73f568a9c1580242de93194402d2) | Timestamp of the last input capture.
`public int16_t `[`temp`](#structdht22_1a54baf6d3cf7819fd576efcdeb5ed6d98) | Temperature reading in tenths of a degree (152 => 15.2 degC)
`public uint16_t `[`hum`](#structdht22_1ae6fb5ed5185ad6cc0bc9525c34b7d53e) | Humidity reading in tenths of a percent (0-1000 => 0-100 RH)
`public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#structdht22_1a2f85ff3689520d5276c9431da0f45378) | Current state of the sensor.
`public bool `[`parity`](#structdht22_1a3f32f989e34d67aa0736e2606a255e55) | Set when the checksum is incorrent.
`public bool `[`timing`](#structdht22_1a20f65ad56869382ed8681b9dd1aa85d6) | Set when the timing of the pulses coming from the sensor is invalid.
`public struct dht22::@0 `[`error_flags`](#structdht22_1a03251bc0907d3f2709d4b8550b9e90e3) | Error flags.
`public `[`dht22_config`](#structdht22__config)` `[`config`](#structdht22_1ab326e0814c94b277efd81f8527ccc3d8) | Configuration of the sensor.

## Members

#### `public uint8_t `[`rx_buffer`](#structdht22_1a47f38aa1f777ab5c907ec0375eae1344) 

Buffer for receiving data (40bits = 5bytes)

#### `public int8_t `[`bit_pos`](#structdht22_1aa5c499727bc97d11b526ea2dc1eec4fb) 

Current position of the bit being received (from -1 to 40)

#### `public uint16_t `[`last_val`](#structdht22_1a866a73f568a9c1580242de93194402d2) 

Timestamp of the last input capture.

Used for calculating duration between input captures and therefore the pulse length.

#### `public int16_t `[`temp`](#structdht22_1a54baf6d3cf7819fd576efcdeb5ed6d98) 

Temperature reading in tenths of a degree (152 => 15.2 degC)

#### `public uint16_t `[`hum`](#structdht22_1ae6fb5ed5185ad6cc0bc9525c34b7d53e) 

Humidity reading in tenths of a percent (0-1000 => 0-100 RH)

#### `public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#structdht22_1a2f85ff3689520d5276c9431da0f45378) 

Current state of the sensor.

#### `public bool `[`parity`](#structdht22_1a3f32f989e34d67aa0736e2606a255e55) 

Set when the checksum is incorrent.

#### `public bool `[`timing`](#structdht22_1a20f65ad56869382ed8681b9dd1aa85d6) 

Set when the timing of the pulses coming from the sensor is invalid.

#### `public struct dht22::@0 `[`error_flags`](#structdht22_1a03251bc0907d3f2709d4b8550b9e90e3) 

Error flags.

#### `public `[`dht22_config`](#structdht22__config)` `[`config`](#structdht22_1ab326e0814c94b277efd81f8527ccc3d8) 

Configuration of the sensor.

# struct `dht22_config` 

This structure is for initializing the sensor handle.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint16_t `[`gpio_pin`](#structdht22__config_1a1468dc79e1c16d2ae8597631191ab190) | GPIO pin connected to the DHT22 sensor.
`public GPIO_TypeDef * `[`gpio_port`](#structdht22__config_1a081bd8cbb6d27fdb0ab0681b66cfd080) | GPIO port associated with the `gpio_pin`
`public TIM_HandleTypeDef * `[`timer`](#structdht22__config_1a30b15aedcc086ca7abb69f7ac012ce64) | Calibrated timer used for time measurements.
`public uint32_t `[`timer_channel`](#structdht22__config_1a9209e1ec26ff459b75d3981ca197ec43) | Input capture channel of the timer to be used for time measurements.

## Members

#### `public uint16_t `[`gpio_pin`](#structdht22__config_1a1468dc79e1c16d2ae8597631191ab190) 

GPIO pin connected to the DHT22 sensor.

#### `public GPIO_TypeDef * `[`gpio_port`](#structdht22__config_1a081bd8cbb6d27fdb0ab0681b66cfd080) 

GPIO port associated with the `gpio_pin`

#### `public TIM_HandleTypeDef * `[`timer`](#structdht22__config_1a30b15aedcc086ca7abb69f7ac012ce64) 

Calibrated timer used for time measurements.

#### `public uint32_t `[`timer_channel`](#structdht22__config_1a9209e1ec26ff459b75d3981ca197ec43) 

Input capture channel of the timer to be used for time measurements.

Generated by [Moxygen](https://sourcey.com/moxygen)