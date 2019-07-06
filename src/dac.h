
#ifndef _DAC_H_
#define _DAC_H_

#include <Arduino.h>

#define CHIP_NAME "DAC9767"

// DA1相关引脚(J3)                   
#define DA1_DATA0     PD0              
#define DA1_DATA1     PD1  
#define DA1_DATA2     PD2  
#define DA1_DATA3     PD3  
#define DA1_DATA4     PD4  
#define DA1_DATA5     PD5  
#define DA1_DATA6     PD6  
#define DA1_DATA7     PD7  
#define DA1_DATA8     PD8  
#define DA1_DATA9     PD9  
#define DA1_DATA10    PD10  
#define DA1_DATA11    PD11  
#define DA1_DATA12    PD12  
#define DA1_DATA13    PD13  
#define DA1_CLK       PD14
#define DA1_WRT       PD15                


// DA2相关引脚(J3)                   
#define DA1_DATA0     PE0              
#define DA1_DATA1     PE1  
#define DA1_DATA2     PE2  
#define DA1_DATA3     PE3  
#define DA1_DATA4     PE4  
#define DA1_DATA5     PE5  
#define DA1_DATA6     PE6  
#define DA1_DATA7     PE7  
#define DA1_DATA8     PE8  
#define DA1_DATA9     PE9  
#define DA1_DATA10    PE10  
#define DA1_DATA11    PE11  
#define DA1_DATA12    PE12  
#define DA1_DATA13    PE13  
#define DA1_CLK       PE14
#define DA1_WRT       PE15                       

void DAC9767_Init();
void DAC9767_WriteData1(int16_t val);

#endif 
