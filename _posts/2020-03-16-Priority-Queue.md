---
title: Лекция 15 - Приоритетна опашка
category: новини
tags:
  - лекции
  - материали
---

## А и Б клас
```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int value;
  int priority;
};

struct node_t* push(struct node_t* queue, int size, struct node_t new_node) {
  //struct node_t queue[10];
  queue = realloc(queue, sizeof(struct node_t) * (size + 1));
  //queue[size] = new_node;

  int is_found = 0;
  for(int i=0; i<size; i++) {
    if(queue[i].priority > new_node.priority) {
      // insert here
      is_found = 1;
      for(int j=size; j>i; j--) {
        queue[j] = queue[j-1];
      }

      queue[i] = new_node;

      break;
    }
  }

  if(!is_found) {
    queue[size] = new_node;
  }

  return queue;
}

void print_queue(struct node_t* queue, int size) {
  for(int i=0; i<size; i++) {
    printf("[%d] value=%d priority=%d\n", i, queue[i].value, queue[i].priority);
  }
}

int main() {
  struct node_t* queue = NULL;

  struct node_t node1 = {10, 2};
  struct node_t node2 = {20, 1};
  struct node_t node3 = {30, 4};
  struct node_t node4 = {30, 1};

  int size = 0;

  queue = push(queue, size++, node1);
  queue = push(queue, size++, node2);
  queue = push(queue, size++, node3);
  queue = push(queue, size++, node4);

  print_queue(queue, size);

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
  int priority;
};

struct queue_t {
  struct node_t* head;
  int size;
};
// 2 - 4 - 1 - 3 - 1
void push(struct queue_t* queue, struct node_t* new_node) {
  if(queue->head == NULL) {
//if(queue->size == 0) {
    queue->head = new_node;
    new_node->next = NULL;
    queue->size = 1;
    //return;
  } else {
    if(queue->head->priority > new_node->priority) {
      new_node->next = queue->head;
      queue->head = new_node;
    } else {
      struct node_t* curr = queue->head;
      printf("new_node(%d)\n", new_node->priority);
      while(curr->priority < new_node->priority && curr->next != NULL) {
        curr = curr->next;
      }
      printf("curr(%d,%p)\n", curr->priority, curr->next);

      new_node->next = curr->next;
      curr->next = new_node;
      /*if(curr->next == NULL) {
        curr->next = new_node;
        new_node->next = NULL;
      } else {
        new_node->next = curr->next;
        curr->next = new_node;
      }*/
     // if(curr->next != NULL) {

      /*} else {
        curr->next = new_node;
        new_node->next = NULL;
      }*/
    }
    /*struct node_t* curr = queue->head;
    while(curr->next != NULL) {
      curr = curr->next;
    }

    curr->next = new_node;
    new_node->next = NULL;*/
    queue->size++;
  }
}

void print_queue(struct queue_t* queue) {
  struct node_t* curr = queue->head;
  while(curr != NULL) {
    printf("[%p] value=%d priority=%d next=%p\n", curr, curr->value, curr->priority, curr->next);
    curr = curr->next;
  }
}

int main() {
  struct queue_t queue = {NULL, 0};

  struct node_t node1 = {10, NULL, 2};
  struct node_t node2 = {40, NULL, 1};
  struct node_t node3 = {30, NULL, 3};
  struct node_t node4 = {20, NULL, 1};
  struct node_t node5 = {70, NULL, 4};

  push(&queue, &node1);
  push(&queue, &node5);
  push(&queue, &node2);
  push(&queue, &node3);
  push(&queue, &node4);

  print_queue(&queue);

  return 0;
}
```
