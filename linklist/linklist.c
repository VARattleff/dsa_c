#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

LinkList* createList() 
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void appendNode(LinkList* list, void* data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->prevNode = list->tail;

    if (list->tail) 
    {
        list->tail->nextNode = newNode;
    } else 
    {
        list->head = newNode; 
    }
    list->tail = newNode;
}

void prependNode(LinkList* list, void* data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prevNode = NULL;
    newNode->nextNode = list->head;

    if (list->head) 
    {
        list->head->prevNode = newNode;
    } else 
    {
        list->tail = newNode; 
    }
    list->head = newNode;
}

void deleteNode(LinkList* list, Node* node) 
{
    if (!node) return;
    if (node->prevNode) 
    {
        node->prevNode->nextNode = node->nextNode;
    } else 
    {
        list->head = node->nextNode; 
    }

    if (node->nextNode) 
    {
        node->nextNode->prevNode = node->prevNode;
    } else 
    {
        list->tail = node->prevNode; 
    }

    free(node);
}

void displayList(LinkList* list, void (*printData)(void*)) 
{
    Node* currentNode = list->head;
    while (currentNode) 
    {
        printData(currentNode->data);
        currentNode = currentNode->nextNode;
    }
}

void freeList(LinkList* list) 
{
    Node* currentNode = list->head;
    while (currentNode) 
    {
        Node* nextNode = currentNode->nextNode;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
}