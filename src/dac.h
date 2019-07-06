
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

#define DA1_DATAi(i)   DA1_DATA##i 

// DA2相关引脚(J3)
#define da2_wrt                  
#define da2_clk                  
#define da2data0                   
#define da2data1                   
#define da2data2                   
#define da2data3                   
#define da2data4                   
#define da2data5                   
#define da2data6                   
#define da2data7                   
#define da2data8                   
#define da2data9                  
#define da2data10                  
#define da2data11                  
#define da2data12                      
#define da2data13                      

#endif 
