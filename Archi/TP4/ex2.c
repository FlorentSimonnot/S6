#include <stdio.h>
int sum (int count){
	int s = 0;
	int i;
	for(i = 0; i < count; i++)
		s+=i*i*i;
	return s;
}

int main() {
	int count = 10000000;
	printf("%d\n", sum(count));
}