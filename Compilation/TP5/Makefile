CC=gcc
NASM=nasm
CFLAGS=-no-pie

EXEC=square

$(EXEC) : $(EXEC).o exo2.o
	$(CC) -o $(EXEC) $^ $(CFLAGS)

%.o : %.asm
	$(NASM) -f elf64 -o $@ $<

clean :
	rm -o $(EXEC).o
