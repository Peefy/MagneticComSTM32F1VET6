
#include "dac.h"
#include "mylib.h"

void DAC9767_Init(){
    for (size_t i = 0; i < 16; i++){
        pinMode(DA1_DATA0 + i, OUTPUT);
        digitalWrite(DA1_DATA0 + i, LOW);
    }
    digitalWrite(DA1_DATA13, LOW);
}

void DAC9767_WriteData1(int16_t val){
    digitalWrite(DA1_CLK, HIGH);
    digitalWrite(DA1_WRT, HIGH);
    delay(10);
    digitalWrite(DA1_CLK, LOW);
    digitalWrite(DA1_WRT, LOW);
    delay(10);
}
