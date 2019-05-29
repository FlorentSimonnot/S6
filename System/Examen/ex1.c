#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main(void){

    switch(fork()){
        case -1 : 
            perror("fork error\n");
            _exit(1); 
        case 0 : 
            sleep(5); 
            printf("Mon pid est : %d\n", getpid());
            exit(EXIT_SUCCESS); 
        default : 
            wait(NULL);
            printf("Mon fils vient de terminer\n");
    }
}