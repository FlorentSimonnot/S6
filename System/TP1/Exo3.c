#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

/*===========================TP1===========================*/

//EXERCICE 3


int main(void){
	DIR *dir;
	struct dirent *dent;
	dir = opendir(".");

	if(dir != NULL){
		while((dent = readdir(dir)) != NULL){
			if (strcmp(dent->d_name, "..") != 0 && strcmp(dent->d_name, ".") != 0){
				printf("%s\n", dent->d_name);
			}
		}
	}
	closedir(dir);
	return 0;

}