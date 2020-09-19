---
title: Лекция 14 - Динамична памет/едносвързан списък
category: лекции
---
A и Б клас
[Линк към презентацията за списък](https://docs.google.com/presentation/d/1akNB8yN82wpF_FbxIwPg8xvTnVV1nZIURuUYVWMAWI8/edit#slide=id.p)

В и Г клас
[Линк към презентацията за динамична памет](https://docs.google.com/presentation/d/1UY1PWQDPMwTYUTFyWVVwbn0irq1ZeGUnQvgidkFS7V0/edit#slide=id.p)

## Задачи от час А

```c
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node_t init_list ()
{
  struct node_t head;

  head.next = NULL;

  return head;
}

void destroy_list (struct node_t head)
{
  struct node_t *temp = &head;
  struct node_t *del = head.next;

  while (temp->next != NULL)
    {
      temp = del->next;
      free (del);
      del = temp;
    }
  free (del);
}

int size (struct node_t head)
{
  int size = 0;
  struct node_t *temp = head.next;

  if (temp == NULL)
    {
      return 0;
    }

  while (temp->next != NULL)
    {
      temp = temp->next;
      ++size;
    }

  return size;
}

int empty (struct node_t head)
{
  return size (head) == 0;
}
```

## Задачи от час Б

```c
// main.c
#include <stdio.h>
#include "list.h"

int main() {

    struct list_t original = list_init(5);

    insert_last(&original, 4);
    insert_last(&original, 5);

    struct list_t l = list_copy(original);

    printf("%d %d %d\n", l.head->value, l.head->next->value, l.head->next->next->value);

    list_destroy(&l);
    list_destroy(&original);

    return 0;
}
```

```c
// list.c
#include "list.h"
#include <stdlib.h>

struct list_t list_init(int value) {
    struct list_t l;

    l.head = malloc(sizeof(struct node_t));

    l.head->value = value;
    l.head->next = NULL;

    return l;
}

void list_destroy(struct list_t *l) {
    struct node_t *current = l->head;
    struct node_t *tmp = current->next;

    while(current->next != NULL) {
        free(current);
        current = tmp;
        tmp = tmp->next;
    }

    free(current);
}

struct list_t list_copy(struct list_t original) {
    // check if list is empty

    struct list_t copy = list_init(original.head->value);

    struct node_t *current = original.head->next;

    while(current != NULL) {
        insert_last(&copy, current->value);
        current = current->next;
    }

    return copy;
}

void insert_last(struct list_t *l, int value) {
    struct node_t *new_node = malloc(sizeof(struct node_t));

    new_node->value = value;
    new_node->next = NULL;

    struct node_t *last = l->head;

    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}
```

```c
// list.h
#ifndef __LIST_H__
#define __LIST_H__

struct list_t {
    struct node_t *head;
};

struct node_t {
    int value;
    struct node_t *next;
};

struct list_t list_init(int);
void list_destroy(struct list_t*);
struct list_t list_copy(struct list_t);

void insert_last(struct list_t*, int);
#endif
```

## Задачи от час В и Г

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("err\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }

    // printf("%p\n", &n);
    // printf("%p\n", arr);

    free(arr);

    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int i = 0;
    int n;
    int res = scanf("%d", &n);
    while(res != EOF) {
        printf("%d - %d\n", res, n);
        res = scanf("%d", &n);
    }

    printf("%d %d", res, EOF);

    return 0;
}
```

```c
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    int size = 2;
    int *arr = malloc(size * sizeof(int));
    int n;

    while(scanf("%d", &n) != EOF) {
/*        if (i == size) {
            int *tmp = malloc(size * sizeof(int));
            for(int k = 0; k < size; k++){
                tmp[k] = arr[k];
                printf("tmp = i%d\n", arr[k]);
            }

            size *= 2;
            free(arr);
            arr = malloc(size * sizeof(int));
            memcpy(arr, tmp, i * sizeof(int));

            free(tmp);
        } // manual realloc */

        size *= 2;

        arr = realloc(arr, size * sizeof(int));

        arr[i] = n;
        i++;
    }

    for (int k = 0; k < i; k++) {
        printf("%d\n", arr[k]);
    }

    free(arr);
    return 0;
}
```
