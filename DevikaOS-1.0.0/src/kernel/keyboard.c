/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/keyboard.h" 

// Define the keyboard map array
char keyboard_map[128] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
    '\b', // Backspace
    '\t', // Tab
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', // Enter
    0, // Left Control
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 
    0, // Left Shift
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 
    0, // Right Shift
    '*', // Keypad *
    0, // Left Alt
    ' ', // Spacebar
    0, // Caps Lock
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // F1 - F10
    0, // Num Lock
    0, // Scroll Lock
    '7', // Keypad 7
    '8', // Keypad 8
    '9', // Keypad 9
    '-', // Keypad -
    '4', // Keypad 4
    '5', // Keypad 5
    '6', // Keypad 6
    '+', // Keypad +
    '1', // Keypad 1
    '2', // Keypad 2
    '3', // Keypad 3
    '0', // Keypad 0
    '.', // Keypad .
    0, 0, 0, // Unused keys
    0, // F11
    0  // F12
};

string str_read()
{
    char *buffstr = (char *)malloc(200);
    uint8 i = 0;

    while (1)
    {
        if (inportb(0x64) & 0x1)
        {
            uint8 scancode = inportb(0x60);

            // Check if Enter key is pressed
            if (scancode == 0x1C)
            {
                buffstr[i] = '\0'; // Null-terminate the string
                break;
            }

            // Check if Backspace key is pressed
            if (scancode == 0x0E)
            {
                if (i > 0)
                {
                    i--;
                    put_char('\b');   // Move cursor back
                    buffstr[i] = '\0'; // Null-terminate the string
                }
                continue;
            }

            // Check if the scancode corresponds to a printable character
            if (scancode < 59 && keyboard_map[scancode] != '\0')
            {
                char character = keyboard_map[scancode];
                put_char(character);
                buffstr[i] = character;
                i++;
            }
        }
    }

    return buffstr;
}