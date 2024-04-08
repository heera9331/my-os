/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#ifndef IDT_H
#define IDT_H

 
#include "../../cdevika/include/types.h"
#include "../../cdevika/include/stddef.h"  

#define KERNEL_CS 0x08

typedef struct {
    uint16 lowOffset;
    uint16 sel;
    uint8 always0;
    uint8 flags;
    uint16 highOffset;
} __attribute__((packed)) idtGateT;

typedef struct {
    uint16 limit;
    uint32 base;
} __attribute__((packed)) idtRegisterT;

#define IDT_ENTRIES 256
extern idtGateT idt[IDT_ENTRIES];
extern idtRegisterT idtReg;

/* Functions implemented in idt.c */
void setIdtGate(int n, uint32 handler);
void setIdt();

#endif //DEVIKAOS_IDT_H
