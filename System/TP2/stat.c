#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>

#include "stat.h"

char get_type(const struct stat * buf) {
    unsigned int i;

    struct _typemap {
        char type;
        short macro;
    } typemap[] = {
        {'-', S_ISREG(buf->st_mode)},
        {'d', S_ISDIR(buf->st_mode)},
        {'c', S_ISCHR(buf->st_mode)},
        {'b', S_ISBLK(buf->st_mode)},
        {'p', S_ISFIFO(buf->st_mode)},
        {'l', S_ISLNK(buf->st_mode)},
        {'s', S_ISSOCK(buf->st_mode)}
    };

    for (i = 0U; i < (unsigned) (sizeof(typemap)/sizeof(typemap[0])); ++i)
        if (typemap[i].macro == 1) {
            return typemap[i].type ;
        }

    return '?';
}

void get_perm(const struct stat * buf, char * perm) {
    printf( (buf->st_mode & S_IRUSR) ? "r" : "-");
    printf( (buf->st_mode & S_IWUSR) ? "w" : "-");
    printf( (buf->st_mode & S_IXUSR) ? "x" : "-");
    printf( (buf->st_mode & S_IRGRP) ? "r" : "-");
    printf( (buf->st_mode & S_IWGRP) ? "w" : "-");
    printf( (buf->st_mode & S_IXGRP) ? "x" : "-");
    printf( (buf->st_mode & S_IROTH) ? "r" : "-");
    printf( (buf->st_mode & S_IWOTH) ? "w" : "-");
    printf( (buf->st_mode & S_IXOTH) ? "x" : "-");
}

void display_inode(const struct stat * buf) {
    printf("%ld ", buf->st_ino);
}

void display_blocks(const struct stat *buf){
    printf("%ld ", buf->st_blocks);
}

void display_size(const struct stat *buf){
    printf("%ld ", buf->st_size);
}

void display_link(const char * filename) {
    char link_buf[BUFSIZ];
    ssize_t size;

    if ((size = readlink(filename, link_buf, BUFSIZ)) == -1) {
        perror("Problem with the link");
        exit(EXIT_FAILURE);
    }

    char link_str[size];
    snprintf(link_str, size + 1, "%s", link_buf);
    printf("%s -> %s\n", filename, link_str);
}


void display_uid_gid(const struct stat * buf, int num) {
    struct passwd * pwuid = NULL;
    struct group * grgid = NULL;

    if (num){
        pwuid = getpwuid(buf->st_uid);
        printf("%s ", pwuid->pw_name);
        grgid = getgrgid(buf->st_gid);
        printf("%s ", grgid->gr_name);
        printf("%d %d ", buf->st_uid, buf->st_gid);
        return;
    }
}

void display_date(const struct stat * buf) {
    struct tm * date;
    char * months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


    if (NULL == (date = localtime(&buf->st_ctime)))
        return;

    printf("%d-%s-%d %d:%d:%d", 1900+date->tm_year, months[date->tm_mon], date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);

}
