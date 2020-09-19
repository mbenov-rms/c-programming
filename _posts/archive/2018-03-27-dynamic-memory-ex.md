---
title: Лекция 13 - Упражнение на Динамична памет/Побитови маски
category: лекции
---
A и Б клас
[Линк към презентацията за динамична памет](https://docs.google.com/presentation/d/14DoqKDPazpLymUM18l533Q8U_47sx615KabiMeWrC8Q/edit#slide=id.g1d932fb3cb_0_0)

## Задачи от час А

```c
#include <stdio.h>
#include <stdlib.h>

struct phonebook_entry_t
{
  char name[20];
  char number[10];
};

int main ()
{
  struct phonebook_entry_t *phonebook;
  int i = 0;

  phonebook = (struct phonebook_entry_t*)malloc (sizeof (struct phonebook_entry_t));

  while (fgets (phonebook[i].name, 20, stdin) != NULL)
    {
      if (fgets (phonebook[i].number, 10, stdin) == NULL)
        {
          printf ("Invalid input\n");
          free (phonebook);
          return -1;
        }
      ++i;
      phonebook = (struct phonebook_entry_t*)realloc (phonebook, sizeof (struct phonebook_entry_t) * (i + 1));
    }

  free (phonebook);

  return 0;
}
```

## Задачи от час Б

```c
// eof.c
#include <stdio.h>
#include <stdlib.h>

struct phonebook_entry_t {
    int age;
};

int main () {

    struct phonebook_entry_t *a;
    int count = 2;
    int index = 0;
    int tmp;

    a = malloc(count * sizeof(struct phonebook_entry_t));

    if (a == NULL) {
        return -1;
    }

    while (scanf("%d", &tmp) != EOF) {
        if (index == count) {
            // b[2]
            // a -> b
            // a[4]
            // b -> a
            count *= 2;

            a = realloc(a, sizeof(struct phonebook_entry_t) * count);

            // check if null
        }

        struct phonebook_entry_t entry = { tmp };

        a[index] = entry;
        index++;
    }

    for (int i = 0; i < index; i++) {
        printf("%d -> %d\n", i, a[i].age);
    }

    free(a);

    return 0;

}
```

```c
// vector.c
#include <stdio.h>
#include <stdlib.h>

struct vector_t {
    int capacity;
    int size;
    int *arr;
};

struct vector_t init();
void destroy(struct vector_t*);
void add_last(struct vector_t*, int);
int full(struct vector_t);
void expand(struct vector_t*);
int last(struct vector_t);
int empty(struct vector_t);
int pop(struct vector_t*);

int main() {
    struct vector_t v = init();

    printf("%d\n", last(v));
    add_last(&v, 5);
    printf("%d\n", last(v));
    add_last(&v, 7);
    printf("%d\n", last(v));
    add_last(&v, 9);
    printf("%d\n", pop(&v));
    printf("%d\n", last(v));

    destroy(&v);

    return 0;
}

int pop(struct vector_t *v) {
    v->size--;

    return v->arr[v->size];
}

int empty(struct vector_t v) {
    return v.size == 0;
}

int last(struct vector_t v) {
    if (empty(v)) {
         return -1;
    }

    return v.arr[v.size - 1];
}

int full(struct vector_t v) {
    return v.size == v.capacity;
}

void expand(struct vector_t *v) {
    v->capacity *= 2;

    v->arr = realloc(v->arr, sizeof(int) * v->capacity);
}

void add_last(struct vector_t *v, int item) {
    if (full(*v)) {
        expand(v);
    }

    v->arr[v->size] = item;
    v->size++;
}

void destroy(struct vector_t *v) {
    v->capacity = 0;
    v->size = 0;

    free(v->arr);

    v->arr = NULL;
}

struct vector_t init() {
    struct vector_t vector;
    vector.capacity = 2;
    vector.size = 0;
    vector.arr = malloc(sizeof(int) * vector.capacity);

    return vector;
}
```

## Задачи от час Г

```c
#include <stdio.h>

int new_pressed (int old_state, int new_state)
{
  int mask = old_state ^ new_state;
  return mask & new_state;
}

int released (int old_state, int new_state)
{
  int mask = old_state ^ new_state;
  return mask & old_state;
}

int main ()
{
  printf ("%d\n", new_pressed (10, 7));
  printf ("%d\n", released (10, 7));

  return 0;
}
```
