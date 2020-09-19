---
title: Лекция 14 - Указатели/Стек
category: лекции
---
A и Б клас
[Линк към презентацията за стек](https://docs.google.com/presentation/d/1GHF7q_9JWd2tws8xe05e0C7wkm3VWdmG7AMDaq2_seo/edit)

В и Г клас
[Линк към презентацията за указатели](https://docs.google.com/presentation/d/14BsLm5hhEPYgsNRRlSAusA7EZlKhSpzU4PCx-T36Bk8/edit)

## Задачи от час А и Б

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_t {
    int capacity;
    int count;
    int *arr;
};

struct stack_t stack_init(int);
void stack_destroy(struct stack_t*);
void push(struct stack_t*, int);
int top(struct stack_t);
int pop(struct stack_t*);
int size(struct stack_t);

float rpn_solve(char*);

int main() {

    struct stack_t s = stack_init(2);

    push(&s, 5);
    push(&s, 7);
    printf("%d\n", top(s));
    printf("%d\n", size(s));
    printf("%d\n", pop(&s));
    printf("%d\n", top(s));
    printf("%d\n", size(s));

    stack_destroy(&s);

    printf("%f\n", rpn_solve("2 3 5 + +"));


    return 0;
}

float rpn_solve(char *exp) {
    int length = strlen(exp);
    struct stack_t stack = stack_init(length);

    for (int i = 0; i < length; i+=2) {
        // i++ => if (exp[i] == ' ') continue;

        if (exp[i] >= 48 && exp[i] <= '9') {
            push(&stack, exp[i] - '0');
        }
        else {
            int result;
            int second = pop(&stack);
            int first = pop(&stack);

            switch(exp[i]) {
                case '-': result = first - second; break;
                case '+': result = first + second; break;
                case '*': result = first * second; break;
                case '/': result = first / second; break;
                default: return 0.0;
            }

            push(&stack, result);
        }
    }

    float result = top(stack);
    stack_destroy(&stack);

    return result;
}

struct stack_t stack_init(int initial_capacity) {
    struct stack_t stack;
    stack.count = 0;
    stack.capacity = initial_capacity;
    stack.arr = malloc(initial_capacity * sizeof(int));

    return stack;
}

void stack_destroy(struct stack_t *stack) {
    free(stack->arr);
    stack->arr = NULL;

    stack->count = 0;
    stack->capacity = 0;
}

void push(struct stack_t *s, int elem) {
    // Check if we have space

    s->arr[s->count] = elem;
    s->count++;
}

int top(struct stack_t s) {
    // Check it is not empty
    return s.arr[s.count - 1];
}

int pop(struct stack_t *s) {
    // Check it is not empty

    int elem = top(*s);
    s->count--;

    return elem;
    // return s->arr[s->count--];
}

int size(struct stack_t s) {
    return s.count;
}
```

## Задачи от час В и Г

```c
#include<stdio.h>

struct human_t {
    int age;
    float viso4ina;
};

int main() {

    struct human_t h = { 20, 1.20 };
    struct human_t *h_ptr = &h;
    printf("%d\n", h_ptr.age);

    int arr[10];

    arr[0] = 10123353;
    arr[1] = 20;

    char *ptr = arr;

    printf("%d\n", *ptr);
    printf("%d\n", *(ptr+1));

    for (int i = 0; i < 10; i++) {
        printf("%p\n", arr + i);
    }

    return 0;
}
```

```c
#include <stdio.h>

int print_sequence(int*, int*);

int main() {

    int arr[] = {1, 2, 3, 4, 5};

    print_sequence(&arr[3], &arr[2]);


    return 0;
}

int print_sequence(int *start, int *end) {
    int count = 0;

    if (end < start) {
        return 0;
    }

    do {
        printf("%d\n", *start);
        start += 1;
        count++;
    }
    while(start <= end);

    return count;
}
```

```c
#include <stdio.h>

void get_min_max(int*, int*, int*, int);

int main() {

    int min;
    int max;
    int arr[] = {1, 2, 3, 4, 5};

    get_min_max(arr, &min, &max, 5);

    printf("%d %d\n", min, max);

    return 0;
}

void get_min_max(int *arr, int *min, int *max, int size) {
    if (size <= 0) { return; }

    *min = arr[0];
    *max = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }

        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}
```