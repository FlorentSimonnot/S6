#include <stdio.h>
#include <stdlib.h>

// man 2 open ==> je sais quoi inclure!
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// man 2 read ==> je sais quoi inclure!
// man 2 write ==> je sais quoi inclure!
// man 2 close ==> je sais quoi inclure!
#include <unistd.h>

#define BUFFERSIZE (10)


int main(int argc, char **argv)
{
    int src; // descipteur de fichier source
    int dest;// descipteur de fichier destination
    int n; // nombre d'octets lus
    char buf[BUFFERSIZE]; // buffer de travail

    if (argc < 2)
    {
        fprintf(stderr, "%s: missing file operand\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc < 3)
    {
        fprintf(stderr, "%s: missing destination file operand after `%s'\n",
                argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((src = open(argv[1], O_RDONLY)) == -1)
    {
        // echec si le fichier n'existe pas ou si pas R pour le user
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Attention au champ mode pour les droits, sinon, ils sont positionnés de
     * manière aléatoire */
    //  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH <==> 644
    if ((dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    while ((n = read(src, buf, BUFFERSIZE)) != 0)
    {
        if (n == -1)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
        if (write(dest, buf, n) == -1)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if ((close(src) == -1) || (close(dest) == -1))
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

