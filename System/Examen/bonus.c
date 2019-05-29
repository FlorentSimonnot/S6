#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[]){

    if(argc < 1){
        perror("Missing arguments\n"); 
        exit(EXIT_FAILURE);
    }

    switch(fork()){
        case -1: 
            perror("fork\n"); 
            exit(0); 
        case 0 : 
            if(execlp("/bin/ls", argv[1], argv[2], NULL) == -1){
                perror("execlp\n"); 
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        default :
            wait(0); 
            printf("Mon fils a finis d'executé %s\n", argv[1]); 

    }

    return 0;
}