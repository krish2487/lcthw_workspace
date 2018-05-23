#include <stdio.h>

int main(int argc, char const *argv[])
{
	int ages[]={23,43,12,89,2};
	char *names[] = {"Alan","Frank","Mary","John","Lisa"};

	int count = sizeof(ages)/sizeof(int);
	int i=0;

	//Array access the normal way
		for(i=0; i < count; i++)
		{
			printf("%s has %d years alive.\n", names[i], ages[i]);
		}

	printf("---\n");

	//Creates a pointer to an integer
	int *cur_age = ages;
	//Creates a pointer, pointing to a pointer,which is pointing to a character array
	//Since the array names[] itself is a array of character arrays.
	//We need a pointer pointing to another character array pointer
	char **cur_name = names;

	for (i=0; i< count;i++)
	{
		printf("%s id %d years old\n", *(cur_name + i),*(cur_age + i));
		//The increment by i has to be within braces to point to the next elememt in the array.
		//Omitting the braces will increment the pointer to the next character in a given element
		
		// *(cur_name + i ) != *cur_name +i
		//When i = 0, both point to the zeroth element of the names array
		//When i=1
		//*(cur_name + i) points to the first element in the names array
		// *cur_name + i points to the first character of the zeroth element in names array

		// The below line shows the difference in pointer arithmetic.
		// printf(" %s %s \n", *(cur_name + i), *cur_name +i);
	}

	printf("---\n");

	// Pointers can also be accessed using array indexing i.e [subscript]
	for( i = 0; i < count ; i++)
	{
		printf("%s id %d years old again\n", cur_name[i], cur_age[i]);
	}
	//Pointers are not arrays.
	//even though cur_name points to names[]
	//names[] is an array, cur_name is apointer of type character.
	//sizeof (cur_name) = sizeof (char).
	// i.e size of pointer is the size of its data type
	printf("Size of names[] is : %ld\n",sizeof(names));
	printf("Size of cur_name is : %ld\n",sizeof(cur_name));
	return 0;
}