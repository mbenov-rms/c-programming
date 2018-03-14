---
title: Лекция 12 - Динамична памет/Побитови маски
category: лекции
---
A и Б клас
[Линк към презентацията за динамична памет](https://docs.google.com/presentation/d/1UY1PWQDPMwTYUTFyWVVwbn0irq1ZeGUnQvgidkFS7V0/edit?usp=sharing)

В и Г клас
[Линк към презентацията за побитови маски](https://docs.google.com/presentation/d/1Ewegu04XNaiLmrG6m_FV0WCfmhWfHt2f6RyeGc0Nhy0/edit?usp=sharing)

## Задачи от час А и Б

```c
#include <stdio.h>
#include <string.h>

int main ()
{
  int a[10];

  memset (&a, 0, sizeof (int) * 10);

  for (int i = 0; i < 10; ++i)
    {
      printf ("%d, ", a[i]);
    }
  printf ("\n");

  return 0;
}
```

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main ()
{
  int *a = (int*)(malloc (1024));

  free (a);
  a = NULL;
  free (a);

  printf ("Test\n");

  return 0;
}
```

## Задачи от час В и Г

```c
#include <stdio.h>

int is_power_of_two (int n)
{
  int count = 0;

  for (int i = 0; i < sizeof (int) * 8; ++i)
    {
      if (n & (1 << i))
        {
          ++count;
        }
    }
  return count == 1;
}

int main ()
{
  int n = 4;

  printf ("%d\n", is_power_of_two (n));
  printf ("%d\n", is_power_of_two (1));
  printf ("%d\n", is_power_of_two (5));
  printf ("%d\n", is_power_of_two (10));

  return 0;
}
```
