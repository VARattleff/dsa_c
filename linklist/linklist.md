# linklist opg 

## Kompilering

For at kompilere dette projekt på en ARM-baseret Mac M2, kan du bruge følgende kommando i terminalen:

```bash
mkdir -p build
gcc \
linklist/linklist.c  \
linklist/test_linklist.c \
-o build/linklist
```

## oversigt:

```c
LinkList* createList();
void appendNode(LinkList* list, void* data);
void prependNode(LinkList* list, void* data);
void deleteNode(LinkList* list, Node* node);
void displayList(LinkList* list, void (*printData)(void*));
void freeList(LinkList* list);   
```
## brug: 

Se filen test_linklist.c for at få en idé om funktionaliteten i programmet.



