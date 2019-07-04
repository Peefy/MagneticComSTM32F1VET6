
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>
#include <HardwareTimer.h>

#include "modulation.h"
#include "demodulation.h"
#include "dac.h"

#define PIN_LED PB0
#define PIN_AD  PA0
#define PIN_DA  PC1

#define DATA_LEN 8
#define SERIAL_BAUD 9600
#define TIMER_MS 10

#define ADC_BIT12_FLOAT 4096.0
#define CHIP_VCC 3.3

#define ad2val(x) ( x / ADC_BIT12_FLOAT * CHIP_VCC ) 
#define val2ad(x) ( x / CHIP_VCC * ADC_BIT12_FLOAT ) 

#endif