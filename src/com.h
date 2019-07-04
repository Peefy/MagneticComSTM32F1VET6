
#ifndef _COM_H_
#define _COM_H_

#include <stdint.h>

enum class ModulationModeEnum{
    QPSK,
    BPSK,
    ASK,
    FSK
};

typedef struct
{
    uint8_t HeaderOne;
    uint8_t SendBits;
    uint8_t ModulationMode;
}DownPackage;


#endif 
