#include "include/kb.h"
#include "include/isr.h"
#include "include/screen.h"

int main() {
     isr_install();
     clearScreen();
    print("Hi and Welcome to DevikaOS operating system\n");
    print("DevikaOS> ");
    while(1)
    {
        string ch = readStr();
        print("\n");
        print(ch);
    }
    return 0;
}


