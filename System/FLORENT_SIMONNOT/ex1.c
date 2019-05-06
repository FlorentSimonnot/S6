#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
	struct stat fileStat, fileStat2;

    if(2 != argc) {
    	fprintf(stderr,"I need one file name\n");
    	return 1;
    }   

    if(lstat(argv[1], &fileStat) < 0){
    	perror("stat\n");
    	return 1;
    }   

    if(S_ISLNK(fileStat.st_mode)){
    	printf("This is a symbolic link\n");
    	printf("Name : %s\n", argv[1]);
	    printf("Inode : %lu\n",fileStat.st_ino);
		if(stat(argv[1], &fileStat2) < 0){
	    	perror("stat\n");
	    	return 1;
	    } 
	    printf("File link :\n");
	    printf("Inode : %lu\n",fileStat2.st_ino);
	    return 0;
    }

    if(!S_ISDIR(fileStat.st_mode)){
    	fprintf(stderr, "%s isn't a repertory\n", argv[1]);
    	return 1;
    }

    printf("Name : %s\n", argv[1]);
    printf("Inode : %lu\n",fileStat.st_ino);

	return 0;
}