---
title: Лекция 04 - Указатели
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/16bCkwgicrvq-Mi9qaFpvDXPNflxyNQqtzTbRB2yxGxU/edit?usp=sharing)

{% include presentation id="2PACX-1vSiQZUdy3c9-xlD5sHnh6nJ_5tiNNU72qPaHao8pjqEZPEyJa_FnaDHJ8us4eX7xhroD7TUdE8g3WOe/" %}

## А клас
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int *arr;

    arr = malloc(10 * sizeof(int));

    for(int i = 0; i < 10; i++) {
        arr[i] = i;
        printf("%d %d\n", i, arr[i]);
    }

    memset(arr, -1, 10 * sizeof(int));

    for(int i = 0; i < 10; i++) {
        printf("%d %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}
```

## Б клас
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  int size = 10;
  int *arr = malloc (size * sizeof (int));

  for (int i = 0; i < size; ++i)
    {
      arr[i] = i;
      printf ("%d %d\n", i, arr[i]);
    }

  memset (arr, 0, size * sizeof(int));

  for (int i = 0; i < size; ++i)
    {
      printf ("%d %d\n", i, arr[i]);
    }

  free (arr);
  arr = NULL;

  if (arr != NULL)
    printf ("%d\n", arr[0]);

  return 0;
}
```
