
#include "modulation.h"
#include "config.h"

ModulationConfigTypedef ModulationConfig = 
{ 
    TIMER_MS * 0.001,
    1.0 / (TIMER_MS * 0.001), 
    0.2 / (TIMER_MS * 0.001), 
    0.04 / (TIMER_MS * 0.001) 
};


