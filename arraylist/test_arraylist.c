#include <stdio.h>
#include "arraylist.h"

int main() 
{
    ArrayList* list = alst_create();

    alst_add(list, 1);
    alst_add(list, 2);
    alst_add(list, 3);
    printf("Size: %d\n", alst_size(list)); 

    printf("Element at index 1: %d\n", alst_get(list, 1)); 

    alst_remove(list);
    printf("Size after remove: %d\n", alst_size(list)); 

    alst_insert_index(list, 1, 99);
    printf("Element at index 1 after insert: %d\n", alst_get(list, 1)); 

    alst_set(list, 1, 42);
    printf("Element at index 1 after set: %d\n", alst_get(list, 1)); 

    alst_clear(list);
    printf("Size after clear: %d\n", alst_size(list)); 

    alst_add(list, 100);
    alst_add(list, 200);
    alst_add(list, 300);
    printf("Size after adding elements again: %d\n", alst_size(list)); 
    
    alst_remove_index(list, 1);
    printf("Size after remove index 1: %d\n", alst_size(list)); 
    printf("Element at index 1 after remove index: %d\n", alst_get(list, 1)); 
    
    alst_free(list);

    return 0;
}
