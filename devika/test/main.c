

// #include <stdio.h>

#include <stdio.h>
#include <string.h>

void fnx(const char *ptr)
{
    ptr++;
}

int main()
{
    const char *fname = "heera";
    fnx(fname);
    putchar(*fname++);
    putchar(*fname++);
    putchar(*fname++);
    putchar(*fname++);
    putchar(*fname++);
    return 0;
}
