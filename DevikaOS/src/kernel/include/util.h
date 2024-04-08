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
string intToAscii(int n, char str[]);
int strToInt(string str);
string intToStr(int n);
void* memoryAllocate(int noOfBytes);

#endif // DEVIKAOS_UTIL_H
