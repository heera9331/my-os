
dosseg ; dos segment , manages the arrangement of segments in a program (optional)

section .model small ; (optional) model directive

/**
* tiny - code+data <= 64kb
* small - code <= 64kb, data <= 64kb
* medium - code <= any size, data <= 64kb
* compact - code <= 64kb, data <= any size
* large - code <= any size, data <= any size
* huge - code <= any size, data <= any size
* 
*/

section .stack 100h     ; stack segment directive (optional)

; block starting symbol
section .bss
    ; variables

section .data ; code segment directive
    ; constants

section .text
    ; entry point of linker
    global _start

; start here
_start:
    