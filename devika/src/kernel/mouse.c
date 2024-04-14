#include "include/mouse.h"

// Mouse interrupt handler
void mouse_handler()
{
    // Read the mouse packet data
    struct mouse_packet packet;
    packet.buttons = inportb(0x60); // Read button states
    packet.x_delta = inportb(0x60); // Read X delta
    packet.y_delta = inportb(0x60); // Read Y delta

    // Process the mouse packet (example: print the delta values)
    puts("mouse movement");
    puts("dx");
    puts(int_to_str(packet.x_delta));
    puts("dy");
    puts(int_to_str(packet.y_delta));
}

void mouse_init()
{
    // Enable auxiliary device interrupts (PS/2 mouse)
    (0x64, 0xA8);

    // Enable interrupts from the PS/2 mouse
    outportb(0x64, 0x20);               // Command 0x20 - Get current controller command byte
    uint8 command_byte = inportb(0x60); // Read current controller command byte
    command_byte |= 0x02;               // Set bit 1 to enable interrupt from mouse
    outportb(0x64, 0x60);               // Command 0x60 - Set controller command byte
    outportb(0x60, command_byte);       // Write modified command byte back
}