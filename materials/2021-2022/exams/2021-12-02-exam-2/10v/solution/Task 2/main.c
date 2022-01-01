#include <stdio.h>

#include "linked_list.h"

int main() {
    struct  node_t* list = add(NULL, 1);
    list = add(list, 2);
    list = add(list, 3);
    list = add(list, 4);
    list = add(list, 5);

    list = reverse(list);

    struct node_t* curr = list;
    while(curr != NULL) {
      printf("%d ", curr->value);
      curr = curr->next;
    }
    puts("");

    return 0;
}
