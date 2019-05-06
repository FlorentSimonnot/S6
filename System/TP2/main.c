#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#include "ls.h"

int main(int argc, char ** argv) {
    if (ls_parse_args(argc, argv) == -1) {
        printf("Try `%s --help' for more informations\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*Pas de chemin précisé*/
    if (optind == argc) {
        if (ls_display_dir_rec(".") == -1) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    } 
    /*Chemin précisé*/
    else {
        unsigned int i;

        for (i = optind; i < argc; i++) {
            if (ls_display_rec(argv[i]) == -1) {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }
    }
    exit(EXIT_SUCCESS);
}
