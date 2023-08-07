// Extract the 3 parts of a float using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"
#define EXP 0x7F800000
#define fract 0x7FFFFF
// separate out the 3 components of a float
float_components_t float_bits(uint32_t f) {
    float_components_t components;
    components.sign = f >> 31;   
    components.exponent = (f & EXP) >> 23; 
    components.fraction = f & fract;
    return components;
}

 {
    
    f = f << n_rotations; 
    return n;
 
 
}



// given the 3 components of a float
// return 1 if it is NaN, 0 otherwise
int is_nan(float_components_t f) {
    if ((f.exponent ^ (EXP >> 23)) == 0 && (f.fraction) != 0) {
        return 1;
    }
    return 0;
}

// given the 3 components of a float
// return 1 if it is inf, 0 otherwise
int is_positive_infinity(float_components_t f) {
    if ((f.sign & 1) == 0 && (f.exponent ^ (EXP >> 23)) == 0 && (f.fraction & fract) == 0) {
        return 1;
    }
    return 0;
}

// given the 3 components of a float
// return 1 if it is -inf, 0 otherwise
int is_negative_infinity(float_components_t f) {
    if (f.sign == 1 && (f.exponent ^ (EXP >> 23)) == 0) {
        return 1;
    }
    return 0;
}

// given the 3 components of a float
// return 1 if it is 0 or -0, 0 otherwise
int is_zero(float_components_t f) {
    if (f.fraction == 0 && f.exponent == 0) {
        return 1;
    }
    return 0;
}
