
#include "demodulation.h"
#include "config.h"

DemodulationConfigTypedef DemodulationConfig = 
{ 
    TIMER_MS * 0.001,
    1.0 / (TIMER_MS * 0.001), 
    0.2 / (TIMER_MS * 0.001), 
    0.04 / (TIMER_MS * 0.001) 
};

double demodulateBPSK(double t, double val){
    return 0.0;
}

