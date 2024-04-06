#include "include/screen.h"
#include "include/keyboard.h"
#include "include/string.h"

int kmain()
{
        clearScreen();
        print("Welcome to Devika operating system\nPlease enter a command\n");
        while (1)
        {
                print("\nDevikaOS> ");

                string ch = readStr();
                if (strEql(ch, "cmd"))
                {
                        print("\nYou are allready in cmd\n");
                }
                else if (strEql(ch, "clear"))
                {
                        clearScreen();
                }

                else
                {
                        print("\nBad command!\n");
                }

                print("\n");
        }
}
