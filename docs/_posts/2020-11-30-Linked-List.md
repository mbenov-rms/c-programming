---
title: Лекция 08 - Свързан Списък
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/1b1GwnQOicopWGk9KqBYS9PeWQoKBE31-eE0OxiOUPuA/)

{% include presentation id="2PACX-1vTxg9BfcMDaAVRlRcAozs1Hgo5Z-5xJWTtVpgsTGXeBlNpPjJJn9YCewWZ5rDrZRbVyqCGT8kERgm1N" %}

### Код от час
```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int data;
  struct node_t* next;
};

struct list_t {
  struct node_t* head;
};

void insert(struct list_t* list, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));

  new_node->data = value;
//  new_node->next = NULL;

  new_node->next = list->head;
  list->head = new_node;
}

int remove_first(struct list_t* list, int* result) {
  if(list->head == NULL) {
    return 0;
  }

 // int value = list->head->data;
  *result = list->head->data;
  struct node_t* old_head = list->head;
  list->head = old_head->next;
  free(old_head);
  //return value;
  return 1;
}

int main() {
  struct node_t second = {5, NULL};
  struct node_t first = {4, &second};
  struct node_t third = {7, NULL};

  //first.next = &second;
  second.next = &third;

  /*printf("%d %d %d\n", first.data, second.data, third.data);
  printf("%p %p %p\n", first.next, second.next, third.next);
  printf("%d %d\n", first.next->data, first.next->next->data);*/

  struct list_t my_list = {NULL};
  //my_list.head = &first;

  insert(&my_list, 13);
  insert(&my_list, 18);

  struct node_t* tmp = my_list.head; // &first;
  while(tmp != NULL) {
    printf("%p %d %p\n", tmp, tmp->data, tmp->next);
    tmp = tmp->next;
  }

  int result_from_remove = 0;
  while(remove_first(&my_list, &result_from_remove)) {
    printf("%d\n", result_from_remove);
  }
  /*printf("%d\n", remove_first(&my_list));
  printf("%d\n", remove_first(&my_list));
  printf("%d\n", remove_first(&my_list));
  printf("%d\n", remove_first(&my_list));
  printf("%d\n", remove_first(&my_list));
  printf("%d\n", remove_first(&my_list));
  printf("%d\n", remove_first(&my_list));*/

  tmp = my_list.head;
  while(tmp != NULL) {
    printf("%p %d %p\n", tmp, tmp->data, tmp->next);
    tmp = tmp->next;
  }

  return 0;
}
```
