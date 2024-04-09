/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/stdio.h"
#include "include/stddef.h"
#include "include/stdlib.h"

/**
 * @desc - screen api
 */

#include "../kernel/include/screen.h"

void put_char(char ch) {
    // Optionally, check if buffer is full and flush it
    string videoMemory = (string)0xb8000; // Mark memory as volatile
    switch (ch)
    {
        case (0x08): // Backspace
            if (cursorX >= 0)
            {
                cursorX--;
                videoMemory[((cursorY * sw + cursorX)) * 2] = ' ';
                videoMemory[((cursorY * sw + cursorX)) * 2 + 1] = 0x00;
            }
            break;
        case ('\r'): // Carriage return
            cursorX = 0;
            break;
        case ('\n'): // Newline
            cursorX = 0;
            cursorY++;
            break;
        default: // Normal character
            videoMemory[((cursorY * sw + cursorX)) * 2] = ch;
            videoMemory[((cursorY * sw + cursorX)) * 2 + 1] = 0x0F;
            cursorX++;
            break;
    }
    // Check if cursor exceeds screen width
    if (cursorX >= sw)
    {
        cursorX = 0;
        cursorY++;
    }
    updateCursor();
    newLineCheck();
}

/**
 * print data with new line
*/
void puts(string str) {
    while(*str) {
        put_char(*str++);
    }
    put_char('\n');
}

/**
 * print data without new line
*/
void print(string str) {
    while(*str) {
        put_char(*str++);
    } 
}