CC=gcc
CFLAGS= -Wall -Wfatal-errors
LDFLAGS=-lreadline
OBJ=main.o ls.o stat.o

ls: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

main.o : main.c ls.h

stat.o : stat.c stat.h 

ls.o : ls.c ls.h

%.o: 	%.c	
	$(CC) -c $< $(CFLAGS)

clean:	
	rm -f *.o

mrproper: clean
	  rm -f ls

