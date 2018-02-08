# DHT22 [![Build Status](https://travis-ci.org/petoknm/DHT22.svg?branch=master)](https://travis-ci.org/petoknm/DHT22)
Library for STM32 series microcontrollers for reading DHT22 sensor values

## Supported sensors
`sensor_name (DHT_TYPE to use)`
 - DHT11 (DHT11)
 - DHT22 (DHT22)
 - AM2302 (DHT22)
 - AM2320 (DHT22) (remember to ground pin 3 to choose DHT protocol)

## TODO
 - test stm32f4 example
 - libopencm3 support
 - Testing
 - Use cmake
 - Documentation
 - More examples
 - Photos/Videos
 - v1.0.0
 - a possible debugging improvement would be pin change interrupt on both
rising and falling edges to gain more timing information and deduce the cause
of the failure

## Example
 - [simple example (no error handling)](https://github.com/petoknm/DHT22/blob/master/example/general/example-simple.c)
 - [example with error handling](https://github.com/petoknm/DHT22/blob/master/example/general/example.c)

 The general example is used by all
 the microcontroller specific examples. This demostrates that the library
 is fully portable across all the STM32 families.

Used in projects:
 - [dht22-datalogger](https://github.com/petoknm/dht22-datalogger/tree/master)


## Documentation
You can find [generated documentation here](https://github.com/petoknm/DHT22/blob/master/api.md).

## Hardware setup
DHT22 uses one data pin that needs to be connected to a timer input capture
channel. For each example there is a `README.md` file (e.g.
`example/stm32f1/README.md`) describing the harware
setup used in the particular example. Of course you can choose a different pin
as long as the pin can be used as a timer input capture channel.

## Software setup
You need to include `dht22.h` file to get access to the functionality provided
by this library. You also have to compile the `dht22.c` file, together with your
other source files. You can take a look at the
[examples](#examples--how-you-can-help) to see how
that can be done.

### Timer setup
This library requires a 16bit timer to be configured such that its counting
frequency is **1MHz**. All measurements inside the library are relative to that
and rely on that calibration.

Example:
 - timer_clock = 8MHz
 - timer_prescaler = timer_clock / 1MHz = 8

Now that you know the timer prescaler you need to make sure that the timer
prescaler register has a value 1 less that that.

Example:
 - timer_prescaler = 8 => TIMx_PSC = 7

And don't forget to register `dht22_interrupt_handler` in your timer interrupt handler. Here is an example:
```c
void TIM3_IRQHandler(void) {
    HAL_TIM_IRQHandler(&htim3);
    dht22_interrupt_handler(&dht); // <--- Let the DHT22 library do all the necessary calculations
}
```

## Requirements
For building you need:
 - make
 - arm-none-eabi-gcc

For developing you will also need:
 - clang-format
 - doxygen
 - graphviz
 - moxygen

## Building examples
```shell
# In one of the example folders (e.g. example/stm32f1)
make
```
The resulting binaries can then be found in the `build` folder.

## Examples & How you can help
You can find all the examples in the
[example directory](https://github.com/petoknm/DHT22/blob/master/example).
I would like to support as many STM32 families as possible, but for that I will
need your help. If you have a micro that is not supported or tested yet, please
leave a comment in the issue [#4](https://github.com/petoknm/DHT22/issues/4)
about microcontroller support, so that I can add it to the list of supported
micros.

## Updating documentation
```shell
make docs
```

## Formating source code
```shell
make format
```

## Implementation details
The library uses timer input capture functionality of timers to measure the
timing of the waveform coming from the sensor. It uses a custom protocol and
that is why we have to time it ourselves, without any other hardware support
(that I am aware of).
