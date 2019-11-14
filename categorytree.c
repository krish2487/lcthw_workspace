#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef struct tCategory
{
    char* RecordParent;
    char* RecordName;
    bool RootCategory;
    struct tCategory * nextNode;
} tCategory;

bool addCategory(char* name, tCategory* parent);
bool getChildren(tCategory* category, char* results);


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

bool addCategory(char* name, tCategory* parent)
{
    // memory allocation
    tCategory* Record = (tCategory*) malloc(sizeof(tCategory));
    if(Record == NULL)
        return false;
    //check if parent category does not exist

    //Check if category already exists

    //check if it is a root category
    if(parent == 'NULL')
    {
        Record->RootCategory=true;
        Record->RecordParent = NULL;
    }
    else
    {
        Record->RootCategory=false;
        Record->RecordParent=parent->RecordName;
    }

    parent->nextNode = (Record);
    Record->RecordName = name;
    Record->nextNode = NULL;

    return true;
}


bool getChildren(tCategory* category, char* results)
{

    while(category->nextNode != NULL)
    {
        //Print immediate node successor and point to it.
        printf("%s -> %s", category->RecordParent, category->RecordName);
        category=(category->nextNode);
    }

    return true;
}


