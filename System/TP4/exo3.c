#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int i; 

	for(i = 0; i < 10; i++){
		switch(fork()){
			case -1 : 
				perror("Frok\n"); 
				_exit(1); 
			case 0 : 
				printf("Mon pid est : %d et le PID de mon père est : %d\n", getpid(), getppid());
				_exit(1);
			default : wait(0);
		}
	}


	return 0;
}