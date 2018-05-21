#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i=0;
	for (i = 0; i < argc; ++i)
	{
		printf("Argument %d: %s\n", i, argv[i]);
		//argv[0] is the calling executable. i.e the program being executed in argv[0]
		/* code */
	}

	int num_of_states=4;
	char *states[]={ "Washington","Oregon","Texas", "California"};
	for (i = 0; i < num_of_states; ++i)
	{
		printf("State %d: %s\n", i,states[i]);
		/* code */
	}
	return 0;
}