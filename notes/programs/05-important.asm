

; a simple boot sector that prints a message to the screen using a BIOS routine

mov ah, 0x0e

mov al, 'H'
int 0x10        ; interrupt
 
mov al, 'e'
int 0x10        ; interrupt
 
mov al, 'l'
int 0x10        ; interrupt
 
mov al, 'l'
int 0x10        ; interrupt
 
mov al, 'o'
int 0x10        ; interrupt
 

jmp $

times 510 - ($ - $$) db 0

dw 0xaa55   ; bios know we are a boot sector

; build and run commands
; nasm main.asm -f bin -o main.bin
; qemu-system-x86_64 main.bin