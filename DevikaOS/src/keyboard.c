/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/keyboard.h"
#include "keyboard_scancodes.h"

string strRead()
{
    char *buffstr = (char *)memoryAllocate(200);
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
                    printChar('\b');   // Move cursor back
                    buffstr[i] = '\0'; // Null-terminate the string
                }
                continue;
            }

            // Check if the scancode corresponds to a printable character
            if (scancode < 59 && keyboard_map[scancode] != '\0')
            {
                char character = keyboard_map[scancode];
                printChar(character);
                buffstr[i] = character;
                i++;
            }
        }
    }

    return buffstr;
}