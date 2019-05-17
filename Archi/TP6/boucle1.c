#include <stdlib.h>
#include <stdio.h>

void fonction(int *A, int *B, int *C, int n){
    int i, s = 0; 

    for(i = 1; i < n-1; i++){
        A[i] = B[i-1];
        B[i] = C[i]; 
        s = A[i] + B[i];
        printf("%d %d\n", A[i], B[i]);  
    }
    printf("%d\n", s); 
}

int main(){
    int i = 0; 
    int *A, *B, *C; 
    int n = 10;

    A = (int*) malloc(sizeof(int) * n); 
    B = (int*) malloc(sizeof(int) * n); 
    C = (int*) malloc(sizeof(int) * n); 

    fonction(A, B, C, n); 

    free(A); 
    free(B);  
    free(C);
    return 0; 
}