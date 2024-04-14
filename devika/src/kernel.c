/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "kernel/include/shell.h"
#include "kernel/include/isr.h"
#include "kernel/include/screen.h"
#include "kernel/include/mouse.h"
#include "./cdevika/include/stdio.h"

int main()
{
    clearScreen();
    puts("kernel started");
    puts("Interrupt Service Routine");
    isrInstall();

    puts("init mouse");
    mouse_init();
    puts("mouse init done");

    mouse_handler();
    
    // puts("Launching shell");
    // launchShell(4);
    return 0;
}