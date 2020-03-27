---
title: Лекция 16 - Двусвързан списък
category: новини
tags:
  - лекции
  - материали
---

## А и Б клас
```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  struct node_t* next;
  struct node_t* prev;
};

struct double_linked_list{
	struct node_t* head;
};

void init(struct double_linked_list* list){
	struct node_t *head = (struct node_t*)malloc(sizeof(struct node_t));
	head->next = head->prev = head;
	list->head = head;
}



void print_list(struct double_linked_list* list){
	struct node_t *iterator = list->head;
	if(iterator->next == iterator || iterator->prev == iterator){
		printf("The list is empty!\n");		
		return;
	}

	while(iterator->next != list->head){
		printf("%d\n", iterator->next->value);
		iterator = iterator->next;
	}
}

void add_after_head(struct double_linked_list* list, int val){
	
	struct node_t *head = list -> head;
	struct node_t *new_node = (struct node_t*)malloc(sizeof(struct node_t));
	new_node->next = head->next;
	new_node->prev = head;
	head->next->prev = new_node;
	head->next = new_node;
	new_node->value = val;
}


int main(){
	struct double_linked_list list;
	init(&list);
	add_after_head(&list,7);
	add_after_head(&list,2);
	add_after_head(&list,3);

	print_list(&list);
	
}
```
## В клас
```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int val;
	struct node_t *next;
	struct node_t *prev;
};


struct double_linked_list {
	struct node_t *head;
};


void init(struct double_linked_list *list){
	struct node_t *head = (struct node_t*)malloc(sizeof(struct node_t));
	head->next = head->prev = head;
	list->head = head;
}

void print(struct double_linked_list *list){
	struct node_t *curr = list->head;
	if(curr->next == list->head && curr->prev == list->head){
		printf("This list is EMPTY!\n");
		return;
	}

	while(curr->next != list->head){
		printf("%d\n",curr->next->val);
		curr = curr->next;
	}

}

void add(struct double_linked_list *list, int value){
	struct node_t *new_element = (struct node_t*)malloc(sizeof(struct node_t));
	struct node_t *head = list->head;

	new_element->next = head->next;
	head->next->prev = new_element;
	new_element->prev = head;
	head->next = new_element;
	new_element->val = value;
}


int main(){
	struct double_linked_list list;
	init(&list);
	print(&list);
	add(&list,7);
	add(&list,2);
	add(&list,3);
	print(&list);
	return 0;
}
```
