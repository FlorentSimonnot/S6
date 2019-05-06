#include <stdio.h>
#include <stdlib.h>


int main(void){
	int max = 1000; 
	float somme1 = .0, somme2 = .0;

	//Somme 1
	
	for(int i = 1; i <= max; i++){
		somme1 += (1.0 / i);
	}

	for(int i = max; i >= 1; i--){
		somme2 += (1.0 / i);
	}

	printf("%.10f VS %.10f\n", somme1, somme2);


	return 0;
}