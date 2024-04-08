/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */


#ifndef ISR_H
#define ISR_H
#endif //DEVIKAOS_ISR_H

 
#include "../../cdevika/include/types.h"
#include "../../cdevika/include/stdio.h"
#include "idt.h"
#include "screen.h"
#include "util.h"


extern string exceptionMessages[32];
void isrInstall();

/* ISRs reserved for CPU exceptions */
void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();


