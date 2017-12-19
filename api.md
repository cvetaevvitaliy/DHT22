# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`DHT22_StartIT`](#dht22_8c_1a045a01d0be5da934965d41a69ad3cd18)            | 
`define `[`DHT22_StopIT`](#dht22_8c_1ac4102d598485c6a623db004f78622aca)            | 
`enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)            | Possible return values of the functions
`enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)            | Describes the state of the sensor
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8h_1a9c75b3c36f0920fa6ad3ac5ad8ea2b9e)`(`[`DHT22_InitTypeDef`](#struct_d_h_t22___init_type_def)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8h_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Deinitializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8h_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Reads the current temperature and humidity from the sensor 
`public void `[`DHT22_InterruptHandler`](#dht22_8h_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Handles the pin interrupt 
`public void `[`DHT22_SetPinOUT`](#dht22_8c_1a5fee0dc6b5cd41cfa086ab69b35ddb5e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Sets up the pin as an output 
`public void `[`DHT22_SetPinIN`](#dht22_8c_1ad4175670c5d079ac695155e1f2d6122e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Sets up the pin as an input 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_InitiateTransfer`](#dht22_8c_1aa50c742eb8df892ed970ac68c0c09e6f)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initiates a transfer of sensor data 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8c_1a9c75b3c36f0920fa6ad3ac5ad8ea2b9e)`(`[`DHT22_InitTypeDef`](#struct_d_h_t22___init_type_def)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8c_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Deinitializes the DHT22 communication 
`public void `[`DHT22_InterruptHandler`](#dht22_8c_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Handles the pin interrupt 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8c_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Reads the current temperature and humidity from the sensor 
`struct `[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def) | This structure is the sensor handle
`struct `[`DHT22_InitTypeDef`](#struct_d_h_t22___init_type_def) | This structure is for initializing the sensor handle

## Members

#### `define `[`DHT22_StartIT`](#dht22_8c_1a045a01d0be5da934965d41a69ad3cd18) 

#### `define `[`DHT22_StopIT`](#dht22_8c_1ac4102d598485c6a623db004f78622aca) 

#### `enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
DHT22_OK            | 
DHT22_ERROR            | 
DHT22_CRC_ERROR            | 

Possible return values of the functions

#### `enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
DHT22_RECEIVED            | 
DHT22_RECEIVING            | 
DHT22_READY            | 

Describes the state of the sensor

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8h_1a9c75b3c36f0920fa6ad3ac5ad8ea2b9e)`(`[`DHT22_InitTypeDef`](#struct_d_h_t22___init_type_def)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

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

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8c_1a9c75b3c36f0920fa6ad3ac5ad8ea2b9e)`(`[`DHT22_InitTypeDef`](#struct_d_h_t22___init_type_def)` * init,`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

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
`public uint8_t `[`crc_error_flag`](#struct_d_h_t22___handle_type_def_1a0e67f80c1eb86855d0ca1439ecf960c0) | 
`public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#struct_d_h_t22___handle_type_def_1a2f85ff3689520d5276c9431da0f45378) | 
`public TIM_HandleTypeDef `[`timHandle`](#struct_d_h_t22___handle_type_def_1aa809f49efcf3fd6f8ccc4a2a9c7542fa) | 
`public TIM_IC_InitTypeDef `[`timICHandle`](#struct_d_h_t22___handle_type_def_1a887d46837de5ea18a249bc23e027db50) | 
`public uint32_t `[`tim_channel`](#struct_d_h_t22___handle_type_def_1ac695785e5005b76ab3d8749095adc661) | 
`public uint16_t `[`gpio_pin`](#struct_d_h_t22___handle_type_def_1a1468dc79e1c16d2ae8597631191ab190) | 
`public GPIO_TypeDef * `[`gpio_port`](#struct_d_h_t22___handle_type_def_1a081bd8cbb6d27fdb0ab0681b66cfd080) | 
`public IRQn_Type `[`timer_irqn`](#struct_d_h_t22___handle_type_def_1a70cb722279d212fa1c6005742b183b0d) | 

## Members

#### `public uint8_t `[`rx_buffer`](#struct_d_h_t22___handle_type_def_1a47f38aa1f777ab5c907ec0375eae1344) 

#### `public int `[`bit_pos`](#struct_d_h_t22___handle_type_def_1a3bdb49ed9986f21df0b78879c749192c) 

#### `public uint16_t `[`last_val`](#struct_d_h_t22___handle_type_def_1a866a73f568a9c1580242de93194402d2) 

#### `public float `[`temp`](#struct_d_h_t22___handle_type_def_1a24d61a35b72d7299eb6b5f48e71a571b) 

#### `public float `[`hum`](#struct_d_h_t22___handle_type_def_1a38adb4de3d9d0391675c323d13503af7) 

#### `public uint8_t `[`crc_error_flag`](#struct_d_h_t22___handle_type_def_1a0e67f80c1eb86855d0ca1439ecf960c0) 

#### `public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#struct_d_h_t22___handle_type_def_1a2f85ff3689520d5276c9431da0f45378) 

#### `public TIM_HandleTypeDef `[`timHandle`](#struct_d_h_t22___handle_type_def_1aa809f49efcf3fd6f8ccc4a2a9c7542fa) 

#### `public TIM_IC_InitTypeDef `[`timICHandle`](#struct_d_h_t22___handle_type_def_1a887d46837de5ea18a249bc23e027db50) 

#### `public uint32_t `[`tim_channel`](#struct_d_h_t22___handle_type_def_1ac695785e5005b76ab3d8749095adc661) 

#### `public uint16_t `[`gpio_pin`](#struct_d_h_t22___handle_type_def_1a1468dc79e1c16d2ae8597631191ab190) 

#### `public GPIO_TypeDef * `[`gpio_port`](#struct_d_h_t22___handle_type_def_1a081bd8cbb6d27fdb0ab0681b66cfd080) 

#### `public IRQn_Type `[`timer_irqn`](#struct_d_h_t22___handle_type_def_1a70cb722279d212fa1c6005742b183b0d) 

# struct `DHT22_InitTypeDef` 

This structure is for initializing the sensor handle

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint16_t `[`gpio_pin`](#struct_d_h_t22___init_type_def_1a1468dc79e1c16d2ae8597631191ab190) | 
`public GPIO_TypeDef * `[`gpio_port`](#struct_d_h_t22___init_type_def_1a081bd8cbb6d27fdb0ab0681b66cfd080) | 
`public TIM_TypeDef * `[`timer`](#struct_d_h_t22___init_type_def_1a5f2d7e0e880def3262a850626e3df17d) | 
`public uint32_t `[`timer_channel`](#struct_d_h_t22___init_type_def_1a9209e1ec26ff459b75d3981ca197ec43) | 

## Members

#### `public uint16_t `[`gpio_pin`](#struct_d_h_t22___init_type_def_1a1468dc79e1c16d2ae8597631191ab190) 

#### `public GPIO_TypeDef * `[`gpio_port`](#struct_d_h_t22___init_type_def_1a081bd8cbb6d27fdb0ab0681b66cfd080) 

#### `public TIM_TypeDef * `[`timer`](#struct_d_h_t22___init_type_def_1a5f2d7e0e880def3262a850626e3df17d) 

#### `public uint32_t `[`timer_channel`](#struct_d_h_t22___init_type_def_1a9209e1ec26ff459b75d3981ca197ec43) 

Generated by [Moxygen](https://sourcey.com/moxygen)