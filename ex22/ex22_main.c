
#include "ex22.h"
#include "dbg.h"

const char *MY_NAME= "Zed A Shaw";
void scope_demo(int count)
{
	log_info("count is %d",count);
	if(count > 10)
	{
		//Declaring and initializing a used variable name again is bad. the below
		//count is a local variable, local to the if condition
		int count = 100;
		log_info("count in this scope is %d", count);
	}

	log_info("Count at exit is %d", count);
	count = 3000;  
	log_info("count after assignment is %d", count);

}

int main(int argc, char const *argv[])
{
	log_info("My name is %s, age %d", MY_NAME, get_age());
	set_age(100);
	log_info("The size is %d", THE_SIZE);
	print_size();
	THE_SIZE = 9;
	
	log_info("THE_SIZE is now %d", THE_SIZE);
	print_size();

	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once more: %f", update_ratio(300.0));

	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("Count after calling scope_demo: %d", count);

	return 0;
}