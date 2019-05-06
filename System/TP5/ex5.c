#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd; 

	if ((fd = open("sortie.txt",  O_WRONLY | O_CREAT | 
							 O_TRUNC, S_IRUSR | 
							 S_IWUSR)) == -1){
        perror("sortie.txt\n");
        exit(EXIT_FAILURE);
    }

    dup2(fd, STDOUT_FILENO);


    if (close(fd) == -1){
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    /*Pas obligé de faire un fork si on ne veut pas vérifier le résultat ou reprendre 
	la main sur le programme.
    */
    execlp("ls", "ls", NULL);

    /*
    
    	Commande général ./ex5.c ls
    	execvp(argv[1], argv)

    */

	perror("Ben??\n"); 
	exit(EXIT_FAILURE);
}