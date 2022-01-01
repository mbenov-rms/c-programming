---
title: Лекция 10 - Свързан Списък
category: новини
tags:
  - лекции
  - материали
---

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

  new_node->next = list->head;
  list->head = new_node;
}

int remove_first(struct list_t* list, int* result) {
  if(list->head == NULL) {
    return 0;
  }

  *result = list->head->data;
  struct node_t* old_head = list->head;
  list->head = old_head->next;
  free(old_head);
  return 1;
}

void insert_back(struct list_t* list, int value) {
  if(list->head == NULL) {
    insert(list, value);
    return;
  }

  struct node_t* last_node = list->head;

  while(last_node->next != NULL) {
    last_node = last_node->next;
  }

  struct node_t* new_node = malloc(sizeof(struct node_t));

  new_node->data = value;
  new_node->next = NULL;

  last_node->next = new_node;
}

// Функция, която разделя списък на 2 еднакво дълги части и връща указател към втората.
struct list_t* split_list(struct list_t* list) {
  if(list->head == NULL) {
    return NULL;
  }

  int i = 1;
  struct node_t* node = list->head;
  for(; node->next != NULL; i++) {
    node = node->next;
  }
  printf("%d\n", i);

  int i2 = 1;
  node = list->head;
  for(;i2 < i/2; i2++) {
    node = node->next;
  }
  // 0 1 5
  // 1 2 7
  // 2 3 9
  // 3 4 11

  struct list_t* second_list = malloc(sizeof(struct list_t));

  second_list->head = node->next;
  node->next = NULL;

  return second_list;
}

void print_list(struct list_t* list) {
  if(!list->head) {
    puts("It's empty");
    return;
  }

  int i = 0;
  struct node_t* node = list->head;
  while(node!=NULL) {
    printf("[%d] %d\n", i++, node->data);
    node = node->next;
  }
}

int main() {
  struct list_t list1 = {NULL};

  insert(&list1, 11);
  insert(&list1, 9);
  insert(&list1, 7);
  insert(&list1, 5);

  puts("List 1");
  print_list(&list1);

  struct list_t* list2 = split_list(&list1);

  puts("List 1");
  print_list(&list1);
  puts("List 2");
  print_list(list2);

  return 0;
}
```
