/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/screen.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;

int color = 0x0F;
void clearLine(uint8 from, uint8 to)
{
    uint16 i = sw * from * sd;

    string videoMemory = (string)0xb8000;
    for (i; i < (sw * to * sd); i++)
    {
        videoMemory[(i / 2) * 2 + 1] = color;
        videoMemory[(i / 2) * 2] = 0;
    }
}

void updateCursor()
{
    // Position = (y * width) +  x
    unsigned temp = cursorY * sw + cursorX - 1;
    // CRT Control Register: Select Cursor Location
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8); // Send the high byte across the bus
    outportb(0x3D4, 15);        // CRT Control Register: Select Send Low byte
    outportb(0x3D5, temp);      // Send the Low byte of the cursor location
}

void clearScreen()
{
    clearLine(0, sh - 1);
    cursorX = 0;
    cursorY = 0;
    updateCursor();
}

void scrollUp(uint8 lineNumber)
{
    string videoMemory = (string)0xb8000;
    uint16 i = 0;
    clearLine(0, lineNumber - 1); // updated
    for (i; i < sw * (sh - 1) * 2; i++)
    {
        videoMemory[i] = videoMemory[i + sw * 2 * lineNumber];
    }
    clearLine(sh - 1 - lineNumber, sh - 1);

    if ((cursorY - lineNumber) < 0)
    {
        cursorY = 0;
        cursorX = 0;
    }
    else
    {
        cursorY -= lineNumber;
    }
    updateCursor();
}

void newLineCheck()
{
    if (cursorY >= sh - 1)
    {
        scrollUp(1);
    }
}

void printChar(char c)
{
    string videoMemory = (string)0xb8000;
    switch (c)
    {
    case (0x08):
        if (cursorX > 0)
        {
            cursorX--;
            videoMemory[(cursorY * sw + cursorX) * sd] = 0; //(0xF0 & color)
        }
        break;
        /* case (0x09):
                 cursorX = (cursorX + 8) & ~(8 - 1);
                 break;*/
    case ('\r'):
        cursorX = 0;
        break;
    case ('\n'):
        cursorX = 0;
        cursorY++;
        break;
    default:
        videoMemory[((cursorY * sw + cursorX)) * sd] = c;
        videoMemory[((cursorY * sw + cursorX)) * sd + 1] = color;
        cursorX++;
        break;
    }
    if (cursorX >= sw)
    {
        cursorX = 0;
        cursorY++;
    }
    updateCursor();
    newLineCheck();
}

void print(string ch)
{
    uint16 i = 0;
    uint8 len = strLength(ch); // Updated (Now we store string length on a variable to call the function only once)
    for (i; i < len; i++)
    {
        printChar(ch[i]);
    }
    /* while((ch[i] != (char)0) && (i<=length))
             print(ch[i++]);*/
}

void setScreenColor(int text_color, int bg_color)
{
    color = (bg_color << 4) | text_color;
}

void setScreenColorFromColorCode(int color_code)
{
    color = color_code;
}

void printColored(string ch, int text_color, int bg_color)
{
    int current_color = color;
    setScreenColor(text_color, bg_color);
    print(ch);
    setScreenColorFromColorCode(current_color);
}