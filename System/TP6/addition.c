#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv []){
	int a, b; 
	int error; 

	setvbuf(stdout, NULL, _IONBF, 0);

	while(1){
		if(scanf("%d", &a) != 1){
			error = 1;
		}
		if(scanf("%d", &b) != 1){
			error = 1;
		}
		printf("%d\n", a+b);
	}

	return 0;
}