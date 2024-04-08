/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc - Utilities for DevikaOS
 */

#ifndef _UTIL_H
#define _UTIL_H

#include "types.h"
#include "string.h"

#define MAX_MEMORY_SIZE 1000

void memoryCopy(const char *source, char *dest, int noOfBytes);
void memorySet(uint8 *dest, uint8 val, uint32 len);
string int_to_ascii(int n, char str[]);
int str_to_int(string str);
string int_to_str(int n);
void* memoryAllocate(int noOfBytes);

#endif // DEVIKAOS_UTIL_H
