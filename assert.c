#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
	int i=0;
	for (i = 0; i < 10; ++i)
	{
		printf("I is : %d\n", i);
		assert(i<9);
		/* code */
	}
	return 0;
}