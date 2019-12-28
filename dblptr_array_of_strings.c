#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    printf("Printing all the arguments\n");

    char **temp = argv;


    while(*temp != NULL)
    {
        printf("%s \n", *temp);
        temp++;
    }

    char *test[] = {"Hello", "Test", "array", "fluff", "lorem", "ipsum","alpha", "bravo","charlie","delta","END_OF_ARRAY"};

    // char **temp = NULL;
    temp = test;
    int element=0,character=0;

    for(element=0;test[element]!="END_OF_ARRAY";element++)
    {
        printf("Element: %s\n", test[element]);
        for(character=0;(*(*(test + element) + character))!='\0';character++)
        {
            printf("%c\t",*(*(test + element) + character));
        }
        printf("\n");
    }

    // while(*temp != "END_OF_ARRAY")
    // {
    //     printf("%s \n", *temp);
    //     temp++;
    // }

    return 0;
}