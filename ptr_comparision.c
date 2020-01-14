#include <stdio.h>

int main(int argc, char const *argv[])
{
    const char *ptr1="Hello";
    const char *ptr2="Hello";
    const char *ptr3="World";

    if(*ptr1 == *ptr2)
    {
        printf("PTR1 and PTR2 are equal\n");
    }
    if(ptr1 == ptr3)
    {
        printf("PTR1 and PTR3 are equal\n");
    }

    return 0;
}