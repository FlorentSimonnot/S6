./compil -o res.asm < test/global_or_not_global.tpc
nasm -f  elf64 -o res.o res.asm
gcc -nostartfiles -no-pie res.o -o res
./res