/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/shell.h"
#include "include/screen.h"
#include "include/isr.h"
 
int main() {
    clearScreen();
    isrInstall();
    launchShell(4);
    return 0;
}