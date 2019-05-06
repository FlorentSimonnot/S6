#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){
	int pipe_vers_serveur[2], pipe_retour_serveur[2];
	char prog[255], a[255], b[255], buffer[512];

	if(pipe(pipe_vers_serveur) == -1){
		perror("Erreur avec le pipe\n");
		_exit(1);
	}
	if(pipe(pipe_retour_serveur) == -1){
		perror("Erreur avec le pipe\n");
		_exit(1);
	}

	switch(fork()){
		case -1 : perror("Erreur avec le fork"); _exit(1); break;
		case 0 : dup2(pipe_vers_serveur[0], 0);
				dup2(pipe_retour_serveur[1], 1);
				close(pipe_vers_serveur[0]); 
				close(pipe_vers_serveur[1]); 
				close(pipe_retour_serveur[0]); 
				close(pipe_retour_serveur[1]);
				if(execlp("./addition", "./addition", NULL) == -1){
					perror("Erreur avec le exec\n");
					_exit(1);
				}
				break;
		default : 
				close(pipe_vers_serveur[0]); 
				close(pipe_retour_serveur[1]);
	}

	while(1){
		scanf("%s %s %s", prog, a, b); 

		sprintf(buffer, "%s %s\n", a, b); 

		write(pipe_vers_serveur[1], buffer, strlen(buffer)); 
		read(pipe_retour_serveur[0], buffer, 512); 
		printf("le resultat est %s\n", buffer);
	}

	return 0;
}