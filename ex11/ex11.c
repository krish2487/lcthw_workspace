#include <stdio.h>

int main(int argc, char const *argv[])
{
	//Initializing all the elements to 0
	int numbers[4] = {0};
	//The assignment below only sets the first element to a. 
	char name[4] = {'a'};

	//Print each element in the arrays
	printf("numbers: %d %d %d %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

	//Print the entire char ayyar as a string
	printf("name: %s\n", name);

	numbers[0]=1;
	numbers[1]=2;
	numbers[2]=3;
	numbers[3]=4;

	name[0]='Z';
	name[1]='e';
	name[2]='d';
	name[3]='\0'; // The null char has to be explicitly assigned to the last element.

	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
	printf("%s\n", name);

	char *another = "Zed";
	printf("Another name: %s\n", another);
	printf("Another name each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);
	// Since a string is also a character array, individual elements can be indexed and accessed.

	return 0;
}