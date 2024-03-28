#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h" // Include necessary header for types

// Function to read a byte from a port
uint8 inportb(uint16 _port) {
    uint8 rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

// Function to write a byte to a port
void outportb(uint16 _port, uint8 _data) {
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

#endif // End of SYSTEM_H
