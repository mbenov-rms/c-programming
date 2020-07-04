---
title: Решение на контролно 4
category: задачи
tags:
  - материали
  - задачи
  - контролни
---

## А, Б
[Условие](https://docs.google.com/document/d/1cCTTopHXFlgZ-6ILIqltiOXby1unf2HHONy2VOT65aU/edit?usp=sharing)

### Задача 1
```c
#include <stdio.h>
#include <string.h>

int read_and_count() {
  char str[51];
  fgets(str, 50, stdin);

  int max = 0;

  for(int i = 0; i < strlen(str); i++) {
    int len = 1;
    while(str[i+len] == str[i]) {
      len++;
    }

    if(max < len) max = len;

    i += len - 1;
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

int is_three_of_a_kind(struct card_t* cards[]) {
  for(int i = 0; i < 3; i++) {
    if(cards[i]->value == cards[i+1]->value &&
       cards[i+1]->value == cards[i+2]->value) {
      return 1;
    }
  }

  return 0;
}

void test1() {
  struct card_t c1 = {"spade", 5};
  struct card_t c2 = {"club", 6};
  struct card_t c3 = {"diamond", 6};
  struct card_t c4 = {"heart", 6};
  struct card_t c5 = {"spade", 9};

  struct card_t* cards[5];
  cards[0] = &c1;
  cards[1] = &c2;
  cards[2] = &c3;
  cards[3] = &c4;
  cards[4] = &c5;

  int result = is_three_of_a_kind(cards);
  printf("Result: %d\n", result);
}

void test2() {
  struct card_t c1 = {"spade", 5};
  struct card_t c2 = {"club", 6};
  struct card_t c3 = {"diamond", 6};
  struct card_t c4 = {"heart", 10};
  struct card_t c5 = {"spade", 11};

  struct card_t* cards[5];
  cards[0] = &c1;
  cards[1] = &c2;
  cards[2] = &c3;
  cards[3] = &c4;
  cards[4] = &c5;

  int result = is_three_of_a_kind(cards);
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

struct triangle_t {
  int a;
  int b;
  int c;
};

int perimeter(struct triangle_t triangle);
int area(struct triangle_t triangle);

#endif
```

```c
// utils.c
#include "utils.h"

int perimeter(struct triangle_t triangle) {
  return triangle.a + triangle.b + triangle.c;
}

int area(struct triangle_t triangle) {
  return (triangle.a * triangle.b) / 2;
}
```

```c
// main.c
#include <stdio.h>

#include "utils.h"

int main() {
  struct triangle_t t1 = {3, 4, 5};
  struct triangle_t t2 = {5, 10, 2};

  printf("t1: P = %d S = %d\n", perimeter(t1), area(t1));
  printf("t2: P = %d S = %d\n", perimeter(t2), area(t2));

  return 0;
}
```

```c
// makefile.c
default:
	gcc -Wall -pedantic -std=c11 main.c utils.c -o main

clean:
	rm main
```

## В
[Условие](https://docs.google.com/document/d/12f_fLg5tFMY7SE2WlAQtjqo65RjRJf_XYdF41UZ-gKQ/edit?usp=sharing)

### Задача 1
```c
#include <stdio.h>
#include <string.h>

int read_and_count() {
  char str[51];
  fgets(str, 50, stdin);

  int max = 0;

  for(int i = 0; i < strlen(str); i++) {
    int len = 0;

    do {
      len++;
    } while(str[i + len] != str[i + len - 1] && i + len < strlen(str));

    if(max < len) max = len;

    i += len - 1;
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

int is_straight(struct card_t* cards[]) {
  for(int i = 0; i < 4; i++) {
    if(cards[i]->value != cards[i+1]->value - 1) {
      return 0;
    }
  }

  return 1;
}


void test1() {
  struct card_t c1 = {"spade", 5};
  struct card_t c2 = {"club", 6};
  struct card_t c3 = {"diamond", 7};
  struct card_t c4 = {"heart", 8};
  struct card_t c5 = {"spade", 9};

  struct card_t* cards[5];
  cards[0] = &c1;
  cards[1] = &c2;
  cards[2] = &c3;
  cards[3] = &c4;
  cards[4] = &c5;

  int result = is_straight(cards);
  printf("Result: %d\n", result);
}

void test2() {
  struct card_t c1 = {"spade", 5};
  struct card_t c2 = {"club", 6};
  struct card_t c3 = {"diamond", 8};
  struct card_t c4 = {"heart", 10};
  struct card_t c5 = {"spade", 11};

  struct card_t* cards[5];
  cards[0] = &c1;
  cards[1] = &c2;
  cards[2] = &c3;
  cards[3] = &c4;
  cards[4] = &c5;

  int result = is_straight(cards);
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

struct rectangle_t {
  int a;
  int b;
};

int perimeter(struct rectangle_t rectangle);
int area(struct rectangle_t rectangle);

#endif
```

```c
// utils.c
#include "utils.h"

int perimeter(struct rectangle_t rectangle) {
  return (rectangle.a + rectangle.b) * 2;
}

int area(struct rectangle_t rectangle) {
  return rectangle.a * rectangle.b;
}
```

```c
// main.c
#include <stdio.h>

#include "utils.h"

int main() {
  struct rectangle_t r1 = {3, 4};
  struct rectangle_t r2 = {5, 10};

  printf("r1: P = %d S = %d\n", perimeter(r1), area(r1));
  printf("r2: P = %d S = %d\n", perimeter(r2), area(r2));

  return 0;
}
```

```c
// makefile.c
default:
	gcc -Wall -pedantic -std=c11 main.c utils.c -o main

clean:
	rm main
```
