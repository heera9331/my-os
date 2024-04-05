# nasm -f elf32 kernel.asm -o kasm.o
# gcc -m32 -c kernel.c -o kc.o
# ld -m elf_i386 -T link.ld -o iknow/boot/kernel.bin kasm.o kc.o 
# qemu -kernel iknow/boot/kernel.bin
# grub-mkrescue -o iknow.iso iknow/

# read a

# modified --------------------------------------------------

# Assemble kernel.asm using NASM
nasm -f elf32 kernel.asm -o ./objs/kernel_asm.o

# Compile kernel.c using GCC
gcc -m32 -c kernel.c -o ./objs/kernel_c.o

# Link kernel_asm.o and kernel_c.o using LD
# ld -m elf_i386 -T link.ld -o iknow/boot/kernel.bin kernel_asm.o kernel_c.o
# ld -m elf_i386 -o iknow/boot/kernel.bin kernel_asm.o kernel_c.o

# alternate command -> combine all object files  => make single executable file
ld -m elf_i386 -o ./kernel.bin ./objs/*.o

# Run the kernel.bin using QEMU
qemu-system-x86_64 -kernel ./kernel.bin
# read a


# run qemu using .ios
# qemu-system-x86_64 -cdrom path_to_iso_image

# run qemu using .ios
# qemu-system-x86_64 -hda path_to_disk_image

# current path - /d/