#include <stdio.h>
#include <stdint.h>
void main()
{
	printf("Testing string magic\n");

	for (uint8_t i = 0; i <= 9 ; i++){
		printf("Array index is %d, array look up value is %c\n", i, "0123456789"[i]);
	}
}