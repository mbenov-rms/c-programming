---
title: Лекция 19 - Препроцесор и хедъри
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/1HlmCeiESXHe8TEZ0rCHMW7-7gsbI-1mS_eyO47ipNec/edit?usp=sharing)

{% include presentation id="2PACX-1vSLYkFUm5DCPkFxVtumUfswHV4hUXIlxfD19j6lEg2RuklNaO275hq_bTZ7lzQHvtc0kRNEBxlQTq-D" %}

## А и Б клас
```c
// macros.c

#include <stdio.h>

#define DEBUG
#define PI 3.14
#define square(x) (x) * (x)

int main() {
  #ifdef DEBUG
  printf("I'M DEBUGGING\n");
  #endif
  printf("PI = %f\n", PI);
  int a = 7;
  printf("7^2 = %d\n", square(5 + 2));
  return 0;
}

#undef DEBUG
```

```c
// headers.c

#include <stdio.h>

#include "string.h"
#include "string.h"

int main() {
  //printf("strlen(abcd) = %d\n", strlen2("abcd"));
  return 0;
}
```

```c
// string.h
#ifndef STRING_H
#define STRING_H

int strlen2(char *);

int VAR = 10;

#endif
```

```c
// string-linux.c
#include "string.h"

int strlen2(char* str) {
  return 5;
}
```

```c
// string-win.c
#include "string.h"

int strlen2(char* str) {
  return 7;
}
```

```c
// makefile
default: linux

win:
	gcc -E headers.c string-win.c

linux:
	gcc headers.c string-linux.c
```
