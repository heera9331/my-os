nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o -ffreestanding
ld -m elf_i386 -T link.ld -o iknow/boot/kernel.bin kasm.o kc.o 
qemu-system-x86_64 -kernel iknow/boot/kernel.bin
