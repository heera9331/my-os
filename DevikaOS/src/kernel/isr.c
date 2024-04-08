/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/isr.h"

void isrInstall()
{
    setIdtGate(0, (uint32)isr0);
    setIdtGate(1, (uint32)isr1);
    setIdtGate(2, (uint32)isr2);
    setIdtGate(3, (uint32)isr3);
    setIdtGate(4, (uint32)isr4);
    setIdtGate(5, (uint32)isr5);
    setIdtGate(6, (uint32)isr6);
    setIdtGate(7, (uint32)isr7);
    setIdtGate(8, (uint32)isr8);
    setIdtGate(9, (uint32)isr9);
    setIdtGate(10, (uint32)isr10);
    setIdtGate(11, (uint32)isr11);
    setIdtGate(12, (uint32)isr12);
    setIdtGate(13, (uint32)isr13);
    setIdtGate(14, (uint32)isr14);
    setIdtGate(15, (uint32)isr15);
    setIdtGate(16, (uint32)isr16);
    setIdtGate(17, (uint32)isr17);
    setIdtGate(18, (uint32)isr18);
    setIdtGate(19, (uint32)isr19);
    setIdtGate(20, (uint32)isr20);
    setIdtGate(21, (uint32)isr21);
    setIdtGate(22, (uint32)isr22);
    setIdtGate(23, (uint32)isr23);
    setIdtGate(24, (uint32)isr24);
    setIdtGate(25, (uint32)isr25);
    setIdtGate(26, (uint32)isr26);
    setIdtGate(27, (uint32)isr27);
    setIdtGate(28, (uint32)isr28);
    setIdtGate(29, (uint32)isr29);
    setIdtGate(30, (uint32)isr30);
    setIdtGate(31, (uint32)isr31);

    setIdt(); // Load with ASM
}

/*Handlers*/
void isr0()
{
    print(exceptionMessages[0]);
    asm("hlt");
}
void isr1()
{
    print(exceptionMessages[1]);
    asm("hlt");
}
void isr2()
{
    print(exceptionMessages[2]);
    asm("hlt");
}
void isr3()
{
    print(exceptionMessages[3]);
    asm("hlt");
}
void isr4()
{
    print(exceptionMessages[4]);
    asm("hlt");
}
void isr5()
{
    print(exceptionMessages[5]);
    asm("hlt");
}
void isr6()
{
    print(exceptionMessages[6]);
    asm("hlt");
}
void isr7()
{
    print(exceptionMessages[7]);
    asm("hlt");
}
void isr8()
{
    print(exceptionMessages[8]);
    asm("hlt");
}
void isr9()
{
    print(exceptionMessages[9]);
    asm("hlt");
}
void isr10()
{
    print(exceptionMessages[10]);
    asm("hlt");
}
void isr11()
{
    print(exceptionMessages[11]);
    asm("hlt");
}
void isr12()
{
    print(exceptionMessages[12]);
    asm("hlt");
}
void isr13()
{
    print(exceptionMessages[13]);
    asm("hlt");
}
void isr14()
{
    print(exceptionMessages[14]);
    asm("hlt");
}
void isr15()
{
    print(exceptionMessages[15]);
    asm("hlt");
}
void isr16()
{
    print(exceptionMessages[16]);
    asm("hlt");
}
void isr17()
{
    print(exceptionMessages[17]);
    asm("hlt");
}
void isr18()
{
    print(exceptionMessages[18]);
    asm("hlt");
}
void isr19()
{
    print(exceptionMessages[19]);
    asm("hlt");
}
void isr20()
{
    print(exceptionMessages[20]);
    asm("hlt");
}
void isr21()
{
    print(exceptionMessages[21]);
    asm("hlt");
}
void isr22()
{
    print(exceptionMessages[22]);
    asm("hlt");
}
void isr23()
{
    print(exceptionMessages[23]);
    asm("hlt");
}
void isr24()
{
    print(exceptionMessages[24]);
    asm("hlt");
}
void isr25()
{
    print(exceptionMessages[25]);
    asm("hlt");
}
void isr26()
{
    print(exceptionMessages[26]);
    asm("hlt");
}
void isr27()
{
    print(exceptionMessages[27]);
    asm("hlt");
}
void isr28()
{
    print(exceptionMessages[28]);
    asm("hlt");
}
void isr29()
{
    print(exceptionMessages[29]);
    asm("hlt");
}
void isr30()
{
    print(exceptionMessages[30]);
    asm("hlt");
}
void isr31()
{
    print(exceptionMessages[31]);
    asm("hlt");
}

/*End Handlers*/

/* To print the message which defines every exception */
string exceptionMessages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"};
