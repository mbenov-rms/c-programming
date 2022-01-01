---
title: Задачи от подготовката за поправка
category: новини
tags:
  - поправителен
  - материали
  - задачи
---
## Задачи от час Б и Г

```c
#include <stdio.h>
#include <math.h>

int is_curious(int);
void print_curious_numbers_with_arity(int);

int main()
{
  printf ("%d\n", is_curious(25));
  printf ("%d\n", is_curious(13));
  printf ("%d\n", is_curious(76));
  printf ("\n");

  print_curious_numbers_with_arity(2);
  print_curious_numbers_with_arity(3);
  print_curious_numbers_with_arity(5);

  return 0;
}

int is_curious(int n)
{
  int check = n * n;

  int tmp = n;
  int len = 0;
  while (tmp != 0)
    {
      tmp /= 10;
      ++len;
    }

  for (int i = 0; i < len; ++i)
    {
      if (n % 10 != check % 10)
        {
          return 0;
        }
      n /= 10;
      check /= 10;
    }

  return 1;
}

void print_curious_numbers_with_arity(int n)
{
  int low_range = pow (10, n - 1);
  int high_range = pow (10, n);

  for (int i = low_range; i < high_range; ++i)
    {
      if (is_curious(i))
        {
          printf ("%d\n", i);
        }
    }
}
```

```c
#include <stdio.h>
#include <string.h>

struct airplane_t
{
  char model[10];
  char destination[50];
  int fuel;
  char full_description[100];
};

void fill (struct airplane_t*);
void fill_airplane_with_lowest_fuel (struct airplane_t*, int);

int main ()
{
  struct airplane_t plane = { "dc-8", "Montreal", 600, "" };
  struct airplane_t planes[] = { { "dc-8", "Montreal", 600, "" },
                                 { "Concord", "New York", 200, "" } };

  fill (&plane);
  printf ("%s\n", plane.full_description);

  fill_airplane_with_lowest_fuel (planes, 2);

  return 0;
}

void fill (struct airplane_t *airplane)
{
  airplane->fuel += 500;

  strcpy (airplane->full_description, airplane->model);
  strcat (airplane->full_description, " ");
  strcat (airplane->full_description, airplane->destination);
  strcat (airplane->full_description, " ");

  int tmp = airplane->fuel;
  int len = 0;
  while (tmp != 0)
    {
      tmp /= 10;
      ++len;
    }

  char fuel_str[len + 1];
  tmp = airplane->fuel;
  for (int i = len - 1; i >= 0; --i)
    {
      fuel_str[i] = '0' + (tmp % 10);
      tmp /= 10;
    }
  fuel_str[len] = '\0';

  strcat (airplane->full_description, fuel_str);
}

void fill_airplane_with_lowest_fuel (struct airplane_t *airplane,
                                     int arr_size)
{
  if (arr_size <= 0) return;
  int min = airplane[0].fuel;
  int idx = 0;

  for (int i = 1; i < arr_size; ++i)
    {
      if (min > airplane[i].fuel)
        {
          min = airplane[i].fuel;
          idx = i;
        }
    }

  fill(&airplane[idx]);
  printf ("%s\n", airplane[idx].full_description);
}
```
