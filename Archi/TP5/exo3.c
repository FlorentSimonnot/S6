#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_time(int *tab, int size,  int (*fct)(int*, int)){
    unsigned long nb = clock(); 
    int res;

    res = fct(tab, size);

    printf("%.10f sec\n", (clock()-nb)/(float)CLOCKS_PER_SEC);
    return res; 
}

void construit_tableau(int *tab, int size){
    int i; 

    for(i = 0; i < size; i++){
        tab[i] = rand()%(100-1) +1;
    }
}

int fct1(int *tab, int size){
    int i = 0; 
    int nb = 0;

    for(i = 0; i < size; i++){
        if(tab[i] > 24){
            if(tab[i] < 51)
                nb++; 
        }
    }
    return nb; 
}

int fct2(int *tab, int size){
    int i = 0; 
    int nb = 0;

    for(i = 0; i < size; i++){
        if(tab[i] < 51){
            if(tab[i] > 24)
                nb++; 
        }
    }
    return nb; 
}


int main(){
    int *tab; 

    if((tab = (int*) malloc(sizeof(int) * 1000000)) == NULL){
        exit(EXIT_FAILURE); 
    } 

    construit_tableau(tab, 1000000); 
    printf("%d\n", print_time(tab, 1000000, fct1));
    printf("%d\n", print_time(tab, 1000000, fct2));

    return 0; 
}