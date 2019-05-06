#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int i, j;

	switch(fork()){
		case -1 : 
			perror("error");
			_exit(1);
		case 0 : 
			for(i = 1; i < 101; i++)
				printf("%d\n", i);
		default : 
			for(j = 500; j > 399; j--)
				printf("%d\n", j);
			wait(0);
			printf("Le compte à rebourd est terminé. Explosion !! BOUM !!! \n");
	}
	return 0;

	return 0;
}