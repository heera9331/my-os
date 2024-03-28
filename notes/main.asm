section .data
    prompt db "Enter a character: ", 0
    newline db 0x0a, 0
    len equ $ - prompt

section .bss
    input resb 1

section .text
    global _start

_start:
    ; Print prompt
    mov rax, 1              ; System call for write
    mov rdi, 1              ; File descriptor 1 is stdout
    mov rsi, prompt         ; Pointer to string to write
    mov rdx, len             ; Length of string
    syscall

    ; Read a character from user
    mov rax, 0              ; System call for read
    mov rdi, 0              ; File descriptor 0 is stdin
    mov rsi, input          ; Buffer to store input
    mov rdx, 1              ; Number of bytes to read
    syscall

    ; Print newline
    mov rax, 1              ; System call for write
    mov rdi, 1              ; File descriptor 1 is stdout
    mov rsi, newline        ; Pointer to newline character
    mov rdx, 2              ; Length of string
    syscall

    ; Print the character back
    mov rax, 1              ; System call for write
    mov rdi, 1              ; File descriptor 1 is stdout
    mov rsi, input          ; Pointer to character to write
    mov rdx, 1              ; Length of string (1 byte for a character)
    syscall

    ; Exit the program
    mov eax, 60             ; System call for exit
    xor edi, edi            ; Exit code 0
    syscall
