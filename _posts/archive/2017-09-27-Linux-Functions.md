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

    int num1; // not initialised, just showing randomness
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
    // return !is_odd(another_number);

    if (is_odd(another_number) == 0) {
        return 1;
    }
    return 0;

}
```

```c
// calc.c
#include<stdio.h>

int sum(int, int);
int mul(int, int);

int main() {
    printf("3 + 5 = %d\n", sum(3, 5));
    printf("6 + 12 = %d\n", sum(6, 12));
    printf("0 + -5 = %d\n", sum(0, -5));

    int arg1, arg2; // Not initialised, just showing randomness
    printf("%d + %d = %d\n", arg1, arg2, sum(arg1, arg2));

    int res = mul(5, 5);
    int res2 = mul(5, 6);
    printf("%d\n", res);
    printf("%d\n", res2);

    return 0;
}

int sum(int first, int second) {
    return first + second;
}

int mul(int a, int b) {
   int res = 0;
   for(int i = 0; i < a /* or b */; ++i) {
       res = sum(res, b);
    }
    return res;
}
```
