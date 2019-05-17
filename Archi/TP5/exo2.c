#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int compter_nombre_en_dessous(int *tab, int size, int seuil){
    int i = 0; 
    int nb = 0;

    for(i = 0; i < size; i++){
        if(tab[i] < seuil){
            nb += 1; 
        }
    }
    return nb; 
}

int print_time(int *tab, int size, int seuil){
    unsigned long nb = clock(); 
    int res;

    res = compter_nombre_en_dessous(tab, size, seuil);

    printf("seuil = %d --> %.10f sec\n", seuil, (clock()-nb)/(float)CLOCKS_PER_SEC);
    return res; 
}


void construit_tableau(int *tab, int size){
    int i; 

    for(i = 0; i < size; i++){
        tab[i] = rand()%1001; 
    }
}

int main(int argc, char *argv[]){
    int *tab; 
    int seuil[7] = {0, 50, 100, 200, 500, 700, 1000};

    srand(time(NULL));

    if((tab = (int*) malloc(sizeof(int) * N)) == NULL){
        exit(EXIT_FAILURE); 
    } 

    for(int i = 0; i < 7; i++){
        printf("%d\n", print_time(tab, N, seuil[i]));
    }

    free(tab);
    return 0; 
}