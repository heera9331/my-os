/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/shell.h"
#include "include/util.h"

void sum() {
    print("\nEnter first number");
    int n1 = strToInt(strRead());
    print("\nEnter second number");
    int n2 = strToInt(strRead());
    int sum = n1+n2;
}

void help() {
    print("\n[0] help ");
    print("\n[1] addition ");
    print("\n");
}

void launchShell(int n)
{
    string ch = (string)memoryAllocate(200); // util.h
    int counter = 0;
    print("\nDevikaOS shell launched\n");
    do
    {
        print("\n/usr/heera: $ \n");
        help();
        ch = strRead(); // memory_copy(readStr(), ch,100);
        if (strEqual(ch, "exit"))
        {
            print("\nGood Bye!\n");
            return;
        } else if(strEqual(ch, "help")) {
            help();
        } else if(ch == "0") {
            help();
        } else if(strEqual(ch, "1")) {
            sum();
        }
    } while (!strEqual(ch, "exit"));
}