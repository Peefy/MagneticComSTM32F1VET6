
#include "dac.h"

static uint8 __isDACInit = 0;

static void duguDACInit(){
    if (__isDACInit == 1)
        return;   
    dac_init(DAC, DAC_CH1 | DAC_CH2);
    __isDACInit = 1;
}

void duguAnalogWrite(uint16 val, uint8 channel){
    if (__isDACInit == 0)
        duguDACInit();
    dac_write_channel(DAC, channel, val);
}

