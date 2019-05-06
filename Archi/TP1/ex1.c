#include <stdio.h>
#include <stdlib.h>

void calcul(int m, int n){
	float a = m / 10.0; 
	float b = n / 10.0; 
	float c = (m + n) / 10.0; 

	printf("calcul en flotant de %d et %d\n", m, n);

	if(c != a + b){
		printf("Erreur %.10f différent de %.10f\n", c, a+b); 
	}
	else{
		printf("Ok!\n");
	}
}

int main(void){
	int i, j;
	int a[10] = {1, 1, 1, 1, 1, 3, 3, 3, 3, 3}; 
	int b[10] = {4, 5, 6, 7, 8, 4, 5, 6, 7, 8};

	for(i = 0; i < 10; i++){
		calcul(a[i], b[i]);
	}


	return 0;
}