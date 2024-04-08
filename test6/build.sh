nasm -f elf32 kernel.asm -o kernel_asm.o
gcc -m32 -c kernel.c -o kernel.o -ffreestanding
gcc -m32 -c include/system.c -o obj/system.o -ffreestanding
gcc -m32 -c include/idt.c -o obj/idt.o -ffreestanding
gcc -m32 -c include/util.c -o obj/util.o -ffreestanding
gcc -m32 -c include/string.c -o obj/string.o -ffreestanding
gcc -m32 -c include/screen.c -o obj/screen.o -ffreestanding
gcc -m32 -c include/kb.c -o obj/kb.o -ffreestanding
gcc -m32 -c include/isr.c -o obj/isr.o -ffreestanding
ld -m elf_i386 -T link.ld -o ./boot/kernel.bin kernel_asm.o kernel.o obj/system.o obj/string.o obj/screen.o obj/kb.o obj/idt.o obj/util.o obj/isr.o
qemu-system-x86_64 -kernel ./boot/kernel.bin


