CC=gcc
NASM=nasm
CFLAGS=-Wall -no-pie
UTILS=utils.o

EXEC=ex1
#$(EXEC).c
#enlever "-nostartfiles" quand compiler pour du C

$(EXEC) : $(EXEC).o 
	$(CC) $(CFLAGS) $(EXEC).o utils.o -o $(EXEC)

$(EXEC).o : $(EXEC).asm
	$(NASM) -f elf64 -o $(EXEC).o $(EXEC).asm

clean :
	rm -f $(EXEC).o

mrproper : clean
	rm -f $(EXEC)