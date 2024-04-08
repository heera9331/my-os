#ifndef SCREEN_H
#define SCREEN_H

#include "system.h"
#include "string.h"

int cursorX = 0, cursorY = 0;
uint8 sw = 80,sh = 25,sd = 2;

void clearLine(uint8 from,uint8 to);
void updateCursor();
void clearScreen();
void scrollUp(uint8 lineNumber);
void newLineCheck();
void printch(char c);
void print(string ch);

#endif
