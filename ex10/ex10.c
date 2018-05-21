#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERROR: Too few arguments\n");
		return 1;
		//This is how to abort a program with a non zero exit code
	}

	int i = 0;
	//argc is the count of arguments. Each argument can be a string .
	//argv[A][B] allows us to index each element B in each argument A
	for (i = 0; argv[1][i]; ++i)
	{
		char letter = argv[1][i];

		switch (letter)
		{
			// No break for lower case letters to allow for fallthrough to catch both uppercase and lower
			//case voewls. 
			case 'a':
			case 'A':
				printf(" %d: A\n",i);
				break;
			case 'e':
			case 'E':
				printf(" %d: E\n",i);
				break;
			case 'i':
			case 'I':
				printf(" %d: I\n",i);
				break;
			case 'o':
			case 'O':
				printf(" %d: O\n",i);
				break;
			case 'u':
			case 'U':
				printf(" %d: U\n",i);
				break;
			case 'y':
			case 'Y':
				if (i > 2)
				{
				printf(" %d: Y\n",i);
				}
				break;
			default:
				printf("%d: %c is not a vowel\n",i,letter);
		}
		/* code */
	}
	return 0;
}