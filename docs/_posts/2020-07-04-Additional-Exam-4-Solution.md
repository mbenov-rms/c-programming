---
title: Решение на допълнителното контролно 4
category: задачи
tags:
  - материали
  - задачи
  - контролни
---

[Условие](https://docs.google.com/document/d/1TzhVcUzuHFT48q7kt_KPeB0aK15X99QJk7luztMoBZk/edit?usp=sharing)

### Задача 1
```c
#include <stdio.h>
#include <string.h>

int is_lowercase(char c) {
  return c >= 'a' && c <= 'z';
}


int read_and_count() {
  char str[51];
  fgets(str, 50, stdin);

  int max = 0;

  for(int i = 0; i < strlen(str); i++) {
    if(is_lowercase(str[i])) {
      int len = 1;
      while(is_lowercase(str[i+len])) {
        len++;
      }

      if(max < len) max = len;

      i += len - 1;
    }
  }

  return max;
}

int main() {
  int max_len = read_and_count();
  printf("Max length was %d\n", max_len);
  return 0;
}
```

### Задача 2
```c
#include <stdio.h>
#include <stdlib.h>

struct card_t {
  char* suit;
  short value;
};

int is_two_pair(struct card_t* cards[]) {
  int pair_count = 0;

  for(int i = 0; i < 4; i++) {
    if(cards[i]->value == cards[i+1]->value) {
      pair_count++;
      i += 2;
    }
  }

  return pair_count == 2;
}

void test1() {
  struct card_t c1 = {"spade", 5};
  struct card_t c2 = {"club", 5};
  struct card_t c3 = {"diamond", 7};
  struct card_t c4 = {"heart", 8};
  struct card_t c5 = {"spade", 8};

  struct card_t* cards[5];
  cards[0] = &c1;
  cards[1] = &c2;
  cards[2] = &c3;
  cards[3] = &c4;
  cards[4] = &c5;

  int result = is_two_pair(cards);
  printf("Result: %d\n", result);
}

void test2() {
  struct card_t c1 = {"spade", 5};
  struct card_t c2 = {"club", 5};
  struct card_t c3 = {"diamond", 8};
  struct card_t c4 = {"heart", 10};
  struct card_t c5 = {"spade", 11};

  struct card_t* cards[5];
  cards[0] = &c1;
  cards[1] = &c2;
  cards[2] = &c3;
  cards[3] = &c4;
  cards[4] = &c5;

  int result = is_two_pair(cards);
  printf("Result: %d\n", result);
}


int main() {
  test1();
  test2();
  return 0;
}
```

### Задача 3
```c
// utils.h
#ifndef UTILS_H
#define UTILS_H

struct circle_t {
  int r;
};

int perimeter(struct circle_t circle);
int area(struct circle_t circle);

#define PI 3

#endif
```

```c
// utils.c
#include "utils.h"

int perimeter(struct circle_t circle) {
  return 2 * circle.r * PI;
}

int area(struct circle_t circle) {
  return PI * circle.r * circle.r;
}
```

```c
// main.c
#include <stdio.h>

#include "utils.h"

int main() {
  struct circle_t c1 = {3};
  struct circle_t c2 = {5};

  printf("c1: P = %d S = %d\n", perimeter(c1), area(c1));
  printf("c2: P = %d S = %d\n", perimeter(c2), area(c2));

  return 0;
}
```

```c
// makefile
default:
	gcc -Wall -pedantic -std=c11 main.c utils.c -o main

clean:
	rm main
```
