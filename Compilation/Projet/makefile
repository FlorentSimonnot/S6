# Makefile TP Flex

# $@ : the current target
# $^ : the current prerequisites
# $< : the first current prerequisite

CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lfl -ly
SRC=compil
EXEC=compil


# all: $(EXEC) clean

$(EXEC): bin/lex.yy.o bin/$(EXEC).tab.o bin/decl.o bin/input-output.o
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

bin/$(EXEC).tab.c: yacc/$(EXEC).y 
	bison --defines=bin/$(EXEC).tab.h yacc/$(EXEC).y -o $@

bin/lex.yy.c: yacc/$(SRC).lex bin/$(EXEC).tab.c
	flex -o $@ yacc/$(EXEC).lex 

bin/%.o: bin/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

bin/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f bin/*
	rm -f report/*
	
mrproper: clean
	rm -f $(EXEC)
