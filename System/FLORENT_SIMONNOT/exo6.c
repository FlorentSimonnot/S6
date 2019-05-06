#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int want_seven(int i){
	printf("%d\n", i);
}

int main(int argc, char* argv[]){
	int count = 0;

	while(1){
		switch(fork()){
			case -1 : perror("fork"); _exit(1); 
			case 0 : break; 
			default : if(want_seven(getpid()) == 1){
							printf("%d\n", getpid());
							pause();
							printf("youpi\n");
						}
						else{
							if(kill(getpid(), SIGKILL) == -1){
								perror("kill\n"); 
								_exit(1);
							}
						}
					  wait(0);
		}
	}
	
	return 0;
}