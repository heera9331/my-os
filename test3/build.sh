nasm -f elf32 kernel.asm -o ./obj/kernel_asm.o
gcc -m32 -c ./kernel.c -o ./obj/kernel.o -ffreestanding
gcc -m32 -c ./include/keyboard.c -o ./obj/keyboard.o -ffreestanding
gcc -m32 -c ./include/screen.c -o ./obj/screen.o -ffreestanding
gcc -m32 -c ./include/string.c -o ./obj/string.o -ffreestanding
gcc -m32 -c ./include/system.c -o ./obj/system.o -ffreestanding
ld -m elf_i386 -T link.ld -o ./boot/kernel.bin ./obj/kernel_asm.o ./obj/kernel.o ./obj/keyboard.o ./obj/screen.o ./obj/string.o ./obj/system.o
qemu-system-x86_64 -kernel ./boot/kernel.bin
