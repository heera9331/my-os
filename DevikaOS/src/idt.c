/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/idt.h"

idtGateT idt[IDT_ENTRIES];
idtRegisterT idtReg;

void setIdtGate(int n, uint32 handler) {
    idt[n].lowOffset = low_16(handler);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].highOffset = high_16(handler);
}

void setIdt() {
    idtReg.base = (uint32)&idt;
    idtReg.limit = IDT_ENTRIES * sizeof(idtGateT) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r"(&idtReg));
}
