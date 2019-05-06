#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE (10)

/**
le dup sans le pipe sert à faire les redirections :
pour faire un ls >toto
*/

int main(int argc, char ** argv)
{
    char buf[BUFFERSIZE];
    int i;
    int fd;  // decripteur de fichier, file descriptor

    if (argc < 2)
    {
        printf("usage : %s fichier\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    dup2(fd,STDIN_FILENO);

    for (i = 0; i < 3; i++)
    {
        scanf("%s", buf);
        printf("j'ai lu %s\n", buf);
    }

    if (close(fd) == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}



