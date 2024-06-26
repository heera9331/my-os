/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/screen.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;

// color variable is white
int color = 0x0F;
int whiteColor = 0x0F;
int blackColor = 0x00;

void clearLine(uint8 from, uint8 to)
{
    uint16 i = sw * from * sd;

    string videoMemory = (string)0xb8000;
    for (i; i < (sw * to * sd); i++)
    {
        videoMemory[(i / 2) * 2 + 1] = blackColor;
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
    puts(ch);
    setScreenColorFromColorCode(current_color);
}