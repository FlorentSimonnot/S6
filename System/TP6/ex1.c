#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]){
	int res[2]; 
	int fd;

	if(argc < 2){
		fprintf(stderr, "No many arguments !\n");
		_exit(1);
	}

	if(pipe(res) == -1){
		fprintf(stderr, "Error pipe : %d\n", errno);
		_exit(1);
	}

	switch(fork()){
		case -1 : perror("fork\n"); _exit(1);
		case 0 :  close(res[0]); dup2(res[1], 1); execlp(argv[1], argv[1], NULL);
		default : close(res[1]); dup2(res[0], 0); execlp(argv[2], argv[2], NULL);
	}


	return 0;
}