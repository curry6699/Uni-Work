// count bits in a uint64_t

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

// return how many 1 bits value contains
int bit_count(uint64_t value) {
    int i = 63;
    int output = 0;
    
    while (i >= 0) {
        uint64_t mask = value >> i;
        
        if ((mask & 1) == 1) {
            output++;
        }
    
        i = i - 1;
    }
    
    return output;
}
