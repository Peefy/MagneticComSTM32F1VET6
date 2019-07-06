
#include "dac.h"
#include "mylib.h"

void DAC9767_Init(){
    pinMode(DA1_DATA0, OUTPUT);     
    pinMode(DA1_DATA1, OUTPUT);          
    pinMode(DA1_DATA2, OUTPUT); 
    pinMode(DA1_DATA3, OUTPUT); 
    pinMode(DA1_DATA4, OUTPUT); 
    pinMode(DA1_DATA5, OUTPUT); 
    pinMode(DA1_DATA6, OUTPUT); 
    pinMode(DA1_DATA7, OUTPUT); 
    pinMode(DA1_DATA8, OUTPUT); 
    pinMode(DA1_DATA9, OUTPUT); 
    pinMode(DA1_DATA10, OUTPUT); 
    pinMode(DA1_DATA11, OUTPUT); 
    pinMode(DA1_DATA12, OUTPUT); 
    pinMode(DA1_DATA13, OUTPUT); 
    pinMode(DA1_CLK, OUTPUT); 
    pinMode(DA1_WRT, OUTPUT); 
}

void DAC9767_WriteData1(int16_t val){
    int sign = BIT_GET(val, 15);
    digitalWrite(DA1_CLK, LOW);
    digitalWrite(DA1_WRT, LOW);
    delay_us(1);
    for (size_t i = 0; i < 12; i++){
        digitalWrite(DA1_DATA0 + i, BIT_GET(val, i));
    }
    digitalWrite(DA1_DATA13, sign);
    delay_us(1);
    digitalWrite(DA1_CLK, HIGH);
    digitalWrite(DA1_WRT, HIGH);
}
