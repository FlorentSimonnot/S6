#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void pas_touche(int i){
    printf("Je fais des trucs\n");
}

void pause_interdite(int i){
	printf("On ne peut pas mettre en pause ! Aller salut !\n");
	_exit(1);
}


int main(int argc, char* argv[]){
	int count = 0;

	signal(SIGINT, pas_touche);
	signal(SIGCONT, pause_interdite);

	while(1){
		if(count < 2)
			printf("%d seconde\n", count); 
		else
			printf("%d secondes\n", count);
		sleep(1);
		count++;
	}

	return 0;
}