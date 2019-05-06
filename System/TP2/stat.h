#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED

// forward declaration
struct stat;

// retourne le type d'un fichier
extern char get_type(const struct stat * buf);

// récupère les permissions dans la variable perm de longueur 10
// 10 car -rw-r--r--, drwxr-xr-x par exemples
extern void get_perm(const struct stat * buf, char * perm);

// affichage du numéro d'inode
extern void display_inode(const struct stat * buf);

// affichage d'un lien
extern void display_link(const char * filename);

extern void display_size(const struct stat *buf);

// affichage numérique ou littéral des uid et gid
extern void display_uid_gid(const struct stat * buf, int num);

// affichage de la date
extern void display_date(const struct stat * buf);

extern void display_blocks(const struct stat *buf);

#endif /** STAT_H_INCLUDED*/
