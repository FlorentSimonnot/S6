#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void finit(int i){
    printf("J'arrete\n");

	if(kill(i, SIGKILL) == -1){
		perror("kill\n"); 
		_exit(1);
	}
}



int main(int argc, char* argv[]){
	signal(SIGINT, finit);

	if(argc < 2) {
    	fprintf(stderr,"I need one file name\n");
    	return 1;
    }

	while(1){

		switch(fork()){
			case -1 : perror("fork"); _exit(1); 
			case 0 : break; 
			default : 	if(execlp(argv[1], argv[1], NULL) == -1){
							perror("execlp"); 
							_exit(1);
						}
						if(kill(getpid(), SIGKILL) == -1){
							perror("kill"); 
							_exit(1);
						}
		}
		sleep(1);
	}

	return 0;
}