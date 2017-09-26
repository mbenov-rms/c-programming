---
title: Лекция 01 - Linux и функции в С
date: 2017-09-27 01:00:00 +0300
category: лекции
---

Качена е презентацията от лекцията за линукс и функции в С.

[Линк към презентацията](https://docs.google.com/presentation/d/e/2PACX-1vTIIT-CUVPiRloiq-NW4Zl-jaIcP2l3Nqspb2bzokuZwn28Gol_7k3202Nz69UhE16xkxhO4YHV68qV/pub?start=false&loop=false&delayms=3000)

{% include presentation id="2PACX-1vTIIT-CUVPiRloiq-NW4Zl-jaIcP2l3Nqspb2bzokuZwn28Gol_7k3202Nz69UhE16xkxhO4YHV68qV" %}

## Задачи от час

```c
// hello.c
#include<stdio.h>

int main() {
    return 0;
}
```

```c
// odd_even_numbers.c
#include<stdio.h>

int is_odd(int);
int is_even(int);

int main() {

    printf("is 25 odd = %d\n", is_odd(25));
    printf("is 0 odd = %d\n", is_odd(0));

    int num1; // not initialized, just showing randomness
    printf("is %d odd = %d\n",num1, is_odd(num1));

    return 0;
}

int is_odd(int number) {
    // Short version
    // return number % 2 != 0;

    if (number % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

int is_even(int another_number) {
    // Short version
    // return !is_odd(another_numer);

    if (is_odd(another_number) == 0) {
        return 1;
    }
    return 0;

}
```
