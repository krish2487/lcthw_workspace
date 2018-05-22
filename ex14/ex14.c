#include <stdio.h>
#include <ctype.h>

//forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

//forward declaration not done for print_arguments
//but needed for above functions since print_arguments calls them

//Prints each argument in the programn execution from arg[0]
void print_arguments(int argc, char *argv[])
{
	int i=0;

	for (i = 0; i < argc; ++i)
	{
		print_letters(argv[i]);
		/* code */
	}
}

//prints each letter in a specific argument passed to the program
void print_letters(char arg[])
{
	int i=0;

	for (i = 0; arg[i] != '\0'; ++i)
	{
		char ch = arg[i];

		if ( can_print_it(ch)){
			//prints the character and integer equivalent
			printf("%c == %d ", ch,ch);
		}
		/* code */
	}
	printf("\n");
}

int can_print_it(char ch)
{
	// returns true only if the character is a alphabet or a blank space
	return isalpha((int)ch) || isblank((int)ch);
}

int main(int argc, char const *argv[])
{	
	//prints the arguments and their int equivalents including arg[0]
	print_arguments(argc, argv);
	return 0;
}