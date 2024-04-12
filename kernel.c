

#include "include/types.h"

void printf(const char *str)
{
    // Pointer to video memory
    volatile char *video_memory = (volatile char *)0xb8000;

    // Loop through the string and print each character
    while (*str != '\0')
    {
        *video_memory++ = *str++;
        *video_memory++ = 0x07; // White color on black background
    }
}

int kernel_main()
{
    printf("hello from kernel");
    return 0;
}
