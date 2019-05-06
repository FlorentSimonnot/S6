#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/mman.h>

void pas_touche(int i){
	printf("I'm not reacting \n"); 
}

int main(int argc, char *argv[]){
	int i = 0; 
	struct sigaction action;

	/*INIT sigaction*/
	sigemptyset(&action.sa_mask); 
	action.sa_handler = &pas_touche;

	if(sigaction(SIGINT, &action, NULL) == -1){
		perror("sigaction \n"); 
		_exit(1);
	}

	while(1){

	}

	return 0;
}