// Compare 2 floats using bit operations only

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

#define EXP 0x7F800000
#define FRACT 0x7FFFFF
// float_less is given the bits of 2 floats bits1, bits2 as a uint32_t
// and returns 1 if bits1 < bits2, 0 otherwise
// 0 is return if bits1 or bits2 is Nan
// only bit operations and integer comparisons are used
uint32_t float_less(uint32_t bits1, uint32_t bits2) {
    uint32_t sign_1 = bits1 >> 31;
    uint32_t exponent_1 = (bits1 & EXP) >> 23; 
    uint32_t fraction_1 = bits1 & FRACT;

    uint32_t sign_2 = bits2 >> 31;
    uint32_t exponent_2 = (bits2 & EXP) >> 23; 
    uint32_t fraction_2 = bits2 & FRACT;

    // Check for NaN
    if ((exponent_1 ^ (EXP >> 23)) == 0 && (fraction_1) != 0) {
            return 0;
        } 
    if ((exponent_2 ^ (EXP >> 23)) == 0 && (fraction_2) != 0) {
            return 0;
        } 

    // Checking if either or is neg
    if (sign_1 == 1 && sign_2 == 0) {
            return 1;
    }
    if (sign_2 == 1 && sign_1 == 0) {
            return 0;
    }

    // Checking if either or is +inf
    if ((sign_1 & 1) == 0 && (exponent_1 ^ (EXP >> 23)) == 0 && (fraction_1 & FRACT) == 0) {
            return 0;
        } 
    if ((sign_2 & 1) == 0 && (exponent_2 ^ (EXP >> 23)) == 0 && (fraction_2 & FRACT) == 0) {
            return 1;
        } 
    // Checking if either or is -inf
    if (sign_1 == 1 && (exponent_1 ^ (EXP >> 23)) == 0 && sign_2 == 1 && (exponent_2 ^ (EXP >> 23)) == 0) {
            return 0;
    }
    if (sign_1 == 1 && (exponent_1 ^ (EXP >> 23)) == 0) {
            return 1;
    }
    if (sign_2 == 1 && (exponent_2 ^ (EXP >> 23)) == 0) {
            return 0;
    }

    // Checking if either is 0 
    if (exponent_1 == 0 && fraction_1 == 0 && exponent_2 == 0 && fraction_2 == 0) {
        return 0;
    }
    if (exponent_1 == 0 && fraction_1 == 0) {
        return 1;
    }
    if (exponent_2 == 0 && fraction_2 == 0) {
        return 0;
    }

    // Normal < and > +ve
    if (sign_1 == 0 && sign_2 == 0 && exponent_1 < exponent_2 && fraction_1 < fraction_2) {
        return 1;
    }
    if (sign_1 == 0 && sign_2 == 0 && exponent_1 > exponent_2 && fraction_1 > fraction_2) {
        return 0;
    }
    if (sign_1 == 0 && sign_2 == 0 && exponent_1 < exponent_2) {
        return 1;
    } 
    if (sign_1 == 0 && sign_2 == 0 && fraction_1 < fraction_2 && exponent_2 == exponent_1) {
        return 1;
    } 
    if (sign_1 == 1 && sign_2 == 1 && fraction_1 > fraction_2) {
        return 1;
    }


    return 0;
}
   




