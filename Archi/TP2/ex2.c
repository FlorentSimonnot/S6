#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

int *tab = NULL;

float average(double save[10]){
	int i; 
	double sum = 0;

	for(i = 0; i < 10; i++){
		sum += save[i]; 
	}

	return sum/10.;
}

double max(double save[10]){
	int i = 0; 

	double max = save[i];

	for(i = 1; i < 10; i++){
		if(save[i] > max)
			max = save[i];
	}

	return max;
}

double min(double save[10]){
	int i = 0; 

	double min = save[i];

	for(i = 1; i < 10; i++){
		if(save[i] < min)
			min = save[i];
	}

	return min;
}

int acces_seq(int n){
	int i; 

	if(n > SIZE){
		return 0;
	}

	for(i = 0; i <= n; i++){
		tab[i] = n;
	}

	return 1;
}

int acces_alea(int n){
	int i, r; 

	if(n > SIZE){
		return 0;
	}

	r = rand()%n;

	for(i = 0; i <= n; i++){
		tab[r] = n;
	}

	return 1;	
}

float calcul(double save[10]){
	printf("average time : %f\n", average(save)); 
	printf("ecart : %f\n", (max(save) - min(save)));
	return (max(save) - min(save))/average(save) * 100;
}

int main(int argc, char* argv[]){
	clock_t t1, t2; 
	double save[10];
	int i = 0;

	srand(time(NULL));

	if(NULL == (tab = (int*) malloc(SIZE * sizeof(int)))){
		exit(EXIT_FAILURE);
	} 

	for(i = 0; i < 10; i++){
		t1 = clock(); 
		acces_alea(10000000);
		t2 = clock();
		save[i] = (double)(t2-t1)/CLOCKS_PER_SEC;
	}
	printf("%f\n", calcul(save));

	return 0;
}