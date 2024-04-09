/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "../include/util.h" 

void memorySet(uint8 *dest, uint8 val, uint32 len) {
    uint8 *temp = (uint8 *)dest;
    for ( ; len != 0; len--) 
        *temp++ = val;
}
