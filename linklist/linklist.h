#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node {
    struct Node* nextNode;   
    struct Node* prevNode;   
    void* data;              
} Node;

typedef struct LinkList {
    Node* head;              
    Node* tail;              
} LinkList;

LinkList* createList();
void appendNode(LinkList* list, void* data);
void prependNode(LinkList* list, void* data);
void deleteNode(LinkList* list, Node* node);
void displayList(LinkList* list, void (*printData)(void*));
void freeList(LinkList* list);

#endif 