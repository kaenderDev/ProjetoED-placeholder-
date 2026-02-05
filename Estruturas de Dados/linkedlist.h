#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <string.h>


typedef struct Node {       // nó da lista
    void* data;
    struct Node* next;
} Node;

typedef struct {            // a lista
    Node* head;
    size_t element_size;
    size_t size;
} LinkedList;


LinkedList list_create(size_t element_size);

void list_push_front(LinkedList* list, void* value);  //percorre a lista ate o inicio

void list_push_back(LinkedList* list, void* value);   //percorre a lista ate o fim

void* list_get_ptr(LinkedList* list, size_t index);   //percorre a lista ate o indice e retorna o ponteiro

void list_remove(LinkedList* list, size_t index);     //remove um nó da lista

void list_free(LinkedList* list);                     //libera todos os nós


#define LIST_GET(type, list, index) (*(type*)list_get_ptr(list, index)) //macro para typecast
                                                     
#endif
