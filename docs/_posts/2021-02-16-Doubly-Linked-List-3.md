---
title: Лекция 13 - Двусвързан Списък 3
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

typedef struct list_t list_t;
typedef struct node_t node_t;



void print_list(struct list_t* list) {
  struct node_t* curr = list->head;
  int counter = 1;
  printf("size == %d\n", list->size);

  while(curr != NULL) {
    printf("[%d] %d\n", counter++, curr->value);
    curr = curr->next;
  }
}


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

  //printf("%d %d\n", counter, curr->value);

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
	
    for(struct node_t* node = list->head; node != NULL && node->next != NULL; node = node->next) {
	
	  printf("current %d\n", node->value); 	
	
      if(node->value > node->next->value) {
        // swap
        struct node_t* left = node;
        struct node_t* right = node->next;
		
		
		printf("swapping %d %d\n", left->value, right->value); 	

        if(left->prev != NULL)
          left->prev->next = right; // 1
        left->next = right->next; // 2
        right->next = left; // 3

        if(left->next != NULL) 
          left->next->prev = left; // 1
        right->prev = left->prev; // 2
        left->prev = right; // 3

		print_list(list);

        sorted = 0;
      } 
    }
  }
}

list_t* filter_single_digit_numbers(list_t* source) {
	list_t* result = malloc(sizeof(list_t));
	result->head = NULL;
	result->size = 0;
	
	node_t* current = source->head;
	while (current != NULL) {
		if (current->value < 10 && current->value > -10) {
			push_back(result, current->value);
		}
		current = current->next;
	}
	
	return result;
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
  
  list_t* filtered = filter_single_digit_numbers(&my_list);
  print_list(filtered);

  return 0;
}
```

#### Б клас
```c
```

#### В клас
```c
```
