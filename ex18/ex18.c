#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR: %s\n",message);
	}
	//Returns with a non zero exit status
	// An exit status of 0 means it is successful.
	// A non zero exit status means an error occurred
	exit(1);
}

//Typedef creates a "type" which can be used to define
//function pointers return types among other types
//
//Creates a function pointer which takes 2 integers as inputs
//returns a integer as the return variable.
typedef int (*compare_cb) (int a, int b);

//Simple bubble sort functiom
// The third parameter compare_cb is the function pointer
// The same bubble_sort can accept different 
// types of sorting orders by defining function which
// have the same signature as compare_cb
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int j=0;
	int i=0;

	int *target = malloc(count * sizeof(int));
	if(!target)
	{
		die("Memory Error!");
	}

	memcpy(target, numbers, count *sizeof(int));

	for (i = 0; i < count ; i++)
	{
		for (j=0; j < count - 1 ; j++)
		{
			// Here the callback is seen
			//depending on which order is passed into
			//bubble sort that particular function is
			//passed to the line below.
			//by passing a function pointer
			//the functions can be invoked as any variable or array or struct.
			if(cmp(target[j], target[j+1]) > 0)
			{
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}

int sorted_order(int a, int b)
{
	return (a >b ) - (a <b);
}

int reverse_order(int a, int b)
{
	return (a < b) - (a > b); 
}

int strange_order(int a, int b)
{
	if (a ==0 || b ==0)
		return 0;
	else
		return a%b;
}
//This is just a wrapper for the bubble_sort 
//function. to print the numbers after they have
//been sorted
void test_sorting (int *numbers, int count, compare_cb cmp)
{
	int i=0;
	int *sorted = bubble_sort(numbers, count, cmp);

	if(!sorted)
		die("Failed to sort as requested");

	for(i=0; i< count; i++)
	{
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);
}

int main(int argc, char const *argv[])
{
	if(argc < 2)
		die("USAGE: ex18 1 2 3 4 5 ");

	int count = argc - 1;
	int i = 0;
	// This is a pointer to a pointer to a char
	//i.e this is a pointer to the arguments passed to the program
	char **inputs = argv +1;

	int *numbers = malloc(count * sizeof(int));
	if(!numbers)
		die("Memory Error");

	for(i =0; i < count ; i++)
	{
		//This converts the parameters passed to int and assigns them to a
		// array of integers as per the index.
		// this array is used for sorting later
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers,count, sorted_order);
	test_sorting(numbers,count, reverse_order);
	test_sorting(numbers,count, strange_order);

	free(numbers);
	return 0;
}