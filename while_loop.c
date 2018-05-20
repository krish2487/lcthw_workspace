#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i =0;
	while( i<= 10)
	{
		//Will break the while loop when i=7, will print only till 6. 
		//When i=7, loops back to while condition checking and exit the main while loop.
		if(i == 7)
		{
			i=12;
			continue;
		}
		printf(" I = %d\n",i);
		i++;
	}
	return 0;
}