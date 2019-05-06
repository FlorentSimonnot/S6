#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int n;
	/*printf("bonjour\n"); 
	fork(); 
	printf("au revoir\n");
	Affiche : 
	Bonjour
	Au revoir
	Au revoir
	*/
	
	switch((n = fork())){
		case -1 : 
			perror("Fork ???");
			exit(1);
		case 0 : 
			execlp("/bin/ls", "ls", NULL);
			perror("?");
			exit(2);
		default : 
			/*Si pas de wait alors cela affichera un message terminé même si ca lest pas*/
			wait(0);
			printf("ls est terminé\n");


	}
	


	return 0;
}