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


; --------------------------------------------------------


section	.data
    msg db 'Hello, world!', 0xa  ;string to be printed
    len equ $ - msg     ;length of the string
    
section .text
    global _start


_start:
    mov edx, len
    mov ecx, msg
    mov	ebx,1       ;file descriptor (stdout)
    mov	edx,4       ;system call number (sys_write)
    int	0x80        ;call kernel
    
    mov	eax,1      ;system call number (sys_exit)
    int	0x80        ;call kernel
 
