---
title: Лекция 01 - Масиви, стрингове, вход/изход
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/19fu5fwUGxKRCLA49mFzbaIGwDBcsWayzr_-Btqn8rvU/edit?usp=sharing)

{% include presentation id="2PACX-1vSB4tnn5sSWjuM4J1LI7M1wCi3Jyu4ZSWpkzsHnLiptF40v-1i2UkS56lpeMEIarGVzkr9iHgFHhf5r" %}

## Код
```c
#include <stdio.h>

int main() {
  /*char chr = 'c';
  int a = 17;
  float b = 456.43;

  scanf("%d", &a);

  printf("%c %d %.2f \n", chr, a, b);
 */

  int arr[5] = {1, 2, 3};
  for(int i=0; i<5; i++) {
    printf("%d\n", *(arr + i));
  }

  return 0;
}
```
