# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`DHT22_StartIT`](#dht22_8c_1a045a01d0be5da934965d41a69ad3cd18)            | 
`define `[`DHT22_StopIT`](#dht22_8c_1ac4102d598485c6a623db004f78622aca)            | 
`enum `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)            | Possible return values of the functions
`enum `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)            | Describes the state of the sensor
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8h_1a29bc88c0b83860a982455f6e81174334)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8h_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Deinitializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8h_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Reads the current temperature and humidity from the sensor 
`public void `[`DHT22_InterruptHandler`](#dht22_8h_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Handles the pin interrupt 
`public void `[`DHT22_SetPinOUT`](#dht22_8c_1a5fee0dc6b5cd41cfa086ab69b35ddb5e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Sets up the pin as an output 
`public void `[`DHT22_SetPinIN`](#dht22_8c_1ad4175670c5d079ac695155e1f2d6122e)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Sets up the pin as an input 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_InitiateTransfer`](#dht22_8c_1aa50c742eb8df892ed970ac68c0c09e6f)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initiates a transfer of sensor data 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8c_1a29bc88c0b83860a982455f6e81174334)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Initializes the DHT22 communication 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_DeInit`](#dht22_8c_1ada5d62c92505f78d77c3fa785ba8982a)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Deinitializes the DHT22 communication 
`public void `[`DHT22_InterruptHandler`](#dht22_8c_1a561512a49c1b6a49d3124eca8d26928b)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Handles the pin interrupt 
`public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_ReadData`](#dht22_8c_1ad3d02d9f971cc36c866b8759ce3c9bfa)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)`            | Reads the current temperature and humidity from the sensor 
`struct `[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def) | This structure hold all the variables necessary for communication with the sensor

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

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8h_1a29bc88c0b83860a982455f6e81174334)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Initializes the DHT22 communication 
#### Parameters
* `handle` - a pointer to the DHT22 handle 

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

#### `public `[`DHT22_RESULT`](#dht22_8h_1a1d16fe97ca08e0d2c9b928a36472c633)` `[`DHT22_Init`](#dht22_8c_1a29bc88c0b83860a982455f6e81174334)`(`[`DHT22_HandleTypeDef`](#struct_d_h_t22___handle_type_def)` * handle)` 

Initializes the DHT22 communication 
#### Parameters
* `handle` - a pointer to the DHT22 handle 

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

This structure hold all the variables necessary for communication with the sensor

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint8_t `[`bitsRX`](#struct_d_h_t22___handle_type_def_1a246dd2ae7a9fa409d7ec99782b83edd0) | 
`public float `[`temp`](#struct_d_h_t22___handle_type_def_1a24d61a35b72d7299eb6b5f48e71a571b) | 
`public float `[`hum`](#struct_d_h_t22___handle_type_def_1a38adb4de3d9d0391675c323d13503af7) | 
`public uint8_t `[`crcErrorFlag`](#struct_d_h_t22___handle_type_def_1a510dc13f38c68bdb76d40b12b3857160) | 
`public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#struct_d_h_t22___handle_type_def_1a2f85ff3689520d5276c9431da0f45378) | 
`public TIM_HandleTypeDef `[`timHandle`](#struct_d_h_t22___handle_type_def_1aa809f49efcf3fd6f8ccc4a2a9c7542fa) | 
`public TIM_IC_InitTypeDef `[`timICHandle`](#struct_d_h_t22___handle_type_def_1a887d46837de5ea18a249bc23e027db50) | 
`public uint32_t `[`timChannel`](#struct_d_h_t22___handle_type_def_1af46d768d0122a9752b29eaf00d981041) | 
`public uint16_t `[`gpioPin`](#struct_d_h_t22___handle_type_def_1a699db2851efab53386249e133df1021a) | 
`public GPIO_TypeDef * `[`gpioPort`](#struct_d_h_t22___handle_type_def_1aa021f52edc668e716cd8de5d4800450d) | 
`public int `[`bitPos`](#struct_d_h_t22___handle_type_def_1ad92fba41f1ad27de1c712b4add263881) | 
`public IRQn_Type `[`timerIRQn`](#struct_d_h_t22___handle_type_def_1a0c8ca742cd2a7166a8643177bf8bc576) | 
`public uint32_t `[`gpioAlternateFunction`](#struct_d_h_t22___handle_type_def_1a025afdfcfc3449de5e0c629588497bee) | 
`public uint16_t `[`lastVal`](#struct_d_h_t22___handle_type_def_1aa8f2f24cd5c9a580c2719b7b0761a089) | 
`public void(* `[`errorCallback`](#struct_d_h_t22___handle_type_def_1a8a32ad548858efd6b020e49c5da969b4) | 

## Members

#### `public uint8_t `[`bitsRX`](#struct_d_h_t22___handle_type_def_1a246dd2ae7a9fa409d7ec99782b83edd0) 

#### `public float `[`temp`](#struct_d_h_t22___handle_type_def_1a24d61a35b72d7299eb6b5f48e71a571b) 

#### `public float `[`hum`](#struct_d_h_t22___handle_type_def_1a38adb4de3d9d0391675c323d13503af7) 

#### `public uint8_t `[`crcErrorFlag`](#struct_d_h_t22___handle_type_def_1a510dc13f38c68bdb76d40b12b3857160) 

#### `public `[`DHT22_STATE`](#dht22_8h_1a73cd960d2d2ae7988ddb46f1c9e49e79)` `[`state`](#struct_d_h_t22___handle_type_def_1a2f85ff3689520d5276c9431da0f45378) 

#### `public TIM_HandleTypeDef `[`timHandle`](#struct_d_h_t22___handle_type_def_1aa809f49efcf3fd6f8ccc4a2a9c7542fa) 

#### `public TIM_IC_InitTypeDef `[`timICHandle`](#struct_d_h_t22___handle_type_def_1a887d46837de5ea18a249bc23e027db50) 

#### `public uint32_t `[`timChannel`](#struct_d_h_t22___handle_type_def_1af46d768d0122a9752b29eaf00d981041) 

#### `public uint16_t `[`gpioPin`](#struct_d_h_t22___handle_type_def_1a699db2851efab53386249e133df1021a) 

#### `public GPIO_TypeDef * `[`gpioPort`](#struct_d_h_t22___handle_type_def_1aa021f52edc668e716cd8de5d4800450d) 

#### `public int `[`bitPos`](#struct_d_h_t22___handle_type_def_1ad92fba41f1ad27de1c712b4add263881) 

#### `public IRQn_Type `[`timerIRQn`](#struct_d_h_t22___handle_type_def_1a0c8ca742cd2a7166a8643177bf8bc576) 

#### `public uint32_t `[`gpioAlternateFunction`](#struct_d_h_t22___handle_type_def_1a025afdfcfc3449de5e0c629588497bee) 

#### `public uint16_t `[`lastVal`](#struct_d_h_t22___handle_type_def_1aa8f2f24cd5c9a580c2719b7b0761a089) 

#### `public void(* `[`errorCallback`](#struct_d_h_t22___handle_type_def_1a8a32ad548858efd6b020e49c5da969b4) 

Generated by [Moxygen](https://sourcey.com/moxygen)