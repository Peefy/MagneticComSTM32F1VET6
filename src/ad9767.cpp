
#include "ad9767.h"
#include "mylib.h"

#define DAC9767_IDLE() delay_us(10)

void DAC9767_Init(){
    for (size_t i = 0; i < 16; i++){
        pinMode(DA1_DATA0 + i, OUTPUT);
        digitalWrite(DA1_DATA0 + i, LOW);
    }
    digitalWrite(DA1_DATA13, LOW);
}

void DAC9767_WriteData1(int16_t val){
    int sign = BIT_GET(val, 15);
    digitalWrite(DA1_CLK, HIGH);
    digitalWrite(DA1_WRT, HIGH);
    DAC9767_IDLE();
    digitalWrite(DA1_DATA13, sign);
    for (size_t i = 0; i < 12; i++){
        digitalWrite(DA1_DATA0 + i, BIT_GET(val, i));
    }
    DAC9767_IDLE();
    digitalWrite(DA1_CLK, LOW);
    digitalWrite(DA1_WRT, LOW);
    DAC9767_IDLE();
}

static void DAC9767_WriteData2(int16_t val){
    int sign = BIT_GET(val, 15);
    digitalWrite(DA2_CLK, HIGH);
    digitalWrite(DA2_WRT, HIGH);
    DAC9767_IDLE();
    digitalWrite(DA2_DATA13, sign);
    for (size_t i = 0; i < 12; i++){
        digitalWrite(DA2_DATA0 + i, BIT_GET(val, i));
    }
    DAC9767_IDLE();
    digitalWrite(DA2_CLK, LOW);
    digitalWrite(DA2_WRT, LOW);
    DAC9767_IDLE();
}
