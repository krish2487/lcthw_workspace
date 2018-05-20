#include <stdio.h>

int main(int argc, char const *argv[])
{
	//One type of structure declaration. 
	// test_struct_1 is optional. 
	// We can also create test_structure by 
	// struct1 test_struct_1
	struct struct1{
		int a;
		int b;
		int c;
	} test_struct_1;
	// struct struct1 test_struct_1;
	// Even this is valid. The tailing test_struct_1 in struct declaration is not 
	//required then.
	
	//Alternative declaration of a struct typedef.
	//
	typedef struct struct2
	{
		int a;
		int b;
		int c;
	} test_struct;
	test_struct test_struct_2;

	test_struct_1.a = 0;
	test_struct_1.b = 1;
	test_struct_1.c = 2;
	test_struct_2.a = 3;
	test_struct_2.b = 4;
	test_struct_2.c = 5;

	printf("%d\n", test_struct_1.a);
	printf("%d\n", test_struct_1.b);
	printf("%d\n", test_struct_1.c);
	printf("%d\n", test_struct_2.a);
	printf("%d\n", test_struct_2.b);
	printf("%d\n", test_struct_2.c);
	return 0;
}