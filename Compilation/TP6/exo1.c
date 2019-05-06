#include <stdio.h>
#include <inttypes.h>

int32_t _doubleX(int32_t);
int32_t _tripleXPlus1(int32_t);
int32_t _seizeXPlus2(int32_t);
int32_t _pos_or_neg(int64_t);
int32_t _pair_or_impair(int64_t);

int main(int argc, char* argv[]) {
	printf("2 * %d = %d\n",5,  _doubleX(5));
	printf("3 * %d + 1 = %d\n", 5,  _tripleXPlus1(5));
	printf("15 * %d + 2 = %d\n", 5, _seizeXPlus2(5));
	printf("%d est negatif ? %d\n", 5,  _pos_or_neg(5)); 
	printf("%d est negatif ? %d\n", -5, _pos_or_neg(-5)); 
	printf("%d est pair ? %d\n", _pair_or_impair(5));
	printf("%d est pair ? %d\n", _pair_or_impair(6));
	return 0;
}