//criado so para testes, tem que apagar depois

#include <stdio.h>
#include "array.h"
#include "linkedlist.h"

int main() {
    Array arr = array_create(sizeof(int), 3);
    LinkedList ls = list_create(sizeof(int));

    int x = 10, y = 20, z = 30;

    array_set(&arr, 0, &x);
    array_set(&arr, 1, &y);
    array_set(&arr, 2, &z);

    list_push_back(&ls, &x);

    int valor = LIST_GET(int, &ls, 0);

    printf("%d\n", LIST_GET(int, &ls, 0));
    printf("%d\n", ARRAY_GET(int, &arr, 2)); 

    array_free(&arr);
    list_free(&ls);
    return 0;
}
