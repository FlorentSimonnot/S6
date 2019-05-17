#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    if (argc <  2){
        perror("Missing arguments. Two arguments required\n"); 
        return 0;
    }

    while(1){
        usleep(atoi(argv[2]) * 1000);
        write(0, argv[1], strlen(argv[1])); 
        write(0, "\n", 1); 
    }


    return 0; 
}