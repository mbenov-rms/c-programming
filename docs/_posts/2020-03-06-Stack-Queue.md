---
title: Лекция 14 - Стeк и Опашка
category: новини
tags:
  - лекции
  - материали
---

## А клас - Стек
```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int val;
  struct node_t* next;
};

struct stack_t {
  struct node_t* head;
  int size;
};

void print_stack(struct stack_t* list) {
  struct node_t* curr = list->head;

 for(int i=0; i < list->size; i++) {
 printf("%p %d\n", curr, curr->val);
    curr = curr->next;
  }
  printf("== Reached the end! ==\n");
}

void add(struct stack_t* stack, int val) {
    struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->val = val;
  new_node->next = NULL;

  if(stack->head == NULL) {
    stack->head = new_node;
  } else {
   struct node_t* curr = stack->head;
   while(curr->next != NULL) {
    curr = curr->next;
   }
   curr->next = new_node;
  }
  stack->size++;
}

void remove_stack(struct stack_t* stack) {
  if(stack->size <= 0) {
    return;
  }

  if(stack->size == 1) {
    free(stack->head);
    stack->head = NULL;
  } else {
   struct node_t* curr = stack->head;
   for(int i=0;i<stack->size-1;i++) {
      curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
  }
  stack->size--;
}

int main() {
  struct stack_t stack = {NULL, 0};

  for(int i=0; i<10; i++) {
    add(&stack, i);
  }
  print_stack(&stack);

  remove_stack(&stack);
  remove_stack(&stack);
  remove_stack(&stack);
  print_stack(&stack);

  return 0;
}
```

## А клас - Опашка
```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int val;
  struct node_t* next;
};

struct queue_t {
  struct node_t* head;
  int size;
};

void print_queue(struct queue_t* list) {
  struct node_t* curr = list->head;

 for(int i=0; i < list->size; i++) {
 printf("%p %d\n", curr, curr->val);
    curr = curr->next;
  }
  printf("== Reached the end! ==\n");
}

void add(struct queue_t* queue, int val) {
    struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->val = val;
  new_node->next = NULL;

  if(queue->head == NULL) {
    queue->head = new_node;
  } else {
   struct node_t* curr = queue->head;
   while(curr->next != NULL) {
    curr = curr->next;
   }
   curr->next = new_node;
  }
  queue->size++;
}

void remove_queue(struct queue_t* queue) {
  if(queue->size == 0){ return; }

  struct node_t* new_head = queue->head;
  queue->head = new_head->next;
  free(new_head);
  queue->size--;
}

int main() {
  struct queue_t queue = {NULL, 0};

  for(int i=0; i<10; i++) {
    add(&queue, i);
  }
  print_queue(&queue);

  remove_queue(&queue);
  remove_queue(&queue);
  remove_queue(&queue);
  print_queue(&queue);

  return 0;
}
```

## А клас - Стек с динамичен масив
```c
#include <stdlib.h>
#include <stdio.h>

struct stack_t {
  int* items;
  int size;
};

void add(struct stack_t* stack, int val) {
  if(stack->size == 0) {
   stack->items = malloc(sizeof(int));
  } else {
    stack->items = realloc(stack->items, sizeof(int) * (stack->size + 1));
  }
  stack->items[stack->size] = val;
  stack->size++;
}

void print_stack(struct stack_t* stack) {
  for(int i=0; i<stack->size; i++) {
    printf("%d\n", stack->items[i]);
  }
}

int main() {
  struct stack_t stack = {NULL, 0};

  for(int i=0; i<10; i++) {
    add(&stack, i);
  }
  print_stack(&stack);

  /*remove_stack(&stack);
  remove_stack(&stack);
  remove_stack(&stack);
  print_stack(&stack);*/

  return 0;
}
```

## Б клас
```c
```

## В клас
```c
```
