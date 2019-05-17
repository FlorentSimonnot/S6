#include <stdio.h>
#include <stdlib.h>

int sum2(int count){
    int s = 0, i; 
    for(i = 0; i < count; i +=4){
        s += 1; 
        s += 2; 
        s += 3; 
        s += 4; 
    }
    return s; 
}


int main(){



    return 0; 
}