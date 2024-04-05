section .text
    global _start

_start:
    ; Set up segments
    xor ax, ax          ; Clear ax register
    mov ds, ax          ; Set data segment to 0
    mov es, ax          ; Set extra segment to 0

    ; Load kernel from disk
    mov ah, 0x02        ; BIOS function to read sectors
    mov al, 1           ; Number of sectors to read
    mov ch, 0x00        ; Cylinder number
    mov dh, 0x00        ; Head number
    mov cl, 0x02        ; Sector number (the kernel starts at sector 2)
    mov bx, 0x8000      ; Load address in memory (where the kernel will be loaded)
    int 0x13            ; Call BIOS interrupt

    ; Jump to kernel
    jmp 0x8000:0000     ; Jump to the entry point of the kernel
