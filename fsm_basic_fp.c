#include <stdio.h>
#include <stdbool.h>
bool flag1 = true,flag2=true;
static void STATE_A (void);
static void STATE_B (void);
static void STATE_C (void);
static void (*state_pointer)(void) = STATE_A;

static void STATE_A (void)
{
	printf("Executing State A\n");
	if(flag1)
	{
	printf("Changing state to State B\n");
	state_pointer = STATE_B;
	flag1 = false;
	flag2 = true;
	}
	printf("Exiting State A\n");

}

static void STATE_B (void)
{
	printf("Executing State B\n");
	if(flag2)
	{
	printf("Changing state to State C\n");
	state_pointer = STATE_C;
	flag2 = false;
	flag1 = true;
	}
	printf("Exiting State B\n");

}

static void STATE_C (void)
{
	printf("Executing State C\n");
	if(flag1)
	{
	printf("Changing state to State A\n");
	state_pointer = STATE_A;
	flag1 = false;
	}

	if(!flag2)
	{
	printf("Changing state to State B\n");
	state_pointer = STATE_B;
	}
	printf("Exiting State C\n");

}

int main(int argc, char const *argv[])
{
	/* code */
		for (int i = 0; i < 5; ++i)
		{
		(*state_pointer)();
			/* code */
		}
	    /* code */
	
	return 0;
}