---
title: Лекция 12 - Двусвързан Списък 2
category: новини
tags:
  - лекции
  - материали
---

### Код от час

#### А клас
```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
  struct node_t* next;
  struct node_t* prev;
  int value;
};

struct list_t {
  struct node_t* head;
  int size;
};

void push_front(struct list_t* list, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  new_node->next = list->head; // 1

  new_node->prev = NULL; // 2
  if(list->head != NULL)
    list->head->prev = new_node; // 3

  list->head = new_node; // 4

  list->size++;
}

void push_back(struct list_t* list, int value) {
  if(list->head == NULL) {
    push_front(list, value);
    return;
  }

  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  new_node->next = NULL;

  /*if(list->head == NULL) {
    list->head = new_node;
    new_node->prev = NULL;
    return;
  }*/

  struct node_t* curr = list->head;
  while(curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = new_node;
  new_node->prev = curr;

  list->size++;
}

void insert_middle(struct list_t* list, int value) {
  if(list->head == NULL) {
    push_front(list, value);
    return;
  }

  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  struct node_t* curr = list->head;
  int counter = 0;
  while(counter < (list->size / 2) - 1) {
    curr = curr->next;
    counter++;
  }

  printf("%d %d\n", counter, curr->value);

  struct node_t* left = curr;
  struct node_t* right = curr->next;

  left->next = new_node;
  right->prev = new_node;

  new_node->next = right;
  new_node->prev = left;

  list->size++;
}

void pop_front(struct list_t* list) {
  if(list->head == NULL) { // list->size == 0
    return;
  }

  if(list->size == 1) {
    free(list->head);
    list->head = NULL;
    list->size--;
    return;
  }

  struct node_t* new_head = list->head->next;
  new_head->prev = NULL;
  free(list->head);
  list->head = new_head;
  list->size--;
}

void pop_back(struct list_t* list) {
  /*if(list->size == 0) {
    return;
  }

  if(list->size == 1) {
    free(list->head);
    list->head = NULL;
    list->size--;
    return;
  }*/
  if(list->size < 2) {
    pop_front(list);
    return;
  }

  struct node_t* new_tail = list->head;
  for(int i = 2; i < list->size; i++) {
    new_tail = new_tail->next;
    //printf("[%d] %d\n", i, new_tail->value);
  }

  free(new_tail->next);
  new_tail->next = NULL;
  list->size--;
}


void sort_list(struct list_t* list) {
  if(list->size < 2) {
    return;
  }


  struct node_t* node = list->head;

  /*for(i in 0; size - 1)
    for(j in i + 1; size)
      if arr[i] > arr[j]
        tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp

  while(!sorted)
    for(i in 0; size - 1)
      if(arr[i] > arr[i+1]
        swap()
        sorted = false*/
  int sorted = 0;
  while(!sorted) {
    sorted = 1;
    for(node = list->head; node->next != NULL; node = node->next) {
      if(node->value > node->next->value) {
        // swap
        struct node_t* left = node;
        struct node_t* right = node->next;

        if(left->prev != NULL)
          left->prev->next = right; // 1
        left->next = right->next; // 2
        right->next = left; // 3

        if(left->next != NULL)
          left->next->prev = left; // 1
        right->prev = left->prev; // 2
        left->prev = right; // 3

        sorted = 0;
      }
    }
  }
}

void print_list(struct list_t* list) {
  struct node_t* curr = list->head;
  int counter = 1;
  printf("size == %d\n", list->size);

  while(curr != NULL) {
    printf("[%d] %d\n", counter++, curr->value);
    curr = curr->next;
  }
}

int main() {
  struct list_t my_list = {NULL, 0};

  push_front(&my_list, 4);
  push_front(&my_list, 6);
  push_front(&my_list, 7);
  push_front(&my_list, 1);

  push_back(&my_list, 44);
  push_back(&my_list, 66);
  push_back(&my_list, 77);
  push_back(&my_list, 11);

  insert_middle(&my_list, 13);

  print_list(&my_list);

  //pop_front(&my_list);
  //print_list(&my_list);

  //pop_back(&my_list);
 // print_list(&my_list);

  sort_list(&my_list);
  print_list(&my_list);

  return 0;
}
```

#### Б клас
```c
```

#### В клас
```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int value;
  struct node_t* next;
  struct node_t* prev;
};

struct list_t {
  struct node_t* head;
  struct node_t* tail;
  int size;
};

void push_front(struct list_t* list, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  new_node->prev = NULL;
  if(list->head != NULL) {
    list->head->prev = new_node;
  } else {
    list->tail = new_node;
  }
  new_node->next = list->head;

  list->head = new_node;

  list->size++;
}

void push_back(struct list_t* list, int value) {
  if(!list->head) {
    push_front(list, value);
    return;
  }

  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  new_node->next = NULL;
  new_node->prev = list->tail;

  list->tail->next = new_node;
  list->tail = new_node;

  list->size++;
}

void print_list(struct list_t* list) {
  struct node_t* curr = list->head;
  int counter = 1;
  printf("size == %d\n", list->size);

  while(curr != NULL) {
    printf("[%d] %d\n", counter++, curr->value);
    curr = curr->next;
  }
}

void insert_middle(struct list_t* list, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  struct node_t* curr = list->head;
  int counter = 1;
  // s == 6; c = 0; i = 1
  // s == 6; c = 1; i = 2
  // s == 6; c = 2; i = 3
  // s == 6; c = 3; i = 4
  // s == 6; c = 4; i = 5
  while(counter < list->size / 2) {
    curr = curr->next;
    counter++;
  }
  //printf("%d %d\n", counter, curr->value);
  new_node->prev = curr;
  new_node->next = curr->next;

  curr->next->prev = new_node;
  curr->next = new_node;

  list->size++;
}

void pop_front(struct list_t* list) {
  if(!list->head) { // list->size == 0
    return;
  }

  if(!list->head->next) { // list->size == 1
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return;
  }

  list->head = list->head->next;
  free(list->head->prev);
  list->head->prev = NULL;
  list->size--;
}

void pop_back(struct list_t* list) {
  if(list->size < 2) {
    pop_front(list);
    return;
  }

  struct node_t* curr = list->tail;

  curr->prev->next = NULL;
  list->tail = curr->prev;
  free(curr);
  list->size--;
}

void swap_nodes(struct node_t* left, struct node_t* right) {
  struct node_t* next = right->next;

  if(left->prev != NULL)
    left->prev->next = right;

  right->next = left;
  right->prev = left->prev;
  left->next = next;
  left->prev = right;

  if(next != NULL)
    next->prev = left;
}

void sort_list(struct list_t* list) {
//  ot head vseki sus vseki i sravnqvame kakto kaza stefcho i smenqme mestata



  int not_sorted = 1;
  while(not_sorted) {
    not_sorted = 0;
    struct node_t* left = list->head;

    while(left->next != NULL) {
      /*if(curr->value > curr->next->value) {
        swap_nodes(curr, curr->next);
        if(curr == list->head)
          list->head = curr->prev;
        if(curr->next == list->tail)
          list->tail = curr;
      } else {
        curr = curr->next;
      }*/
      struct node_t* right = left->next;
      printf("%d %d\n", left->value, right->value);

      if(left->value > right->value) {
        not_sorted = 1;
        swap_nodes(left, right);
        if(left == list->head)
          list->head = right;
        if(right == list->tail)
          list->tail = left;

        struct node_t* tmp = left;
        left = right;
        right = tmp;
      }   

      left = left->next;
    }

  }

  /*for(int i = 0; i < arr.length - 1; i++) {
    for(int j = i + 1; j < arr.length; j++) {
      if(arr[i] > arr[j]) {
        swap()
      }
    }
  }*/
}

int main() {
  struct list_t my_list = {NULL, NULL, 0};

  push_front(&my_list, 10);
  push_front(&my_list, 7);
  push_front(&my_list, 103);

  push_back(&my_list, 5);
  push_back(&my_list, 12);

  insert_middle(&my_list, 18);

  print_list(&my_list);
  puts("\n\n");

  /*pop_front(&my_list);
  pop_back(&my_list);
  pop_back(&my_list);*/
  sort_list(&my_list);

  print_list(&my_list);

  return 0;
}
```
