#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void printInt(void* data) 
{
    printf("%d ", *(int*)data);
}

int main() 
{
    LinkList* list = createList();

    int data1 = 10, data2 = 20, data3 = 30, data4 = 40;

    appendNode(list, &data1);
    appendNode(list, &data2);
    prependNode(list, &data3);
    appendNode(list, &data4);

    printf("Listen: ");
    displayList(list, printInt);
    printf("\n");

    freeList(list);

    return 0;
}