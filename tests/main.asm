
section .data
    ; variables
    var: dd "Hello", 5      ; string to print 
    length : equ $-var      ; length of string

section .text
    ; entry point of linker
    global _start

; start here
_start:
    mov rax, 1          ; sys_write call
    mov rdi, 1          ; stdout
    mov rsi, var;       ; message to write
    mov rdx, length
    syscall

    ; exit program

    mov rax, 60         ; sys_exit
    mov rdi, 0          ; error code 0 (success)
    syscall             ; call kernel
    