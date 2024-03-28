section .data
    msg db "Hello", 0     ; Character to print

    ; alternate way define variable
    ; msg: db "Hello", 0     ; Character to print

section .text
    global _start

_start:
    mov eax, 4      ; System call number for write
    mov ebx, 1      ; File descriptor 1 (stdout)
    mov ecx, msg    ; Pointer to the message to print (ecx->msg)
    mov edx, 5      ; Number of bytes to write (1 character)
    int 0x80        ; Call kernel

    ; Exit the program
    mov eax, 1      ; System call number for exit
    xor ebx, ebx    ; Exit code 0
    int 0x80        ; Call kernel
