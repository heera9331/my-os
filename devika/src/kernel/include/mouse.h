
#include "../../cdevika/include/types.h"
#include "../../cdevika/include/stdio.h"
#include "../../cdevika/include/string.h"
#include "../../kernel/include/system.h"

#ifndef MOUSE_H
#define MOUSE_H

// Mouse packet structure
struct mouse_packet
{
    uint8 buttons; // Button states
    int8 x_delta;  // Change in X position
    int8 y_delta;  // Change in Y position
};

// Mouse interrupt handler
void mouse_handler();

// Initialize the mouse
void mouse_init();

#endif