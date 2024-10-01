#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

#pragma region defines

#define GROWTH_FACTOR 1.5      
#define MIN_CAPACITY 10        

// Makro til at tjekke om et indeks er inden for gyldige grænser
#define CHECK_BOUNDS(list, index) \
    do { \
        if (index < 0 || index >= list->size) \
        { \
            printf("Fejl: Index er udenfor rækkevidde.\n"); \
            break; \
        } \
    } while(0)

// Makro til at kontrollere og ændre størrelsen på arraylisten
#define CHECK_AND_RESIZE(list) \
    do { \
        if (list->size < list->capacity / 2 && list->capacity > MIN_CAPACITY) \
        { \
            alst_resize(list, list->capacity / 2); \
        } \
    } while(0)

#pragma endregion

// "static" intern funktion til filen til at ændre størrelsen på arraylisten 
static void alst_resize(ArrayList* list, int new_capacity) 
{
    if (new_capacity < MIN_CAPACITY) 
    {
        new_capacity = MIN_CAPACITY;
    }

    int* new_data = (int*)malloc(new_capacity * sizeof(int));
    if (new_data == NULL) 
    {
        printf("Fejl: Kunne ikke allokere hukommelse.\n");
        exit(1);  
    }

    memcpy(new_data, list->data, list->size * sizeof(int));
    free(list->data);  
    list->data = new_data;  
    list->capacity = new_capacity; 
}

ArrayList* alst_create() 
{
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList)); 
    list->size = 0;          
    list->capacity = MIN_CAPACITY; 
    list->data = (int*)malloc(list->capacity * sizeof(int)); 
    return list;  
}

void alst_add(ArrayList* list, int value) 
{
    if (list->size >= list->capacity) 
    {
        alst_resize(list, list->capacity * GROWTH_FACTOR); 
    }
    list->data[list->size++] = value;  
}

// 'inline' for at optimere ydeevnen ved at indlejre funktionen direkte i kaldestedet og reducere overhead fra funktionskald()
inline int alst_get(ArrayList* list, int index) 
{
    CHECK_BOUNDS(list, index);  
    return list->data[index];    
}

// 'inline' for at optimere ydeevnen ved at indlejre funktionen direkte i kaldestedet og reducere overhead fra funktionskald()
inline int alst_size(ArrayList* list) 
{
    return list->size;  
}

void alst_remove(ArrayList* list) 
{
    if (list->size > 0) 
    {
        list->size--;  
        CHECK_AND_RESIZE(list);
    }
}

void alst_remove_index(ArrayList* list, int index) 
{
    CHECK_BOUNDS(list, index); 

    for (int i = index; i < list->size - 1; i++) 
    {
        list->data[i] = list->data[i + 1];
    }

    list->size--; 

    CHECK_AND_RESIZE(list);
}

void alst_insert_index(ArrayList* list, int index, int value) 
{
    if (index < 0 || index > list->size) 
    {
        printf("Fejl: Index er udenfor rækkevidde.\n");
        exit(1);
    }

    if (list->size >= list->capacity) 
    {
        alst_resize(list, list->capacity * 2); 
    }

    for (int i = list->size; i > index; i--) 
    {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = value; 
    list->size++; 
}

void alst_set(ArrayList* list, int index, int value) 
{

    if (index < 0 || index >= list->size) 
    {
        printf("Fejl: Index er udenfor rækkevidde.\n");
        exit(1);
    }
    list->data[index] = value; 
}

void alst_clear(ArrayList* list) 
{
    list->size = 0; 
    alst_resize(list, MIN_CAPACITY); 
}

void alst_free(ArrayList* list) 
{
    free(list->data); 
    free(list); 
}