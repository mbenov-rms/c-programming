---
title: Лекция 11 - Едносвързан Списък
category: новини
tags:
  - лекции
  - материали
---
[Линк към презентацията](https://drive.google.com/open?id=1Ul5qXQRbLzZPJ4Up2c2FdFsyaQ1JBkJ-bo2YUaqUBQw)

{% include presentation id="2PACX-1vRmh4vFVr4aw8l4n2-d9W6bZ7Ns2s0TZ4xDxjICTkbE6W6So7oZx-ogadcPlbn6CZs6wpYXWr2pYn_a" %}

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

## Б клас
```c
#include <stdio.h>
#include <stdlib.h>

struct node_t{
    int value;
    struct node_t* next;
};

struct node_t init(int start_value){
    struct node_t head;
    head.value = start_value;
    head.next = NULL;
    return head;	
}

void add_element(struct node_t *head, int value){

    head->next = malloc(sizeof(struct node_t));
    head->next-> value = value;
    head->next -> next = NULL;
}

void delete_element(struct node_t *head){
    struct node_t *tmp = head->next->next;
    free(head->next);
    head->next  = tmp;
}

int main(){

    struct node_t head = init(0);
    add_element(&head,5);
    printf("%d\n",head.value);
    printf("%d\n",head.next->value);
    add_element(head.next,7);
    printf("%d\n",head.next->value);

    free(head.next);
    return 0;
}
```

## В клас
```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
    int value;
    struct node_t* next;
};

struct node_t* init(int value) {
    struct node_t* new_node = malloc(sizeof(struct node_t));
    new_node -> next = NULL;
    new_node -> value = value;

    return new_node;
}

void insert(struct node_t* node, int value) {
    struct node_t* new_node = init(value);
    node -> next = new_node;
}

void print(struct node_t* head) {
    struct node_t* curr = head;

    while(curr != NULL) {
        printf("[%p] %d (%p)\n", curr, curr -> value, curr -> next);
        curr = curr -> next;
    }
}

void insert_middle(struct node_t* prev, int value) {
    struct node_t* new_node = init(value);
    new_node -> next = prev -> next;
    prev -> next = new_node;
}

void remove_middle(struct node_t* prev) {
    struct node_t* middle = prev -> next;
    struct node_t* next = middle -> next;

    middle -> next = NULL;
    prev -> next = next;

    free(middle);
}

int main() {
    struct node_t* n1 = init(15);
    //struct node_t* n2 = malloc(sizeof(struct node_t));
    //	struct node_t* n3 = malloc(sizeof(struct node_t));

    //	n1->value = 15;
    //n2->value = 25;
    //	n3->value = 35;

    //n1->next = n2;
    //	n2->next = n3;

    insert(n1, 25);
    insert(n1 -> next, 35);

    insert_middle(n1, 45);
    insert_middle(n1, 45);
    insert_middle(n1, 45);
    insert_middle(n1, 45);

    //	printf("%d %d %d\n", n1->value, n2->value, n3->value);
    //	printf("%p %p %p\n", n1->next, n2->next, n3->next);

    //printf("%d %d %d\n", n1->value, n1->next->value, n1->next->next->value);
    //printf("%p %p %p\n", n1->next, n1->next->next, n1->next->next->next);

    print(n1);

    free(n1->next->next);
    free(n1->next);
    free(n1);

    return 0;
}
```
