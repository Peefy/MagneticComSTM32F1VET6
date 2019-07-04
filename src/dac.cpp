
#include "dac.h"
#include <libmaple/dac.h>

static uint8 __isDACInit = 0;

static void duguDACInit(){
    if (__isDACInit == 1)
        return;   
    dac_init(DAC, DAC_CH1);
    __isDACInit = 1;
}

void duguAnalogWrite(uint16 val){
    if (__isDACInit == 0)
        duguDACInit();
    dac_write_channel(DAC, DAC_CH1, val);
}

