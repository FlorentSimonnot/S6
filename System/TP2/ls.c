#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <getopt.h>

#include "stat.h"
#include "ls.h"

static char * progname = NULL;
static int ls_param = 0;
static char * current_path = NULL;

int ls_parse_args(int argc, char ** argv) {
    struct option longopts[] = {
        {"all", 0, NULL, 'a'},
        {"directory", 0, NULL, 'd'},
        {"help", 0, NULL, 'h'},
        {"inode", 0, NULL, 'i'},
        {"long", 0, NULL, 'l'},
        {"numeric-uid-gid", 0, NULL, 'n'},
        {"recursive", 0, NULL, 'R'},
        {"size", 0, NULL, 's'}
    };
    int longindex;
    int r;

    progname = argv[0];

    while ((r = getopt_long(argc, argv, "adhilnRs", longopts, &longindex)) != -1) {
        switch(r) {
        case 'a':
            PARAM_SET_ALL(ls_param);
            break;
        case 'd':
            PARAM_SET_DIR(ls_param);
            break;
        case 'h':
            ls_display_help(argv[0]);
            break;
        case 'i':
            PARAM_SET_INO(ls_param);
            break;
        case 'l':
            PARAM_SET_LNG(ls_param);
            break;
        case 'n':
            PARAM_SET_NUM(ls_param);
            break;
        case 'R':
            PARAM_SET_REC(ls_param);
            break;
        case 's':
            PARAM_SET_SIZ(ls_param);
            break;
        case '?':
            return -1;
        default:
            printf("Option impossible\n");
            break;
        }
    }
    return 0;
}

void ls_display_help() {
    printf("Usage: %s [OPTION]... [FILE]...\n", progname);
    printf("  -a, --all                 do not ignore entries starting with .\n");
    printf("  -d, --directory           list directory entries instead of contents,\n and do not dereference symbolic links\n");
    printf("      --help                print this help\n");
    printf("  -i, --inode               print the index number of each file\n");
    printf("  -l,                       use a long listing format\n");
    printf("  -n, --numeric-uid-gid     like -l, but list numeric user and groups IDS\n");
    printf("  -R, --recursive           recursive\n");
    printf("  -s, --size                print the size of each file, in blocks\n");
}

int ls_filter_hidden(const struct dirent * dir) {
    if (dir->d_name[0] == '.')
        return 0;
    return 1;
}

int ls_is_dir(const struct dirent * dir) {
    struct stat buf;
    int pathsize = strlen(current_path) + strlen(dir->d_name) + 2;

    char fullpath[BUFSIZ];

    snprintf(fullpath, pathsize, "%s/%s", current_path, dir->d_name);

    if (stat(fullpath, &buf) == -1) {
        perror(progname);
        return EXIT_FAILURE;
    }

    return S_ISDIR(buf.st_mode);
}

char * ls_short_path(const char * path) {
    char * shortpath;
    if ((shortpath = strrchr(path, '/')) != NULL)
        return shortpath + 1;
    return (char *) path;
}

/**********************************************************************/


/**********************************************************************
PARCOURS RECURSIF D'UNE ARBORESCENCE
**********************************************************************/

int ls_display_rec(const char * path) {
    struct stat buf;

    if (lstat(path, &buf) == -1)
        return -1;

    if (S_ISDIR(buf.st_mode))
        return ls_display_dir_rec(path);

    return ls_display_file(path, &buf);
}

int ls_display_file(const char * path, const struct stat * buf) {
    // si option -i affiche l'inode
    if(PARAM_IS_INO(ls_param)){
        display_inode(buf);
    }

    // si option -s affiche la taille en nombre de blocs
    if(PARAM_IS_SIZ(ls_param)){
        display_blocks(buf);
    }

    // si option -l ou -n retourne ls_display_file_long
    if(PARAM_IS_LNG(ls_param) || PARAM_IS_NUM(ls_param)){
        return ls_display_file_long(path, buf);
    }

    // affiche le nom du fichier
    printf("%s ", path);
    printf("\n");


    return 0;
}

// chaîne de 10 octets pour mémoriser le type
// et les 3 permissions de l'utilisateur, du groupe et des autres
int ls_display_file_long(const char * path, const struct stat * buf) {
    char type;
    char perm[10];

    // si option -l affiche le type et les permissions
    if(PARAM_IS_LNG(ls_param)){
        type = get_type(buf);
        printf("%c ", type);
        get_perm(buf, perm);
        printf("%s ", perm);
    }


    // si option -n alors affiche les uid-gid numériquement sinon littéralement
    if(PARAM_IS_NUM(ls_param)){
       display_uid_gid(buf, 1);
    }

    // affiche le nombre d'octets
    display_size(buf);
    // affiche la date
    display_date(buf);

    // si lien
    if(type == 'l'){
        display_link(path);
    }
    // sinon affiche le nom du fichier
    if(strcmp(path, ".") != 0)
        printf("%s\n", path);

    return 0;
}

int ls_display_dir_rec(const char * path) {
    int size;
    struct dirent ** namelist;
    int (*filter)(const struct dirent *) = NULL;
    unsigned int i;

    // si l'option -a n'est pas activée
    // alors le filtre est ls_filter_hidden;
    if(!PARAM_IS_ALL(ls_param)){
        filter = ls_filter_hidden;
    }

    current_path = (char *) path;

    /* modifier 1 par une appel de scandir */
    if ((size = scandir(current_path, &namelist, filter, ls_sort)) == -1)
        return -1;

    // si descente récursive alors affiche le chemin
    if(strcmp(current_path, ".") != 0)
        printf("%s\n", current_path);

    for(i = 0U; i < size; ++i) {
        struct stat buf;
        size_t pathsize = strlen(path) + strlen(namelist[i]->d_name) + 2;
        char fullpath[BUFSIZ];

        snprintf(fullpath, pathsize, "%s/%s", path, namelist[i]->d_name);

        if (lstat(fullpath, &buf) == -1){
            return -1;
        }

        /* si c'est un répertoire != "." ou ".." et c'est récursif */
        if (S_ISDIR(buf.st_mode) && PARAM_IS_REC(ls_param) && strcmp(namelist[i]->d_name, ".") && strcmp(namelist[i]->d_name, "..")) {
            if (ls_display_dir_rec(fullpath) == -1)
                return -1;
        } else {
             ls_display_file(fullpath, &buf);
        }
    }

    // libération de la namelist
    for(i = 0U; i < size; i++)
        free(namelist[i]);
    return 0;
}


int ls_sort(const struct dirent ** a, const struct dirent ** b) {
    if ((ls_is_dir(*a) && ls_is_dir(*b)) || (!ls_is_dir(*a) && !ls_is_dir(*b)))
        return alphasort(a, b);

    if (ls_is_dir(*a))
        return 1;

    return -1;
}
