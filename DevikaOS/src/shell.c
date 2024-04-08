/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/shell.h"
 
void launch_shell(int n)
{
    string ch = (string)memoryAllocate(200); // util.h
    int counter = 0;
    do
    {
        print("\nDevikaOS shell launched\n");
        print("/usr/heera: $ ");
        ch = strRead(); // memory_copy(readStr(), ch,100);
        if (strEqual(ch, "exit"))
        {
            print("\nGood Bye!\n");
            return;
        }
    } while (!strEqual(ch, "exit"));
}