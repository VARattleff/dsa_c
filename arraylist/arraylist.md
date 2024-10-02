# arraylist opg 

## Kompilering

For at kompilere dette projekt på en ARM-baseret Mac M2, kan du bruge følgende kommando i terminalen:

```bash
mkdir -p build
gcc \
arraylist/arraylist.c  \
arraylist/test_arraylist.c \
-o build/arraylist
```

## oversigt:

```c
ArrayList* alst_create();                   
void alst_add(ArrayList* list, int value);  
int alst_get(ArrayList* list, int index);   
int alst_size(ArrayList* list);             
void alst_remove(ArrayList* list);          
void alst_remove_index(ArrayList* list, int index);
void alst_insert_index(ArrayList* list, int index, int value); 
void alst_set(ArrayList* list, int index, int value); 
void alst_clear(ArrayList* list);           
void alst_free(ArrayList* list);       
```
## brug: 

Se filen test_arraylist.c for at få en idé om funktionaliteten i programmet.

## ekstra:

Der er tilføjet kommentarer til de elementer, som ligger uden for det nuværende pensum, for eksempel 'define macro', 'static' og 'inline'.