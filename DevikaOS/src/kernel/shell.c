/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#include "include/shell.h"

void sum();
void help();

void launchShell(int n)
{
    string ch = (string)malloc(200); // util.h
    int counter = 0;
    puts("DevikaOS shell launched");
    do
    {
        print("/usr/heera: $ ");
        // memory_copy(readStr(), ch,100);
        str_cpy(str_read(), ch, 100);
        if (str_equal(ch, "exit"))
        {
            puts("\nGood Bye!\n");
            return;
        }
        else if (str_equal(ch, "help"))
        {
            help();
        }
        else if (str_equal(ch, "clear"))
        {
            clearScreen();
        }
        else if (str_equal(ch, "1"))
        {
            sum();
        } else {
            put_char('\n');
            print("Command not found ");
            print(ch);
            put_char('\n');
        }
    } while (!str_equal(ch, "exit"));
}

void sum()
{
    puts("\nEnter first number");
    int n1 = str_to_int(str_read());
    puts("\nEnter second number");
    int n2 = str_to_int(str_read());
    int sum = n1 + n2;
    puts("\n");
    puts(int_to_str(sum));
}

void help()
{
    puts("\n--------------------------");
    puts("\nHelp prompt");
    puts("\n'help' Help menu");
    puts("\n'exit' Exit from shell");
    puts("\n[1] addition ");
}
