CC=gcc
NASM=nasm
CFLAGS=-Wall -no-pie
UTILS=utils.o

EXEC=exo1
#$(EXEC).c
#enlever "-nostartfiles" quand compiler pour du C

$(EXEC) : $(EXEC).o utils.o
	$(CC) $(CFLAGS) $(EXEC).c $(EXEC).o $(UTILS) -o $(EXEC)

$(EXEC).o : $(EXEC).asm
	$(NASM) -f elf64 -o $(EXEC).o $(EXEC).asm

clean :
	rm -f $(EXEC).o

mrproper : clean
	rm -f $(EXEC)