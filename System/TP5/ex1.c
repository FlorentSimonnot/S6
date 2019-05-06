#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

void pas_touche(int i){
	printf("I'm not reacting \n"); 
}

void fin(int i){
	printf("fin \n"); 
}

int main(int argc, char *argv[]){
	int i = 0; 
	signal(SIGINT, pas_touche); 
	signal(SIGCHLD, fin);

	switch(fork()){
		case -1 : 
			perror("fork \n"); 
			_exit(1);
		case 0 : 
			for(i = 0; i < 5; i++)
				sleep(2); 
			_exit(1); 
		default : 
			wait(0);
	}
	return 0;
}