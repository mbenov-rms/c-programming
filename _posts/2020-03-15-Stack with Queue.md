---
title: Лекция 15 - Стeк и Опашка
category: новини
tags:
  - лекции
  - материали
---

## Б и В клас - Стек и опашка
```c
#include <stdio.h>
#include <stdlib.h>


/*
This program is implementing STACK
The STACK is a structure with FILO organization
And QUEUE is a structure with FIFO organization
*/

struct node_t{
	struct node_t *prev;
	int value;
};

struct stack_t{
	struct node_t *last;
	int size;

};

struct stack_t init(){
		//struct stack_t stack = {NULL,0};
		struct stack_t stack;
		stack.last = NULL;
		stack.size = 0;
		return stack;
}

void add_element(struct stack_t *stack,int value){
	struct node_t *new_element = malloc(sizeof(struct node_t));
	new_element -> prev = stack->last;
	new_element -> value = value;
	stack->last = new_element;
	stack->size++;
}

void print_list(struct stack_t *stack){
	struct node_t *current = stack->last;
	for(int i = 0; i< stack->size; i++){
		printf("%d\n",current->value);
		current = current->prev;	
	}
}

void remove_element_from_queue(struct stack_t *queue){
	struct node_t *current = queue->last;
	for(int i=queue->size; i>1; i--){
		current = current->prev;
	}
	free(current->prev);
	current = NULL;
	queue->size--;
}

void remove_element(struct stack_t *stack){
	struct node_t *current = stack->last;
	stack->last = stack->last->prev;
	free(current);
	stack->size--;
}

int main(){
	struct stack_t stack= init();
	add_element(&stack,7);
	add_element(&stack,6);
	add_element(&stack,5);
	add_element(&stack,4);
	printf("===Before Remove===\n");
	print_list(&stack);
	remove_element(&stack);
	printf("===After Remove===\n");
	print_list(&stack);
	remove_element_from_queue(&stack);
	printf("===After QUEUE Remove===\n");
	print_list(&stack);
	

	return 0;
}
```
