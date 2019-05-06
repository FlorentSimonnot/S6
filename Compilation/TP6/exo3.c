#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

void afficher_tab(int *tab, int length){
	int i; 

	for(i = 0; i < length; i++)
		printf("%d ", tab[i]);
	printf("\n");
}

void init_crible_c(int *tab, int length){
	int i; 

	tab[0] = tab[1] = 0;
	for(i = 2; i < length; i++)
		tab[i] = 1;
}

void crible_c(int *tab, int length){
	int i, j; 

	for (i = 2 ; i < sqrt(length) ; i++){
      	if (tab[i]){
         	for (j = i*i ; j < length ; j += i)
        		tab[j] = 0;
	    }
	}
      
}

int main(void){
	int n; 
	int *tab;

	printf("Entrez un nombre : ");
	if(scanf("%d", &n) == 0)
		return 0; 
	tab = (int *) malloc(sizeof(int) * n);
	init_crible_c(tab, n);
	afficher_tab(tab, n);
	crible_c(tab, n);


	return 0;
}