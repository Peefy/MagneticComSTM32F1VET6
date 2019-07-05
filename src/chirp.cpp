
#include "chirp.h"

#include <math.h>

double generateChirp(double t, double mu){
    static double pi = 3.1415926535897932384626433832795;
    return cos(pi * mu * t * t);
}
