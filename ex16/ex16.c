#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//Creates a structure called "Person" who has the following members
// char* name
//  int age
//  int height
//  int weight
struct Person
{
	char *name;
	int age;
	int height;
	int weight;	
};

// Create a function called Person_create which returns a pointer to a structure
// and takes name, age, height and weight as parameters
struct Person *Person_create(char* name, int age, int height, int weight)
{
	//Creates a pointer "who" to a structure of type "Person" and allocates a block of memory
	// the size of structure type "Perspn"
	struct Person *who = malloc(sizeof(struct Person));
	//Checks that the allocated structure is not null i.e the processor was able to
	//allocate the required memory.
	assert (who != NULL);

	//Access members of the structure is done by "->" operator
	//strdup is string duplicate
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	//Asserts that the structure is not NULL
	// if it is NULL then the free() cannot operate
	// The assert halts the program flow if the Person_destroy 
	// is called twice on the same parameter
	assert (who != NULL);
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name : %s\n",who->name);
	printf("\tAge : %d\n",who->age);
	printf("\tHeight : %d\n",who->height);
	printf("\tWeight : %d\n",who->weight);
}
int main(int argc, char const *argv[])
{
	//Creates pointers to structures of type Person with the corresponding parameters
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	printf("Joe is at memory location: %p\n", joe);
	Person_print(joe);

	printf("Frank is at memory location: %p\n", frank);
	Person_print(frank);

	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	Person_destroy(joe);
	Person_destroy(frank);
	// Person_destroy(frank);

	return 0;
}