---
title: Лекция 14 - Динамична памет/едносвързан списък
category: лекции
---
A и Б клас
[Линк към презентацията за списък](https://docs.google.com/presentation/d/1akNB8yN82wpF_FbxIwPg8xvTnVV1nZIURuUYVWMAWI8/edit#slide=id.p)

В и Г клас
[Линк към презентацията за динамична памет](https://docs.google.com/presentation/d/1UY1PWQDPMwTYUTFyWVVwbn0irq1ZeGUnQvgidkFS7V0/edit#slide=id.p)

## Задачи от час А и Б

```c

```

## Задачи от час В и Г

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("err\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }

    // printf("%p\n", &n);
    // printf("%p\n", arr);

    free(arr);

    return 0;
}
```

```c
#include <stdio.h>

int main() {
    int i = 0;
    int n;
    int res = scanf("%d", &n);
    while(res != EOF) {
        printf("%d - %d\n", res, n);
        res = scanf("%d", &n);
    }

    printf("%d %d", res, EOF);

    return 0;
}
```

```c
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    int size = 2;
    int *arr = malloc(size * sizeof(int));
    int n;

    while(scanf("%d", &n) != EOF) {
/*        if (i == size) {
            int *tmp = malloc(size * sizeof(int));
            for(int k = 0; k < size; k++){
                tmp[k] = arr[k];
                printf("tmp = i%d\n", arr[k]);
            }

            size *= 2;
            free(arr);
            arr = malloc(size * sizeof(int));
            memcpy(arr, tmp, i * sizeof(int));

            free(tmp);
        } // manual realloc */

        size *= 2;

        arr = realloc(arr, size * sizeof(int));

        arr[i] = n;
        i++;
    }

    for (int k = 0; k < i; k++) {
        printf("%d\n", arr[k]);
    }

    free(arr);
    return 0;
}
```
