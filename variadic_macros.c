#include <stdio.h>
#include <stdarg.h>

#define FOO(...) printf(__VA_ARGS__)
#define FOO1(M, ...) printf(M, __VA_ARGS__)
int main(int argc, char const *argv[])
{
	printf("Testing variadic arguments\n");

	printf("Testing FOO\n");
	for(int i=0; i <= argc; i++)
	{
		FOO("Argument: %s\n", argv[i]);
	}

	printf("Testing FOO1\n");
	for(int i=0; i <= argc; i++)
	{
		FOO1("Arguments: %d %s\n",i, argv[i]);
	}

	/* code */
	return 0;
}