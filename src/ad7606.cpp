
#include "ad7606.h"

#define GPIO_HIGH 1
#define GPIO_LOW  0

#define NOP_DELAY {unsigned char i ;for(i = 0;i < 2;++i){} }

#define OS2(data) {digitalWrite(PE2, data);NOP_DELAY;}

#define OS1(data) {digitalWrite(PE1, data);NOP_DELAY;}

#define OS0(data) {digitalWrite(PE0, data);NOP_DELAY;}

#define RESET(data) {digitalWrite(PE3, data);NOP_DELAY;}

#define RD(data) {digitalWrite(PE4, data);NOP_DELAY;}

#define CS(data) {digitalWrite(PE5, data);NOP_DELAY;}

#define CONVST(data) {digitalWrite(PE6, data);NOP_DELAY;}

#define RANGE_SEL(data) {NOP_DELAY;}

int16_t ADC_Convert[CHANNAL_NUM] = {-1,-1,-1,-1,-1,-1,-1,-1};

Fifo_t ADC_Fifo[AD_NUM] =
{
 {false,0,{0}},
 {false,0,{0}},
 {false,0,{0}}
};

bool IsGotData = false;

void Fifo_AddData(Fifo_t *This , int16_t data)
{
    if(This->IsFull == false)
        This->Buffer[This->Rear] = data;
    if(++This->Rear >= FIFO_SIZE)
    {
        This->Rear = 0;
        This->IsFull = true;
    }
}

void AD7606_TestGpio(void)
{
    OS2(1);
    OS1(1);
    OS0(1);
    RESET(1);
    RD(1);
    CS(1);
    CONVST(1);
    NOP_DELAY;

    OS2(0);
    OS1(0);
    OS0(0);
    RESET(0);
    RD(0);
    CS(0);
    CONVST(0);
    NOP_DELAY;
}

void AD7606_HardWareInit(void)
{
    //DB0...DB15 input
    for (size_t i = 0; i < 15; i++)
    {
        pinMode(PD0 + i, INPUT);
    }
    
    //OS2 output
   
    //OS1 output
    
    //OS0 output

    //RESET output
    
    //RD output
    
    //CS output
    
    //CONVST output
    
    //BUSY input
    for (size_t i = 0; i < 7; i++)
    {
        pinMode(PE0 + i, OUTPUT);
    }

    pinMode(PE7, INPUT);

}

void AD7606_ConfigAll(void)
{
    AD7606_HardWareInit();
    //AD7606_TestGpio();
    AD7606_SetOS(AD7606OS_No);
    AD7606_SetInputRange(AD7606InputRange_5V);
    AD7606_Reset();

    CONVST(GPIO_HIGH);

}

int16_t AD7606_ReadParrelData(void)
{
    uint16_t data16bit = 0;
    NOP_DELAY;
    NOP_DELAY;
    RD(GPIO_LOW); //不忘记将RD拉低

    for (size_t i = 0; i < 15; i++)
    {
        BIT_SETval(data16bit, i, digitalRead(PD0 + i));
    }

    RD(GPIO_HIGH); //读取完毕将RD拉高
    return data16bit;
}

void AD7606_SetOS(AD7606OS_e os)
{
    signed char os8bit = (signed char)os;
    if(os8bit < 0 || os8bit > 6)
        return;
    OS0(BIT_GET(os8bit,0));
    OS1(BIT_GET(os8bit,1));
    OS2(BIT_GET(os8bit,2));
}

void AD7606_Reset(void)
{
    CS(GPIO_HIGH);
    RESET(GPIO_LOW);
    RESET(GPIO_HIGH);
    delay_us(1);
    RESET(GPIO_LOW);
}

bool AD7606_IsBusy()
{
    uint32 bitData = 0;
    bitData = digitalRead(PE7);
    return bitData > GPIO_HIGH;
}

void AD7606_Scan(void)
{
    if(AD7606_IsBusy() == false)
    {
        CS(GPIO_LOW);
        ADC_Convert[0] = AD7606_ReadParrelData();
        CS(GPIO_HIGH);

        CS(GPIO_LOW);
        ADC_Convert[1] = AD7606_ReadParrelData();
        CS(GPIO_HIGH);

        CS(GPIO_LOW);
        ADC_Convert[2] = AD7606_ReadParrelData();
        CS(GPIO_HIGH);

        AD7606_StartConversion();

    }
}

/*
void AD7606_Scan(void)
{
    #ifdef IS_USE_AD7606
    uint8 i = 0;
    if(AD7606_IsBusy() == false)
    {
        CS(GPIO_LOW);
        for(i = 0;i < CHANNAL_NUM ;++i)
        {
            ADC_Convert[i] = AD7606_ReadParrelData();
        }
        CS(GPIO_HIGH);
        AD7606_StartConversion();
    }
    #endif
}*/

void AD7606_StartConversion(void)
{
    CONVST(GPIO_LOW);
    NOP_DELAY;
    CONVST(GPIO_HIGH);
}

//TODO : 硬件已经设为5V,需要接线到IO口
void AD7606_SetInputRange(AD7606InputRange_e inputRange)
{
    /*
    uint16_t bitData = (uint16_t)inputRange;
    RANGE_SEL(bitData);
    */

}

int16_t AD7606_ReadAdc(unsigned char channel)
{
    int16_t sAdc;
    sAdc = ADC_Convert[channel];
    return sAdc;
}


double AD7606_ReadAdcReal(unsigned char channel)
{
    double dAdc;
    int16_t sAdc;
    sAdc = ADC_Convert[channel];
    dAdc = sAdc / 32768.0 * 5.0;
    return dAdc;
}

void AD7606_TestDemo()
{
    AD7606_ConfigAll();
    AD7606_Scan();
    for (size_t i = 0; i < 3; i++)
    {
        Fifo_AddData(&ADC_Fifo[i], ADC_Convert[i]);
    } 
}

