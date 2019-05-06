#include <stdio.h>
#include <inttypes.h>

int32_t _mult2(int64_t); 

int main(void){

	printf("2 * %d = %d\n",5,  _mult2(5));
	return 0;
}