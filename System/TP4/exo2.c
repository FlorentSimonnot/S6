#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int i = 0; 
	char *res;

	char var[10] = "RUN_"; 
	sprintf(var, "RUN_%d", i++);

	while( (res = getenv(var)) != NULL){
		switch(fork()){
			case -1 : perror("Error Fork\n");
			case 0 : argv[0] = res;
		}
		printf("%s\n", res);
		sprintf(var, "RUN_%d", i++);
	}



	return 0;
}