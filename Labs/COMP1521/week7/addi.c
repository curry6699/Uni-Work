// generate the opcode for an addi instruction

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "addi.h"

// return the MIPS opcode for addi $t,$s, i
uint32_t addi(int t, int s, int i) {
        uint32_t code = 0x20000000;
        
        s <<= 21;
        t <<= 16;
        i = (uint16_t)i;

        return code + s + t + i;
}
