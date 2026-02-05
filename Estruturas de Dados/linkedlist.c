#include "linkedlist.h"


LinkedList list_create(size_t element_size) {   //cria uma lista vazia
    LinkedList list;
    list.head = NULL;
    list.element_size = element_size;
    list.size = 0;
    return list;
}


static Node* create_node(void* value, size_t element_size) {  //cria um novo no 
    Node* node = malloc(sizeof(Node));
    node->data = malloc(element_size);
    memcpy(node->data, value, element_size);
    node->next = NULL;
    return node;
}


void list_push_front(LinkedList* list, void* value) {     //insere no inicio
    Node* node = create_node(value, list->element_size);
    node->next = list->head;
    list->head = node;
    list->size++;
}


void list_push_back(LinkedList* list, void* value) {      // insere no fim
    Node* node = create_node(value, list->element_size);

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }

    list->size++;
}


void* list_get_ptr(LinkedList* list, size_t index) {        // retorna um ponteiro do elemento do indice
    Node* current = list->head;

    for (size_t i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }

    return current ? current->data : NULL;
}


void list_remove(LinkedList* list, size_t index) {           // remove o elemento do indice
    if (list->head == NULL) return;

    Node* current = list->head;
    Node* prev = NULL;

    for (size_t i = 0; i < index && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->data);
    free(current);

    list->size--;
}


void list_free(LinkedList* list) {                       // libera toda a lista
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    list->head = NULL;
    list->size = 0;
}
