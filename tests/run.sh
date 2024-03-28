nasm -f elf64 main.asm -o main.o
ld main.o -o main
./main

echo ""
echo "Removing created object and binary files"

rm *.o
rm main