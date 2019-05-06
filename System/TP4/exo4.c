#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void){
	int i = 866;

	printf("%d %p\n", i, &i);

	switch(fork()){
		case -1 : 
			perror("Error Fork\n"); 
			_exit(1);
		case 0 : 
			i = 899;
			printf("i = %d adresse pere %p\n", i, &i); 
			_exit(1);
		default : 
			wait(0); 
			printf("i = %d adresse pere %p\n", i, &i);
	}

	return 0;
}

/*On remarque que i n'a pas la meme valeur mais garde la meme adresse.*/