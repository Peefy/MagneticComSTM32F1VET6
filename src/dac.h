
#ifndef _DAC_H_
#define _DAC_H_

#include <Arduino.h>
#include "libmaple/dac.h"
#include <STM32ADC.h>

void duguAnalogWrite(uint16 val, uint8 channel);

#endif 
