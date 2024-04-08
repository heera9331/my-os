//
// Created by Heera Singh Lodhi on 4/7/2024.
//

#ifndef DEVIKAOS_SCREEN_H
#define DEVIKAOS_SCREEN_H

#include "system.h"
#include "string.h"

extern int cursorX , cursorY; 
extern const uint8 sw ,sh ,sd;

void clearLine(uint8 from,uint8 to);
void updateCursor();
void clearScreen();
void scrollUp(uint8 lineNumber);
void newLineCheck();
void printChar(char c);
void print(string str);
void setScreenColorFromColorCode(int color_code);
// void set_screen_color_from_color_code(int color_code);
void setScreenColor(int text_color,int bg_color);
void printColored(string ch,int text_color,int bg_color);

#endif
