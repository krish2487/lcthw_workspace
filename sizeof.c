#include <stdio.h>

int main(int argc, char const *argv[])
{
	int var = 100;
	int var_array[10]={1,2,3,4,5,6,7,8,9,0};

	printf("Size of var is %d\n", sizeof(var));
	printf("Size of var_array is %d\n", sizeof(var_array));
	printf("Size of var_array elements is %d\n", sizeof(var_array[0]));
	printf("Number of elements is %d \n", sizeof(var_array)/sizeof(var_array[0]));
	return 0;
}
