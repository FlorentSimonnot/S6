#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE (10)

typedef struct
{
    int lines;
    int words;
    int cars;
    int total_lines;
    int total_words;
    int total_cars;
} Wlc;

int count_lwc(int fd, Wlc * wlc);

int main(int argc, char ** argv)
{
    int fd = 0; // entrée standard par défaut
    Wlc wlc;

    wlc.total_lines = 0;
    wlc.total_words = 0;
    wlc.total_cars = 0;

    // entrée standard par défaut
    if (argc == 1)
    {
        if (count_lwc(fd, &wlc) == 0)
        {
            write(STDERR_FILENO, "erreur de lecture du fichier \n", 32);
            return 0;
        }

        printf("\t%d \t%d \t%d \n", wlc.lines, wlc.words, wlc.cars);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        fd = open (argv[i],O_RDONLY);
        if (fd == -1)
        {
            write (STDERR_FILENO,"le fichier n'existe pas \n", 32);
            return 1;
        }

        if (count_lwc(fd, &wlc) == 0)
        {
            write(STDERR_FILENO, "erreur de lecture du fichier \n", 32);
            close(fd);
            return 0;
        }

        close(fd);
        printf("\t%d \t%d \t%d \t%s\n", wlc.lines, wlc.words, wlc.cars, argv[i]);
    }

    printf("\t%d \t%d \t%d \ttotal\n", wlc.total_lines, wlc.total_words, wlc.total_cars);

    return 0;
}


int count_lwc(int fd, Wlc * wlc)
{
    char buf[BUFFERSIZE];

    wlc->lines = 0;
    wlc->words = 0;
    wlc->cars = 0;

    int n = 1; // nombre d'octets lus
    int current_state = 2;
    while (n > 0)
    {
        n = read (fd, buf, BUFFERSIZE);
        if (n == -1)
        {
            return 0;
        }

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                wlc->cars++;
                wlc->total_cars++;

                if (isspace(buf[i]) != 0)   // le caractère lu est un séparateur
                {
                    if (buf[i] == '\n')
                    {
                        wlc->lines++;
                        wlc->total_lines++;
                    }

                    if (current_state == 1 )
                        current_state = 2;
                }
                else   // le caractère lu est une lettre
                {
                    if (current_state == 2)
                    {
                        current_state = 1;
                        wlc->words++;
                        wlc->total_words++;
                    }
                }
            }
        }
    }

    return 1;
}
