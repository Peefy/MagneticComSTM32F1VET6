
#ifndef _AD7055_H_
#define _AD7055_H_

#include <Arduino.h>

void bsp_InitTM7705(void);
void TM7705_CalibSelf(uint8_t _ch);
void TM7705_SytemCalibZero(uint8_t _ch);
void TM7705_SytemCalibFull(uint8_t _ch);
uint16_t TM7705_ReadAdc(uint8_t _ch);

void TM7705_WriteReg(uint8_t _RegID, uint32_t _RegValue);
uint32_t TM7705_ReadReg(uint8_t _RegID);

void Test_ADF7705();

#endif
