
#ifndef _DEMODULATION_H_
#define _DEMODULATION_H_


typedef struct 
{
    double Ts;
    double Fs;
    double Fc;
    double Rc;
}DemodulationConfigTypedef;

extern DemodulationConfigTypedef DemodulationConfig;

#endif
