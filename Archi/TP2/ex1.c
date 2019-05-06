#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <x86intrin.h>

int main(int argc, char* argv[]){
	int n, i, somme = 0;
	//time_t t1, t2; 
	//unsigned long t1, t2;
	//unsigned int ui;

	//t1 = __rdtscp(&ui);

	if(argc != 2){
		fprintf(stderr, "Error need 1 argument\n"); 
		exit(EXIT_FAILURE);
	}

	n = atoi(argv[1]);

	for(i = 0; i <= n; i++){
		somme += i;
	}
	//t2 = __rdtscp(&ui);

	//printf("%d\n", somme);
	//printf("%fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
	//printf("%ld\n", (t2-t1));


	return 0;
}