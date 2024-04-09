
/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc - types of OS
 * */

#ifndef DEVIKAOS_TYPES_H
#define DEVIKAOS_TYPES_H

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef const char* string;

#define low_16(address) (uint16)((address) & 0xFFFF)
#define high_16(address) (uint16)(((address) >> 16) & 0xFFFF)

#endif //DEVIKAOS_TYPES_H

