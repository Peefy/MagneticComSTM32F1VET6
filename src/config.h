
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>
#include <HardwareTimer.h>

#include "modulation.h"
#include "demodulation.h"
#include "dac.h"
#include "chirp.h"
#include "mylib.h"

// pin config
#define PIN_LED  PB0
#define PIN_AD1  PA0
#define PIN_AD2  PA1
#define PIN_DA1  PA4
#define PIN_DA2  PA5

// serial config
#define DATA_LEN 8
#define SERIAL_BAUD 9600

// timer config
#define TIMER_MS 10
#define TIMER_CHANNEL 1
#define MAIN_LOOP_DELAY_MS 20

// adc config
#define ADC_BIT12_FLOAT 4096.0
#define CHIP_VCC 3.3
#define ad2val(x) ((double)( x / ADC_BIT12_FLOAT * CHIP_VCC ))
#define val2ad(x) ((uint16)( x / CHIP_VCC * ADC_BIT12_FLOAT )) 

#endif
