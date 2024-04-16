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

**Interrupt**

An interrupt is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention.

Interrupt may be software or hardware.

- Hardware interrupt
- Software interrupt
- Exception interrupt

**Interrupt Descriptor Table**

The Interrupt Descriptor Table (IDT) is a data structure used in the x86 architecture to manage interrupts and exceptions. It contains entries, each describing how the processor should handle a particular interrupt or exception.

**Global Descriptor Table**

The Global Descriptor Table (GDT) is a data structure used by the x86 architecture to define memory segments and their access privileges. It's an essential part of memory management in protected mode.

**FAT**

The FAT (File Allocation Table) file system is a popular file system used in various operating systems, including older versions of Windows, as well as in some embedded systems like digital cameras and portable devices. It's known for its simplicity and compatibility across different platforms.

