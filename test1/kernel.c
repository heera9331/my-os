// kernel.c

void kernel_main() {
    const char *hello_msg = "Hello from kernel!\n";
    
    // Function to print the message
    print_string(hello_msg);
    
    // Loop indefinitely
    while(1);
}

// Function to print a string
void print_string(const char *str) {
    // Pointer to video memory
    volatile char *video_memory = (volatile char*)0xb8000;
    
    // Loop through the string and print each character
    while (*str != '\0') {
        *video_memory++ = *str++;
        *video_memory++ = 0x07; // White color on black background
    }
}
