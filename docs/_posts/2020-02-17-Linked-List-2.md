---
title: Лекция 12 - Едносвързан Списък
category: новини
tags:
  - лекции
  - материали
---

## А клас
```c
#include <stdlib.h>
#include <stdio.h>

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

void print_list(struct list_t* list) {
  struct node_t* curr = list->head;

  /*while(curr != NULL) {
    printf("%d\n", curr->val);
    curr = curr->next;
  }*/

 for(int i=0; i < list->size; i++) {
 printf("%p %d\n", curr, curr->val);
    curr = curr->next;
  }
  printf("== Reached the end! ==\n");
}

void remove_by_index(struct list_t* list, int index) {
  if(index > list->size - 1) {
 printf("== Invalid index! ==\n");  
   return;
  }

  if(index == 0) {
struct node_t* to_remove=list->head;
    list->head = to_remove->next;
    free(to_remove);
    list->size--;
    return;
  }

  struct node_t* curr = list->head;
  for(int i=0; i < index - 1; i++) {
    curr = curr->next;
  }
//  curr->next = curr->next->next;
struct node_t* to_remove=curr->next;
  curr->next = to_remove->next;
  free(to_remove);
  list->size--;
}

struct node_t* get(struct list_t* list, int val) {
  int count = 0;
  struct node_t* node = list->head;
  while(count < list->size) {
    if(node->val == val) {
      return node;
    }
    node = node->next;
    count++;
  }
  return NULL;
}

void remove_by_value(struct list_t* list, int val) {
  struct node_t* curr = list->head;

  while(curr->next != NULL) {
    if(curr->next->val == val) {
struct node_t* to_remove=curr->next;
      curr->next = to_remove->next;
      free(to_remove);
      list->size--;
    }
    curr = curr->next;
  }
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
  insert(&list1, 25);
  insert(&list1, 35);
  insert(&list1, 45);
  insert(&list1, 35);

  print_list(&list1);

struct node_t* found=get(&list1,65);
  printf("%p\n", found);
  found=get(&list1,35);
  printf("%p\n", found);

  //remove_by_index(&list1, 2);
  remove_by_value(&list1, 35);
  print_list(&list1);

  //remove_by_index(&list1, 0);
  //print_list(&list1);

  //remove_by_index(&list1, 6);
  //print_list(&list1);
  return 0;
}
```

## Б клас
```c
```

## В клас
```c
```
