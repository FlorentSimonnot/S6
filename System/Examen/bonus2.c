#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

void handlerSignal(int sig, siginfo_t *si, void *context){
    switch(sig){
        case SIGINT : 
            printf("Ctrl+C was pressed. My pid = %d and My father pid = %d\n", getpid(), getppid());
        default : 
            break; 
    }
}

int main(int argc, char *argv[]){
    struct sigaction sig; 
    sig.sa_flags = SA_SIGINFO; 
    sig.sa_sigaction = handlerSignal; 
    
    
    switch(fork()){
        case -1 : 
            perror("fork\n"); 
            exit(EXIT_FAILURE); 
        case 0 : 
            printf("I'm a child\n"); 
            exit(0); 
        default : 
            wait(0); 
            sigaction(SIGINT, &sig, NULL); 
            while(1){}
    }


    return 0;
}