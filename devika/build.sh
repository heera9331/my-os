nasm -f elf32 ./src/loader.s -o ./obj/loader.o
gcc -m32 -c ./src/kernel.c -o ./obj/kernel.o -ffreestanding
gcc -m32 -c ./src/kernel/system.c -o ./obj/system.o -ffreestanding
gcc -m32 -c ./src/kernel/isr.c -o ./obj/isr.o -ffreestanding
gcc -m32 -c ./src/kernel/idt.c -o ./obj/idt.o -ffreestanding
gcc -m32 -c ./src/kernel/utilities/util.c -o ./obj/util.o -ffreestanding
gcc -m32 -c ./src/kernel/screen.c -o ./obj/screen.o -ffreestanding
gcc -m32 -c ./src/kernel/keyboard.c -o ./obj/keyboard.o -ffreestanding
gcc -m32 -c ./src/kernel/shell.c -o ./obj/shell.o -ffreestanding

gcc -m32 -c ./src/cdevika/stdio.c -o ./obj/stdio.o -ffreestanding
gcc -m32 -c ./src/cdevika/stdlib.c -o ./obj/stdlib.o -ffreestanding
gcc -m32 -c ./src/cdevika/string.c -o ./obj/string.o -ffreestanding

ld -m elf_i386 -T ./src/link.ld -o ./boot/kernel.bin ./obj/loader.o ./obj/kernel.o ./obj/idt.o ./obj/keyboard.o ./obj/screen.o ./obj/string.o ./obj/system.o ./obj/util.o ./obj/shell.o ./obj/isr.o ./obj/stdio.o ./obj/stdlib.o
