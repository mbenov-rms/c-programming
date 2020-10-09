---
title: Лекция 03 - Структури
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/1qiDu4XZOnu_fyyC2yEsNk3IxXqHKNeD3pBpX-xJvWQw/edit?usp=sharing)

{% include presentation id="2PACX-1vRIF-HEbVvgjEJ-MgzXa1a5dzwH9vTLSGj-Xmkxjg6FgQTWZ3Hja_tIjax9Q2OO3to0UmlpWpI456mQ" %}

## Код
```c
#include <stdio.h>

struct point_t {
  float x;
  float y;
};

typedef struct point_t my_point_t;

typedef struct point2_t {
  // ...
} my_point2_t;

int are_in_line(struct point_t p1,
                struct point_t p2,
                struct point_t p3) {

// (n−b)(x−m)=(y−n)(m−a)
  return (p2.y - p1.y) * (p3.x - p2.x) ==
         (p3.y - p2.y) * (p2.x - p1.x);
}

int main() {
  struct point_t p1 = {10, 12.3};
  my_point_t p2; // = {1, 5};
  p2.x = 10;
  p2.y = 15;
  my_point_t p3 = {10, 25};

  printf("p1=(%f, %f)\n", p1.x, p1.y);

  printf("%d\n", are_in_line(p1, p2, p3));

  return 0;
}
```
