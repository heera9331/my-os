nasm -f elf32 ./src/kernel.asm -o ./obj/kernel_asm.o
gcc -m32 -c ./src/kernel.c -o ./obj/kernel.o -ffreestanding
gcc -m32 -c ./src/system.c -o ./obj/system.o -ffreestanding
gcc -m32 -c ./src/isr.c -o ./obj/isr.o -ffreestanding
gcc -m32 -c ./src/idt.c -o ./obj/idt.o -ffreestanding
gcc -m32 -c ./src/util.c -o ./obj/util.o -ffreestanding
gcc -m32 -c ./src/string.c -o ./obj/string.o -ffreestanding
gcc -m32 -c ./src/screen.c -o ./obj/screen.o -ffreestanding
gcc -m32 -c ./src/keyboard.c -o ./obj/keyboard.o -ffreestanding
gcc -m32 -c ./src/shell.c -o ./obj/shell.o -ffreestanding

ld -m elf_i386 -T ./src/link.ld -o ./boot/kernel.bin ./obj/kernel_asm.o ./obj/kernel.o ./obj/idt.o ./obj/keyboard.o ./obj/screen.o ./obj/string.o ./obj/system.o ./obj/util.o ./obj/shell.o ./obj/isr.o
