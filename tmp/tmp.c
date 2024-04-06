#include <stdio.h>
#include "tmp.h"

void printChar(char ch) {
    putc(ch, stdout);
}

void printString(char str[]) {
    int i=0;
    while(str[i]) {
        printChar(str[i]);
        i++;
    }
}