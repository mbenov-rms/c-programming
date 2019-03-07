---
title: Лекция 16 - Упражнение върху динамична памет
category: новини
tags:
  - лекции
---


## Вектор

## В клас
```c
#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 5

struct vector_t {
	int capacity;
	int size;
	int *data;
};

struct vector_t init();
void destroy(struct vector_t*);
void add(struct vector_t*, int);
void resize(struct vector_t*);
int get(struct vector_t, int);
void add_front(struct vector_t*, int);
void add_at(struct vector_t*, int, int);

int main() {

	struct vector_t v = init();

	add(&v, 1);
	add(&v, 2);
	add(&v, 3);
	add(&v, 4);
	add(&v, 5);
	add(&v, 6);
	add(&v, 7);

	printf("%d\n", get(v, 6));
	add(&v, 8);
	printf("%d\n", get(v, 7));
	add_front(&v, 10);
	printf("%d %d\n", get(v, 0), v.size);
	add_at(&v, 100, 11);
	printf("%d\n", v.size);
	add_at(&v, 0, 11);
	printf("%d %d\n", get(v, 0), v.size);
	
	destroy(&v);

	return 0;
}

struct vector_t init() {
	struct vector_t vector;	
	vector.capacity = INIT_CAPACITY;
	vector.data = malloc(INIT_CAPACITY * sizeof(int));
	vector.size = 0;

	return vector;
}

void add(struct vector_t *vector, int elem) {
	add_at(vector, vector->size, elem);
}

void add_front(struct vector_t *vector, int elem) {
	add_at(vector, 0, elem);
}

void add_at(struct vector_t *vector, int position, int elem) {
	if (vector->data == NULL) {
		return;
	}

	if (vector->capacity == vector->size) {
		resize(vector);
	}

	if (position < 0 || position > vector->size) {
		return;	
	}

	// this was wrong -> for (int i = position; i > 0; i--) { 
	for (int i = vector->size; i > position; i--) {
		vector->data[i] = vector->data[i - 1];
	}

	vector->data[position] = elem;
	vector->size++;	
	
}

int get(struct vector_t vector, int index) {
	if (index > vector.size || index < 0) {
		return -1;
	}

	return vector.data[index];
}

void resize(struct vector_t *vector) {
	int *tmp = vector->data;
	
	vector->capacity *= 2;
	vector->data = malloc(vector->capacity * sizeof(int));

	for (int i = 0; i < vector->size; i++) {
		vector->data[i] = tmp[i];
	}

	free(tmp);
}

void destroy(struct vector_t *vector) {
	free(vector->data);
	vector->data = NULL;

	vector->capacity = 0;
	vector->size = 0;
}
```
