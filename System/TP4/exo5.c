#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

void dontTouch(int sig) {
    printf("Aïe \n");
}

int main(void) {
	int status, pid; 

    signal(SIGINT, dontTouch);  /* installation du handler */

    while(1){
    	sleep(10); 
    }
    signal(SIGINT, NULL);
    return 0;
}