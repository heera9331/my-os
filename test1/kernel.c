void main()
{
    // Simple print function (you would replace this with a real print function)
    const char *msg = "Hello, world!";
    for (int i = 0; msg[i] != '\0'; ++i)
    {
        // Output each character to the VGA text buffer
        char *video_memory = (char *)0xb8000;
        video_memory[i * 2] = msg[i];
        video_memory[i * 2 + 1] = 0x07; // Text attribute: white on black
    }

    // Infinite loop to keep the kernel running
    while (1)
    {
    }
}
