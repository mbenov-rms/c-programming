---
title: Лекция 11 - Едносвързан Списък
category: новини
tags:
  - лекции
  - материали
---
[Линк към презентацията](https://drive.google.com/open?id=1Ul5qXQRbLzZPJ4Up2c2FdFsyaQ1JBkJ-bo2YUaqUBQw)

{% include presentation id="2PACX-1vRmh4vFVr4aw8l4n2-d9W6bZ7Ns2s0TZ4xDxjICTkbE6W6So7oZx-ogadcPlbn6CZs6wpYXWr2pYn_a/" %}

## А клас
```c
#include <stdlib.h>

struct node_t {
  int val;
  struct node_t* next;
};

struct list_t {
  //struct node_t* first;
  struct node_t* head;
  int size;
};

// For readability
void
insert(struct list_t* list, int val)
{
  //struct node_t new_node = {val, NULL};
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->val = val;
  new_node->next = NULL;

  struct node_t* curr = list->head;
  if(curr == NULL) {
    list->head = new_node;
    list->size = 1;
    return;
  }

  while(curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = new_node;
  list->size++;
}

int main() {
  struct list_t list1 = {NULL, 0};
  /*struct node_t n1 = {15, NULL};

  list1.head = &n1;
  list1.size++;

  struct node_t n2 = {25, NULL};
  list1.head -> next = &n2;
  list1.size++;

  struct node_t n3 = {35, NULL};
  list1.head -> next -> next = &n3;
  list1.size++;*/
  insert(&list1, 15);

  return 0;
}
```
