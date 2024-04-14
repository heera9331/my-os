# OS Development Resources
--

This will help you to develop our own operating system

1. boot loader -> loader.s
2. Kernel
	- printf => hello world
3. Global Descriptor Table
4. Hardware communication port.c
5. Interrupts
6. Keyboard
7. Mouse
8. PCI
9. Graphics mode (VGA)
10. GUI Framework
11. Dynamic Memory Allocation
12. Networking
13. Hard drives
14. System call
15. Ethernet
16. ARP
17. Internet Protocol (IP)
18. ICMP
19. UDP
20. TCP
21. Partition Table
22. File System (FAT32)

**BIOS Functions**

https://redirect.cs.umbc.edu/courses/undergraduate/CMSC211/fall01/burt/tech_help/BIOSandDOS_Interrupts.html

**File Descriptor**

In Unix-like operating systems, including Linux, file descriptors are small, non-negative integers that refer to an open file or input/output (I/O) resource. Here's a brief explanation of common file descriptors:

- 0: Standard input (stdin)
- 1: Standard output (stdout)
- 2: Standard error (stderr)

When you perform input/output operations in assembly language or any programming language in a Unix-like environment, you often specify these file descriptors to indicate where the input or output should be directed.

**Types of kernel**

1. Monolithic Kernel: In a monolithic kernel, all operating system services run in kernel space. This type of kernel provides rich functionality but can be large and complex. Examples include Linux, Unix, and earlier versions of Windows (up to Windows 95/98).

2. Microkernel: Microkernel architecture aims to keep the kernel as small as possible, delegating most tasks to user-space processes called servers. This design promotes modularity and allows for easier maintenance and extensibility. Examples include MINIX, QNX, and some modern operating systems like macOS (with its XNU kernel).

3. Hybrid Kernel: Hybrid kernels attempt to combine the advantages of monolithic and microkernel architectures. They maintain a small, essential kernel in kernel space, while some additional services traditionally found in monolithic kernels may run in user space. This design aims to achieve a balance between performance and modularity. Examples include Microsoft Windows NT/2000/XP/Vista/7/8/10.

**Online Tutorials**

https://www.tutorialspoint.com/assembly_programming/index.htm

**Online Compiler**

https://www.tutorialspoint.com/compile_asm_online.php

**64bit Processor Registers and their usages**

> General-Purpose Registers (GPRs):

- rax: Accumulator register. Used for return values and arithmetic operations.
- rbx: Base register. Used as a pointer to data.
- rcx: Counter register. Used for loop control and shift operations.
- rdx: Data register. Used for I/O pointers and arithmetic operations.
- rsi: Source Index. Used as a pointer to a source in string operations.
- rdi: Destination Index. Used as a pointer to a destination in string operations.
- rsp: Stack Pointer. Points to the top of the stack.
- rbp: Base Pointer. Used to point to the base of the current stack frame.

> Index Registers:

- rsi and rdi: As mentioned earlier, they can also act as index registers.
  64-bit Registers with no Specific Usage:

- r8, r9, r10, r11, r12, r13, r14, r15: These registers are available for general use and are typically used to hold variables or pointers in more complex programs.

**_Instruction Pointer:_**

- rip: Instruction Pointer. Holds the address of the next instruction to be executed.

> Flags Register:

> rflags: Flags register. Holds various status flags indicating the outcome of arithmetic and logical operations.

**System Calls the number**
https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

**Important Commands**

```asm

loop:
    jmp loop


times 510 - ($ - $$) db 0

dw 0xaa55


```

```bash
# make binary

nasm boot_sect.asm -f bin -o boot_sect.bin

# run the created binary on emulator
qemu-system-x86_64 boot_sect.bin
```

**Print Hello**

**Interrupt Descriptor Table**

The Interrupt Descriptor Table (IDT) is a data structure used in the x86 architecture to manage interrupts and exceptions. It contains entries, each describing how the processor should handle a particular interrupt or exception.

**Global Descriptor Table**

The Global Descriptor Table (GDT) is a data structure used by the x86 architecture to define memory segments and their access privileges. It's an essential part of memory management in protected mode.


### Hello World Operating System

Minimal requirement
- loader
- linker
- kernel

```c
// types.h

#ifndef __TYPES_H
#define __TYPES_H

    typedef char                     int8_t;
    typedef unsigned char           uint8_t;
    typedef short                   int16_t;
    typedef unsigned short         uint16_t;
    typedef int                     int32_t;
    typedef unsigned int           uint32_t;
    typedef long long int           int64_t;
    typedef unsigned long long int uint64_t;

#endif
```

```asm
; loader.s

.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM


.section .text
.extern kernelMain 
.global loader


loader:
    mov $kernel_stack, %esp 
    push %eax
    push %ebx
    call kernelMain


_stop:
    cli
    hlt
    jmp _stop


.section .bss
.space 2*1024*1024; # 2 MiB
kernel_stack:

; -----------------another way------------------------
bits    32
section         .text
        align   4
        dd      0x1BADB002
        dd      0x00
        dd      - (0x1BADB002+0x00)

global start
extern main            ; this function is gonna be located in our c code(kernel.c)
start:
        cli             ;clears the interrupts
        call main      ;send processor to continue execution from the kamin funtion in c code
        hlt             ; halt the cpu(pause it from executing from this address

```

```ld
// linker.ld

ENTRY(loader)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

SECTIONS
{
  . = 0x0100000;

  .text :
  {
    *(.multiboot)
    *(.text*)
    *(.rodata)
  }

  .data  :
  {
    start_ctors = .;
    KEEP(*( .init_array ));
    KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.* )));
    end_ctors = .;

    *(.data)
  }

  .bss  :
  {
    *(.bss)
  }

  /DISCARD/ : { *(.fini_array*) *(.comment) }
}
```

**Another linker**

```
OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
 {
   . = 0x100000;
   .text : { *(.text) }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
 }
```

```c
// kernel.c
void printf(char *str)
{
    static uint16_t *VideoMemory = (uint16_t *)0xb8000;

    static uint8_t x = 0, y = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch (str[i])
        {
        case '\n':
            x = 0;
            y++;
            break;
        default:
            VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | str[i];
            x++;
            break;
        }

        if (x >= 80)
        {
            x = 0;
            y++;
        }

        if (y >= 25)
        {
            for (y = 0; y < 25; y++)
                for (x = 0; x < 80; x++)
                    VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void main() {
    printf("hello from kernel");
}
```

makefile => if not work than write file name is MakeFile
```
# sudo apt-get install g++ binutils libc6-dev-i386

GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o kernel.o

run: mykernel.iso
	(killall VirtualBox && sleep 1) || true
	VirtualBox --startvm 'My Operating System' &

%.o: %.cpp
	gcc $(GCCPARAMS) -c -o $@ $<

%.o: %.s
	as $(ASPARAMS) -o $@ $<

mykernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin

mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp mykernel.bin iso/boot/mykernel.bin
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/mykernel.bin'    >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=mykernel.iso iso
	rm -rf iso

run: mykernel.iso
	(killall VirtualBox && sleep 1) || true
	VirtualBox --startvm 'My Operating System' &
```


**Commands**

if makefile not work than we directly run commands to run os's kernel

```sh
# compilation
nasm -f elf32 loader.s -o loader.o
gcc -m32 -c kernel.c -o kernel.o -ffreestanding

# linking
ld -m elf_i386 -T linker.ld -o kernel.bin loader.o kernel.o

# run
qemu-system-x86_64 -kernel kernel.bin
```

