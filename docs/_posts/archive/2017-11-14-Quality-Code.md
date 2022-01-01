---
title: Лекция 06 - Качествен код
category: лекции
---

Качена е презентацията от лекцията за качествен код.

[Линк към презентацията](https://docs.google.com/presentation/d/e/2PACX-1vQhJ3Q_F8eT20H3yMo5aTLf4HgSmAAU0lFByt06kbmShVI3ah5xNCvHNfmQerkZnHIG4RyVeR7fq3bE/pub?start=false&loop=false&delayms=3000)
{% include presentation id="2PACX-1vQhJ3Q_F8eT20H3yMo5aTLf4HgSmAAU0lFByt06kbmShVI3ah5xNCvHNfmQerkZnHIG4RyVeR7fq3bE" %}

## Задачи от час

```c
#include<stdio.h>

#define PI 3.14

float circle_perimeter(struct circle_t);
float circle_area(struct circle_t);

struct point_t {
    float x;
    float y;
};

struct circle_t {
    struct point_t center;
    float radius;
};

int main() {
    struct point_t center = {1, -1};
    struct circle_t circle = {center, 3};

    printf("parameter = %f\n", circle_perimeter(circle));
    printf("area = %f\n", circle_area(circle));

    return 0;
}

float circle_perimeter(struct circle_t circle) {
    return 2 * PI * circle.radius;
}

float circle_area(struct circle_t circle) {
    return PI * circle.radius * circle.radius;
}
```
