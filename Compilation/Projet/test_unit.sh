./compil -o res.asm < test/array.tpc
nasm -f  elf64 -o res.o res.asm
gcc -nostartfiles -no-pie res.o -o res
./res