// Swap bytes of a short

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// given uint16_t value return the value with its bytes swapped
uint16_t short_swap(uint16_t value) {
    uint16_t mask = 0b11111111;
    uint16_t first = value & mask;
    
    mask = mask << 8;
    
    uint16_t second = value & mask;
    
    first = first << 8;
    second = second >> 8;
    
    uint16_t output = first + second;
    return output;
}
