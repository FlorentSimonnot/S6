#include <stdio.h>

int main(){
    int a[2], b[2], i = 0; 
    a[0] = 0; a[1] = 1; 
    b[0] = 2; b[1] = 3; 

    a[i] = b[i++]; 
    printf("%d %d %d %d\n", a[0], a[1], b[0], b[1]);


    return 0; 
}