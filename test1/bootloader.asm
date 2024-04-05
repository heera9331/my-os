BITS 16                   ; Set the assembly to 16-bit mode

global _start             ; Entry point for the bootloader

section .text
_start:
    mov ax, 0             ; Set up the segment registers
    mov ds, ax
    mov es, ax

    mov si, hello_msg     ; Load the address of the hello message
    call print_string     ; Call the print_string function to print it

    jmp $

print_string:
    lodsb                 ; Load the next byte from the string into AL
    cmp al, 0             ; Check if it's the null terminator
    je .done              ; If it is, we're done
    mov ah, 0x0E          ; BIOS tty function to print a character
    int 0x10              ; Call BIOS interrupt to print the character
    jmp print_string      ; Repeat for the next character
.done:
    ret

hello_msg db "Hello, World!", 0  ; Null-terminated string to print

times 510 - ($ - _start) db 0     ; Pad the bootloader to 510 bytes
dw 0xAA55                         ; Boot signature
