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


// OU SE TROUVE le fichier fcntl.h dans l'arborescence?
// find / -name fctnl.h -print 2>/dev/null&
// réponse dans le répertoire : /usr/include
// rappel stdio.h et stdlib.h dans /usr/include
/*********************************
rappel pour voir mes processus la commande ps
  PID TTY          TIME CMD
 2138 pts/0    00:00:01 bash
 2192 pts/0    00:00:54 geany
 4717 pts/0    00:00:10 find
 4759 pts/0    00:00:00 ps

SORTIE DE LA COMMANDE  find / -name fctnl.h -print 2>/dev/null&

POUR EXECUTER DES PROGRAMMES WINDOWS sous LINUX : wine ....
/home/landsnet/.PlayOnLinux/wine/linux-x86/4.0-rc4/include/wine/msvcrt/fcntl.h
/usr/include/x86_64-linux-gnu/asm/fcntl.h
/usr/include/x86_64-linux-gnu/bits/fcntl.h
/usr/include/x86_64-linux-gnu/sys/fcntl.h
/usr/include/linux/fcntl.h
/usr/include/asm-generic/fcntl.h

LE VOILA!!!!!
/usr/include/fcntl.h

SOURCES Linux
/usr/src/linux-headers-4.15.0-44/arch/m32r/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/mn10300/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/score/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/arm64/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/arm/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/ia64/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/sparc/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/mips/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/alpha/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/m68k/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/x86/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/parisc/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/powerpc/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/frv/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/arch/blackfin/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-44/include/uapi/linux/fcntl.h
/usr/src/linux-headers-4.15.0-44/include/uapi/asm-generic/fcntl.h
/usr/src/linux-headers-4.15.0-44/include/linux/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/m32r/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/mn10300/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/score/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/arm64/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/arm/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/ia64/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/sparc/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/mips/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/alpha/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/m68k/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/x86/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/parisc/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/powerpc/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/frv/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/arch/blackfin/include/uapi/asm/fcntl.h
/usr/src/linux-headers-4.15.0-45/include/uapi/linux/fcntl.h
/usr/src/linux-headers-4.15.0-45/include/uapi/asm-generic/fcntl.h
/usr/src/linux-headers-4.15.0-45/include/linux/fcntl.h
***********************************************************************/

#define BUFFERSIZE (10)

int main(int argc, char **argv)
{
    int src, i;
    ssize_t r;
    char buf[BUFFERSIZE];

    // entrée standard par défaut
    if (argc == 1)
    {
        while ((r = read(STDIN_FILENO, buf, BUFFERSIZE)) != 0)
        {
            if (r == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
            if (write(STDOUT_FILENO, buf, r) == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }
        return 0;
    }


    for (i = 1; i < argc; ++i)
    {
        if ((src = open(argv[i], O_RDONLY)) == -1)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }

        while ((r = read(src, buf, BUFFERSIZE)) != 0)
        {
            if (r == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
            if (write(STDOUT_FILENO, buf, r) == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }

        if (close(src) == -1)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}
