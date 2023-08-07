// Multiply a float by 2048 using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"
#define EXP 0x7F800000
#define FRACT 0x7FFFFF

// float_2048 is given the bits of a float f as a uint32_t
// it uses bit operations and + to calculate f * 2048
// and returns the bits of this value as a uint32_t
//
// if the result is too large to be represented as a float +inf or -inf is returned
//
// if f is +0, -0, +inf or -inf, or Nan it is returned unchanged
//
// float_2048 assumes f is not a denormal number
//
uint32_t float_2048(uint32_t f) {
    uint32_t sign = f >> 31;
    uint32_t exponent = (f & EXP) >> 23; 
    uint32_t fraction = f & FRACT;

    // Checks for infinity
    if ((exponent ^ (EXP >> 23)) == 0) {
        return f;
    }
    if (sign == 1 && (exponent ^ (EXP >> 23)) == 0) {
        return f;
    }
    if (fraction == 0 && exponent == 0) {
        return f;
    }

    // Multiplies by 2048
    sign = sign << 31;
    exponent = exponent + 11;
    if ((exponent ^ (EXP >> 23)) == 0) {
        return f;
    }
    exponent = exponent << 23;
    uint32_t output = (sign | exponent) | fraction;

    // Checks for 0
    if (fraction == 0 && exponent == 0) {
        return f;
    }
    // Checks for NaN
    if ((exponent ^ (EXP >> 23)) == 0 && (fraction) != 0) {
        return f;
    }
    if (sign == 1 && (exponent ^ (EXP >> 23)) == 0) {
        return f;
    }
    
    // Checks for infinity
    if ((sign & 1) == 0 && (exponent ^ (EXP >> 23)) == 0 && (fraction & FRACT) == 0) {
        return f;
    }
    if (output =
    return output;
}
