
#ifndef _MODULATION_H_
#define _MODULATION_H_

typedef struct 
{
    double Ts;
    double Fs;
    double Fc;
    double Rc;
}ModulationConfigTypedef;

extern ModulationConfigTypedef ModulationConfig;

#endif
