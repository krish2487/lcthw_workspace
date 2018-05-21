#include <stdio.h>

int main(int argc, char const *argv[])
{
	int areas[]={10,12,13,14,20};
	char name[]="Zed";
	char full_name[]={'Z','e','d',' ','A', ' ', 'S', 'h','a','w'};

	printf("The size of an int: %ld\n",sizeof(int));
	printf("The size of areas[]: %ld\n", sizeof(areas));
	printf("Number of ints in areas[]: %ld\n", sizeof(areas)/sizeof(int));
	printf("The first area id %d, second is %d\n", areas[0], areas[1]);

	printf("The size of char is: %ld\n", sizeof(char));
	printf("The size of name (char[])is %ld\n", sizeof(name));
	printf("The number of chars is : %ld\n", sizeof(name)/sizeof(char));

	printf("The size of full_name is : %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n", sizeof(full_name)/sizeof(char));

	printf("name = \"%s\" and full name = \"%s\" \n", name,full_name);

	return 0;
}