#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define MSGSIZE 32

char *msg1 = "hello #1";
char *msg2 = "hello #2";
char *msg3 = "hello #3";
int main(void){
    char buf[MSGSIZE]; 
    int p[2], j; 
    
    if(pipe(p) == -1){
        perror("pipe\n"); 
        exit(EXIT_FAILURE);
    }

    switch(fork()){
        case -1 : 
            perror("fork\n");
            exit(EXIT_FAILURE); 
        case 0 : 
            close(p[0]); 
            write(p[1], msg1, MSGSIZE);
            write(p[1], msg2, MSGSIZE);
            write(p[1], msg3, MSGSIZE);
            exit(0);
        default :
            close(p[1]); 
            for(j = 0; j < 3; j++){
                read(p[0], buf, MSGSIZE); 
                printf("%s\n", buf);
            }
            wait(0); 
    }
    return 0;
}