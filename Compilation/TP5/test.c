#include <stdio.h>

int hello_world(int nb){
	printf("%d\n", nb);
	return nb;
}

int main(void){

	hello_world(3);

	return 0;
}