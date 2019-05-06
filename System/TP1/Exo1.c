#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/*===========================TP1===========================*/

//EXERCICE 1


int main(int argc, char **argv){

    if(2 != argc) {
    	fprintf(stderr,"I need one file name");
 		printf("\n");
    }   
       
    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
 
    printf("Information for %s\n",argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
    printf("Number of Links: \t%hu\n",fileStat.st_nlink);
    printf("File inode: \t\t%llu\n",fileStat.st_ino);
    printf("Last modification : \t%ld\n", fileStat.st_mtime);
    if(S_ISREG(fileStat.st_mode)){
    	printf("Type : \t\t\tfile\n");
    }
    else if(S_ISDIR(fileStat.st_mode)){
    	printf("Type : \t\t\trepertory\n");
    }
    else{
    	printf("Type : \t\t\tother\n");
    }
 
    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
 
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
	return 0;
}