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
