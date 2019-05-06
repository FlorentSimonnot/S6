CC=gcc
NASM=nasm
CFLAGS=-nostartfiles

EXEC=fibo

$(EXEC) : $(EXEC).o utils.o
	$(CC) -o $(EXEC) $(EXEC).o utils.o $(CFLAGS)

$(EXEC).o : $(EXEC).asm
	$(NASM) -f elf64 -o $(EXEC).o $(EXEC).asm

clean :
	rm -o $(EXEC).o
