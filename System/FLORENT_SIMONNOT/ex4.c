#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void translate(char word[512], int length){
	int i, l; 

	for(i = 0; i < length; i++){
		switch(word[i]){
			case 'a' : word[i] = '4'; break; 
			case 'o' : word[i] = '0'; break;
			case 'e' : word[i] = '3'; break;
			case 't' : word[i] = '7'; break; 
			case 'l' : word[i] = '1'; break;
			default : break;
		}
	}
}

int main(int agrc, char* argv[]){
	char buf[512];
	int size = 512;
	int nb_car = 0;


	if( (nb_car = read(0, buf, size)) == -1){
		perror("read error\n"); 
		exit(1);
	}

	translate(buf, nb_car); 

	if(write(1, buf, nb_car) == -1){
		perror("read error\n"); 
		exit(1);
	}

	return 0;
}