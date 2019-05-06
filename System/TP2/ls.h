#ifndef _LS_H_INCLUDED
#define _LS_H_INCLUDED

#define PARAM_SET_ALL(x) (x |= 1)
#define PARAM_IS_ALL(x) (x & 1)

#define PARAM_SET_DIR(x) (x |= 2)
#define PARAM_IS_DIR(x) (x & 2)

#define PARAM_SET_INO(x) (x |= 4)
#define PARAM_IS_INO(x) (x & 4)

#define PARAM_SET_LNG(x) (x |= 8)
#define PARAM_IS_LNG(x) (x & 8)

#define PARAM_SET_NUM(x) (x |= 16)
#define PARAM_IS_NUM(x) (x & 16)

#define PARAM_SET_REC(x) (x |= 32)
#define PARAM_IS_REC(x) (x & 32)

#define PARAM_SET_SIZ(x) (x |= 64)
#define PARAM_IS_SIZ(x) (x & 64)

// forward declarations
struct stat;
struct dirent;

// analyse des paramètres de la ligne de commande grâce à la fonction getopt
extern int      ls_parse_args(int argc, char ** argv);

// affichage de l'aide
extern void     ls_display_help();

// filtre le répertoire courant ., utile pour la fonction scandir
extern int      ls_filter_hidden(const struct dirent * dir);

// test si on a un répertoire
extern int      ls_is_dir(const struct dirent * dir);

// retourne le nom du fichier à partir d'un chemin relatif
extern char *   ls_short_path(const char * path);

// affiche une arborescence à partir d'un chemin donnée
extern int      ls_display_rec(const char * path);

// affiche un répertoire, si option -R descente récursive
extern int      ls_display_dir_rec(const char * path);

//  affiche selon les options choisies :
    // l'inode
    // la taille en nombre de blocs
    // si option -l ou -n
        // alors appelle la fonction ls_display_file_long
        // sinon affiche le nom du fichier
extern int 	    ls_display_file(const char * path, const struct stat * buf);

// affiche selon les options choisies :
    // les permissions
    // les uid-gid numériquement ou littéralement
    // la taille en octets
    // la date quelque soit l'option
    // si lien
        // alors affiche le lien
        // sinon affiche le nom du fichier
extern int      ls_display_file_long(const char * path, const struct stat * buf);

// TRI lexicographique pour la fonction scandir
extern int      ls_sort(const struct dirent ** a, const struct dirent ** b);

#endif /** _LS_H_INCLUDED*/
