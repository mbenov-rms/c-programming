---
title: Лекция 09 - Динамична Памет
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/13IfdrT5daSwNBgUtLb6PMAgnI-cPbjAZGXz1cCw31ww/)

{% include presentation id="2PACX-1vTAfl08yUxsRco2FJoaPC1rHun15dVesuOd-p8A7FJmlwHQezm3Hb9Yy5VPyqs-OM2yZMVnhOYkk9zb" %}

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  int *numbers = (int*)malloc(50 * sizeof(int));  

  for(int i=0; i<50; i++) {
    numbers[i] = i;
  }

  //memset(numbers, 0, 50 * sizeof(int));

  int *numbers2 = (int*)malloc(50 * sizeof(int));  

  memcpy(numbers2, numbers, 25 * sizeof(int));

  for(int i=0; i<50; i++) {
    printf("%d ", numbers2[i]);
  }
  putchar('\n');

  free(numbers);
  free(numbers2);

  /*double *other_numbers = (double*)numbers;

  printf("%ld %ld %ld\n", sizeof(int), sizeof(float), sizeof(double));

  for(int i=0; i<25; i++) {
    printf("%f ", other_numbers[i]);
  }
  putchar('\n');

  for(int i=0; i<25; i++) {
    other_numbers[i] = i;
  }

  for(int i=0; i<50; i++) {
    printf("%d ", numbers[i]);
  }
  putchar('\n');*/

  /*free(numbers);
  numbers = NULL;

  for(int i=0; i<50; i++) {
    numbers[i] = i;
    printf("%d ", numbers[i]);
  }
  putchar('\n');*/

  //float *x = malloc(sizeof(float));

 // int arr[100];
 // free(arr);

  return 0;
}
```
