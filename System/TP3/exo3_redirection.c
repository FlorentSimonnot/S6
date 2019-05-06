#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/**
le dup sans le pipe sert à faire les redirections :
pour faire un ls > toto
*/

int main(int argc, char ** argv)
{
    int fd; // decripteur de fichier, file descriptor

    if (argc < 2)
    {
        printf("usage : %s fichier\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1],  O_WRONLY | O_CREAT | O_TRUNC,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    dup2(fd, STDOUT_FILENO);

    printf("redirection de la sortie standard dans %s\n", argv[1]);
    printf("dup2 pour la redirection de sortie\n");

    if (close(fd) == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}



