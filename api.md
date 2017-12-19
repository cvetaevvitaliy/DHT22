# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`DHT22_StartIT`](#dht22_8c_1a045a01d0be5da934965d41a69ad3cd18)            | 
`define `[`DHT22_StopIT`](#dht22_8c_1ac4102d598485c6a623db004f78622aca)            | 
`define `[`BETWEEN`](#dht22_8c_1a49e2b9281e2eb3056ab463dd03891f74)            | 
`enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)            | Possible return values of the functions
`enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)            | Describes the state of the sensor
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8h_1ae0a960cf3f32e5f54cbd94b84850f3c7)`(`[`DHT22_Config`](#struct_d_h_t22___config)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8h_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Deinitializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8h_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Reads the current temperature and humidity from the sensor 
`public void `[`DHT22_InterruptHandler`](#dht22_8h_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Handles the pin interrupt 
`public void `[`DHT22_SetPinOUT`](#dht22_8c_1a5fee0dc6b5cd41cfa086ab69b35ddb5e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Sets up the pin as an output 
`public void `[`DHT22_SetPinIN`](#dht22_8c_1ad4175670c5d079ac695155e1f2d6122e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Sets up the pin as an input 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_InitiateTransfer`](#dht22_8c_1aa50c742eb8df892ed970ac68c0c09e6f)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initiates a transfer of sensor data 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8c_1a77f7d41fb384d3f9ba418d491871bffb)`(`[`DHT22_Config`](#struct_d_h_t22___config)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8c_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Deinitializes the DHT22 communication 
`public static void `[`write_bit`](#dht22_8c_1aaf170310d73d58a8326b573497990bd8)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle,bool bit)`            | 
`public static float `[`get_float`](#dht22_8c_1ab95eb6a0a585144280871c8c456cf49f)`(uint8_t * dht_data)`            | 
`public static void `[`finish_rx`](#dht22_8c_1a1f08e8456448c71b13b4f5bd80be9585)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | 
`public void `[`DHT22_InterruptHandler`](#dht22_8c_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Handles the pin interrupt 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8c_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Reads the current temperature and humidity from the sensor 
`struct `[`DHT22_Config`](#struct_d_h_t22___config) | This structure is for initializing the sensor handle
`struct `[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def) | This structure is the sensor handle

## Members

#### `define `[`DHT22_StartIT`](#dht22_8c_1a045a01d0be5da934965d41a69ad3cd18) 

#### `define `[`DHT22_StopIT`](#dht22_8c_1ac4102d598485c6a623db004f78622aca) 

#### `define `[`BETWEEN`](#dht22_8c_1a49e2b9281e2eb3056ab463dd03891f74) 

#### `enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
DHT22_OK            | 
DHT22_ERROR            | 
DHT22_TIMING_ERROR            | 
DHT22_CHECKSUM_ERROR            | 

Possible return values of the functions

#### `enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
DHT22_FINISHED            | 
DHT22_BUSY            | 
DHT22_READY            | 

Describes the state of the sensor

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8h_1ae0a960cf3f32e5f54cbd94b84850f3c7)`(`[`DHT22_Config`](#struct_d_h_t22___config)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Initializes the DHT22 communication 
#### Parameters
* `init` - a pointer to the initialization structure 

* `handle` - a pointer to the DHT22 handle you want to initialize 

#### Returns
whether the function was successful or not

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8h_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Deinitializes the DHT22 communication 
#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
whether the function was successful or not

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8h_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Reads the current temperature and humidity from the sensor 
#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
whether the function was successful or not

#### `public void `[`DHT22_InterruptHandler`](#dht22_8h_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Handles the pin interrupt 
#### Parameters
* `handle` - a pointer to the DHT22 handle

#### `public void `[`DHT22_SetPinOUT`](#dht22_8c_1a5fee0dc6b5cd41cfa086ab69b35ddb5e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Sets up the pin as an output 
#### Parameters
* `handle` - a pointer to the DHT22 handle

#### `public void `[`DHT22_SetPinIN`](#dht22_8c_1ad4175670c5d079ac695155e1f2d6122e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Sets up the pin as an input 
#### Parameters
* `handle` - a pointer to the DHT22 handle

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_InitiateTransfer`](#dht22_8c_1aa50c742eb8df892ed970ac68c0c09e6f)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Initiates a transfer of sensor data 
#### Parameters
* `handle` - a pointer to the DHT22 handle

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8c_1a77f7d41fb384d3f9ba418d491871bffb)`(`[`DHT22_Config`](#struct_d_h_t22___config)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Initializes the DHT22 communication 
#### Parameters
* `init` - a pointer to the initialization structure 

* `handle` - a pointer to the DHT22 handle you want to initialize 

#### Returns
whether the function was successful or not

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8c_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Deinitializes the DHT22 communication 
#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
whether the function was successful or not

#### `public static void `[`write_bit`](#dht22_8c_1aaf170310d73d58a8326b573497990bd8)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle,bool bit)` 

#### `public static float `[`get_float`](#dht22_8c_1ab95eb6a0a585144280871c8c456cf49f)`(uint8_t * dht_data)` 

#### `public static void `[`finish_rx`](#dht22_8c_1a1f08e8456448c71b13b4f5bd80be9585)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

#### `public void `[`DHT22_InterruptHandler`](#dht22_8c_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Handles the pin interrupt 
#### Parameters
* `handle` - a pointer to the DHT22 handle

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8c_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Reads the current temperature and humidity from the sensor 
#### Parameters
* `handle` - a pointer to the DHT22 handle 

#### Returns
whether the function was successful or not

# struct `DHT22_Config` 

This structure is for initializing the sensor handle

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint16_t `[`gpio_pin`](#struct_d_h_t22___config_1a1468dc79e1c16d2ae8597631191ab190) | 
`public GPIO_TypeDef * `[`gpio_port`](#struct_d_h_t22___config_1a081bd8cbb6d27fdb0ab0681b66cfd080) | 
`public TIM_HandleTypeDef * `[`timer`](#struct_d_h_t22___config_1a30b15aedcc086ca7abb69f7ac012ce64) | 
`public uint32_t `[`timer_channel`](#struct_d_h_t22___config_1a9209e1ec26ff459b75d3981ca197ec43) | 
`public IRQn_Type `[`timer_irqn`](#struct_d_h_t22___config_1a70cb722279d212fa1c6005742b183b0d) | 

## Members

#### `public uint16_t `[`gpio_pin`](#struct_d_h_t22___config_1a1468dc79e1c16d2ae8597631191ab190) 

#### `public GPIO_TypeDef * `[`gpio_port`](#struct_d_h_t22___config_1a081bd8cbb6d27fdb0ab0681b66cfd080) 

#### `public TIM_HandleTypeDef * `[`timer`](#struct_d_h_t22___config_1a30b15aedcc086ca7abb69f7ac012ce64) 

#### `public uint32_t `[`timer_channel`](#struct_d_h_t22___config_1a9209e1ec26ff459b75d3981ca197ec43) 

#### `public IRQn_Type `[`timer_irqn`](#struct_d_h_t22___config_1a70cb722279d212fa1c6005742b183b0d) 

# struct `DHT22_HandleTypeDef` 

This structure is the sensor handle

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint8_t `[`rx_buffer`](#struct_d_h_t22___handle_type_def_1a47f38aa1f777ab5c907ec0375eae1344) | 
`public int `[`bit_pos`](#struct_d_h_t22___handle_type_def_1a3bdb49ed9986f21df0b78879c749192c) | 
`public uint16_t `[`last_val`](#struct_d_h_t22___handle_type_def_1a866a73f568a9c1580242de93194402d2) | 
`public float `[`temp`](#struct_d_h_t22___handle_type_def_1a24d61a35b72d7299eb6b5f48e71a571b) | 
`public float `[`hum`](#struct_d_h_t22___handle_type_def_1a38adb4de3d9d0391675c323d13503af7) | 
`public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#struct_d_h_t22___handle_type_def_1a2f85ff3689520d5276c9431da0f45378) | 
`public bool `[`parity`](#struct_d_h_t22___handle_type_def_1a3f32f989e34d67aa0736e2606a255e55) | 
`public bool `[`timing`](#struct_d_h_t22___handle_type_def_1a20f65ad56869382ed8681b9dd1aa85d6) | 
`public struct DHT22_HandleTypeDef::@0 `[`error_flags`](#struct_d_h_t22___handle_type_def_1a80d0ebb2df9c1ace6a102564d135670d) | 
`public `[`DHT22_Config`](#struct_d_h_t22___config)` `[`config`](#struct_d_h_t22___handle_type_def_1a0e9b6a7701079d8e775d6e429618f222) | 

## Members

#### `public uint8_t `[`rx_buffer`](#struct_d_h_t22___handle_type_def_1a47f38aa1f777ab5c907ec0375eae1344) 

#### `public int `[`bit_pos`](#struct_d_h_t22___handle_type_def_1a3bdb49ed9986f21df0b78879c749192c) 

#### `public uint16_t `[`last_val`](#struct_d_h_t22___handle_type_def_1a866a73f568a9c1580242de93194402d2) 

#### `public float `[`temp`](#struct_d_h_t22___handle_type_def_1a24d61a35b72d7299eb6b5f48e71a571b) 

#### `public float `[`hum`](#struct_d_h_t22___handle_type_def_1a38adb4de3d9d0391675c323d13503af7) 

#### `public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#struct_d_h_t22___handle_type_def_1a2f85ff3689520d5276c9431da0f45378) 

#### `public bool `[`parity`](#struct_d_h_t22___handle_type_def_1a3f32f989e34d67aa0736e2606a255e55) 

#### `public bool `[`timing`](#struct_d_h_t22___handle_type_def_1a20f65ad56869382ed8681b9dd1aa85d6) 

#### `public struct DHT22_HandleTypeDef::@0 `[`error_flags`](#struct_d_h_t22___handle_type_def_1a80d0ebb2df9c1ace6a102564d135670d) 

#### `public `[`DHT22_Config`](#struct_d_h_t22___config)` `[`config`](#struct_d_h_t22___handle_type_def_1a0e9b6a7701079d8e775d6e429618f222) 

Generated by [Moxygen](https://sourcey.com/moxygen)