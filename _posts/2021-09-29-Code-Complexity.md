---
title: Лекция 03 - Сложност на алгоритъм
category: новини
tags:
  - лекции
  - материали
---

[Какво е Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)

[По-просто обяснение](https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/)

## Код от час
### В клас

```c
//#include <stdio.h>
//#include "../folder2/stdio.h"

#ifndef FILE_HH
  #define FILE_HH

  #define PI 3.1416

  int main() {
    printf("%f\n", PI);
    return 0;
  }

#endif
```

```c
#include <stdio.h>

void swap(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}


void bubblesort(int b[], int n)
{
  puts("START");
  for(int i = 0;i < n;i++)
  //int hasSwaps = 1;
  //while(hasSwaps)
  {
     // hasSwaps = 0;
      //printf("i = %d\n", i);
      for(int j = 0;j < n;j++)
      {
          printf("j = %d\n", j);
          if(b[j+1] < b[j]) {
            puts("SWAP");
            swap(&b[j+1], &b[j]);
            //hasSwaps = 1;     
          }
      }
  }
  puts("END");
}

void print_array(int numbers[], int n) {
  for(int i = 0; i < n; i++) {
    printf("%d ", numbers[i]);
    //printf("%d ", numbers[i]);
  }

  puts("");
}


void quiz(int n) { // n = 25
  for(int i = 0; i < n; i++) {
    printf("i = %d\n", i);
    n = n - (n-i)/2;
  }
}


int main() {
  //int numbers[] = {2, 1, 5, 7, 4, 9, 3, 6, 8};
  //int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //bubblesort(numbers, 9);

  //print_array(numbers, 9);

  quiz(36);
  return 0;
}
```
