---
title: Лекция 17 - Свързан списък
category: новини
tags:
  - лекции
---

[Линк към презентацията](https://www.youtube.com/watch?v=dQw4w9WgXcQ)
{% include presentation id="2PACX-1vQZ4C_qftOEKGfuVzN3Yca1YFl8MJniDb-Ydi6VY6EFQDUrno_4v_2wh-St9AXZPhgvulmhPrBEBaEB" %}

## A клас

```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int data;
	struct node_t *next;
};

struct list_t {
	struct node_t *head;
};

struct list_t init_list();
void destroy_list(struct list_t*);
int size(struct list_t);
int empty(struct list_t);
void insert(struct list_t *, int);

int main () {
	struct list_t list = init_list();
	
	printf("empty = %d\n", empty(list));
	printf("size = %d\n", size(list));	
	insert(&list, 5);
	insert(&list, 7);

	printf("size = %d\n", size(list));
	insert(&list, 12);


	printf("%d %d %d\n", list.head->data, 
						 list.head->next->data, 
						 list.head->next->next->data);

	printf("size = %d\n", size(list));
	printf("empty = %d\n", empty(list));

	destroy_list(&list);

	printf("size = %d\n", size(list));
	printf("empty = %d\n", empty(list));
	return 0;
}

struct list_t init_list()  {
	struct list_t result;
	
	result.head = NULL;

	return result;	
}

void insert(struct list_t *l, int value) {
	struct node_t *tmp = l->head;

	struct node_t *new_node = malloc(sizeof(struct node_t));

	new_node->data = value;
	new_node->next = NULL;

	if (!empty(*l)) {
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}

		tmp->next = new_node;	
	} else {
		l->head = new_node;
	}


}

int size(struct list_t l) {
	int result = 0;

	for(struct node_t *node = l.head; 
		node != NULL; 
		result++, node = node->next);

	return result;
}

int empty(struct list_t l) {
	return l.head == NULL;
}

void destroy_list(struct list_t *l) {
	struct node_t *tmp = l->head;

	while(tmp != NULL) {
		struct node_t *free_node = tmp;
		tmp = tmp->next;

		free(free_node);
	}

	l->head = NULL;
}
```




## В клас

```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int data;
	struct node_t *next;
};

struct list_t {
	struct node_t *head;
};

struct list_t init_list();
void destroy_list(struct list_t*);
void destroy_list_r(struct node_t*);
void insert(struct list_t*, int);

int main() {
	struct list_t l = init_list();

	insert(&l, 5);
	insert(&l, 7);
	insert(&l, 12);

	destroy_list_r(l.head);

	return 0;
}

struct list_t init_list() {
	struct list_t result;	

	result.head = NULL;

	return result;
}

void insert(struct list_t *l, int value) {
	struct node_t *new_node = malloc(sizeof(struct node_t));
	new_node->data = value;
	new_node->next = NULL;

	struct node_t *tmp = l->head;
	if (tmp == NULL) {
		l->head = new_node;
		return;
	}

	while(tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = new_node;
}

void destroy_list(struct list_t *list) {
	struct node_t *tmp = list->head;
	
	while (tmp != NULL) {
		struct node_t *node = tmp;

		tmp = tmp->next;
		free(node);		
	}

	// WE FORGOT
	list->head = NULL;
}

void destroy_list_r(struct list_t *l) {
	destroy_nodes_r(l->head);

	l->head = NULL;
}
void destroy_nodes_r(struct node_t *node) {
	if (node == NULL) {
		return;
	}
	printf("BEFORE %d\n", node->data);
	destroy_nodes_r(node->next);
	printf("AFTER %d\n", node->data);
	free(node);
}
```
