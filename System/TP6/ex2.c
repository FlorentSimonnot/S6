#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	int res[2]; 
	int i;
	char c;

	if(pipe(res) == -1){
		fprintf(stderr, "Error pipe : %d\n", errno);
		_exit(1);
	}

	switch(fork()){
		case -1 : 	
			perror("fork\n"); 
			_exit(1);
		case 0 :  	 
			for(i = 0; i < 10; i++){
				read(res[0], &c, 1);
				c = toupper(c);
				write(1, &c, 1);
			}		
			_exit(0);
		default :
			close(res[0]); 
			while(read(0, &c, 1)){
				write(res[1], &c, 1);
			}
			_exit(0);
	}	



	return 0;
}