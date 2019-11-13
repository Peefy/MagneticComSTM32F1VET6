
#include "ad9850.h"

#define NOP_DELAY delay_us(5)

#define FQ_UD_A(data)  {digitalWrite(PC0, data);NOP_DELAY;NOP_DELAY;}
#define W_CLK_A(data)  {digitalWrite(PC1, data);NOP_DELAY;NOP_DELAY;}
#define RESET_A(data)  {digitalWrite(PC2, data);NOP_DELAY;NOP_DELAY;}

#define FQ_UD_B(data)  {digitalWrite(PC3, data);NOP_DELAY;NOP_DELAY;}
#define W_CLK_B(data)  {digitalWrite(PC4, data);NOP_DELAY;NOP_DELAY;}
#define RESET_B(data)  {digitalWrite(PC5, data);NOP_DELAY;NOP_DELAY;}

#define FQ_UD_C(data)  {digitalWrite(PC6, data);NOP_DELAY;NOP_DELAY;}
#define W_CLK_C(data)  {digitalWrite(PC7, data);NOP_DELAY;NOP_DELAY;}
#define RESET_C(data)  {digitalWrite(PC8, data);NOP_DELAY;NOP_DELAY;}

#define PARREL_DATA(data) { \
                            digitalWrite(PD0, BIT_GET(data,0)); \
                            digitalWrite(PD1, BIT_GET(data,1)); \
                            digitalWrite(PD2, BIT_GET(data,2)); \
                            digitalWrite(PD3, BIT_GET(data,3)); \
                            digitalWrite(PD4, BIT_GET(data,4)); \
                            digitalWrite(PD5, BIT_GET(data,5)); \
                            digitalWrite(PD6, BIT_GET(data,6)); \
                            digitalWrite(PD7, BIT_GET(data,7)); \
                            }

DDS_t AD9850[AD9850_NUM] =
{
   {0,L1_FREQ},
   {1,L2_FREQ},
   {2,L3_FREQ},
};

void AD9850_CommomHardWareInit(void)
{
    //Data0...Data7
    for (size_t i = 0; i < 8; i++)
    {
        pinMode(PD0 + i, OUTPUT);
    }
    
    //end Data0...Data7

    //FQ-UD_A

    //W_CLK_A

    //RESET_A

    //FQ-UD_B

    //W_CLK_B

    //RESET_B

    //FQ-UD_C

    //W_CLK_C

    //RESET_C
    for (size_t i = 0; i < 9; i++)
    {
        pinMode(PC0 + i, OUTPUT);
    }
    
}

void AD9850_ResetWithParrel(DDS_t* dds)
{
    switch(dds->Number)
    {
        case 0:
            W_CLK_A(0);
             FQ_UD_A(0);
             RESET_A(0);
             RESET_A(1);
             RESET_A(0);
             NOP_DELAY;
            break;
        case 1:
            W_CLK_B(0);
             FQ_UD_B(0);
             RESET_B(0);
             RESET_B(1);
             RESET_B(0);
            break;
        case 2:
            W_CLK_C(0);
             FQ_UD_C(0);
             RESET_C(0);
             RESET_C(1);
             RESET_C(0);
            break;
        default:
            break;
    }
}

void AD9850_WriteWithParrel(DDS_t* dds,unsigned char w0)
{
    unsigned char w;
    uint32_t y;
    double x;
    double frequence = dds->Frequence;

    x = 4294967295 / AD9850_FREQ;//judge to 110M

    frequence = frequence / 1000000;
    frequence = frequence * x;
    y = frequence;

    switch(dds->Number)
    {
        case 0:
            w = w0;
            PARREL_DATA(w);
            W_CLK_A(1);
            W_CLK_A(0);
            w=(y>>24);
            PARREL_DATA(0x00);
            W_CLK_A(1);
            W_CLK_A(0);
            w=(y>>16);
            PARREL_DATA(0x08);      //w2
            W_CLK_A(1);
            W_CLK_A(0);
            w=(y>>8);
            PARREL_DATA(0x00);      //w3
            W_CLK_A(1);
            W_CLK_A(0);
            w=(y>>=0);
            PARREL_DATA(0x00);      //w4
            W_CLK_A(1);
            W_CLK_A(0);
            FQ_UD_A(1);
            FQ_UD_A(0);
            break;
        case 1:
            w = w0;
            PARREL_DATA(w);
            W_CLK_B(1);
            W_CLK_B(0);
            w=(y>>24);
            PARREL_DATA(w);
            W_CLK_B(1);
            W_CLK_B(0);
            w=(y>>16);
            PARREL_DATA(w);      //w2
            W_CLK_B(1);
            W_CLK_B(0);
            w=(y>>8);
            PARREL_DATA(w);      //w3
            W_CLK_B(1);
            W_CLK_B(0);
            w=(y>>=0);
            PARREL_DATA(w);      //w4
            W_CLK_B(1);
            W_CLK_B(0);
            FQ_UD_B(1);
            FQ_UD_B(0);
            break;
        case 2:
            w = w0;
            PARREL_DATA(w);
            W_CLK_C(1);
            W_CLK_C(0);
            w=(y>>24);
            PARREL_DATA(w);
            W_CLK_C(1);
            W_CLK_C(0);
            w=(y>>16);
            PARREL_DATA(w);      //w2
            W_CLK_C(1);
            W_CLK_C(0);
            w=(y>>8);
            PARREL_DATA(w);      //w3
            W_CLK_C(1);
            W_CLK_C(0);
            w=(y>>=0);
            PARREL_DATA(w);      //w4
            W_CLK_C(1);
            W_CLK_C(0);
            FQ_UD_C(1);
            FQ_UD_C(0);
            break;
        default:
            break;
    }

}

void AD9850_AllInit(void)
{
    AD9850_CommomHardWareInit();
    {
        int i = 0;
        for(i = 0;i < AD9850_NUM ;++i)
        {
            AD9850_ResetWithParrel(&AD9850[i]);
            AD9850_WriteWithParrel(&AD9850[i],0x00);
        }
    }
}

void AD9850_TestDemo()
{
    AD9850_AllInit();
}
