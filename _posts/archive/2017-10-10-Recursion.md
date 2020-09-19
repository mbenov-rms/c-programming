---
title: Лекция 03 - Рекурсия
category: лекции
---

Качена е презентацията от лекцията за рекурсивни функции в С.

[Линк към презентацията](https://docs.google.com/presentation/d/e/2PACX-1vTAjs5-1YMXJq2bzNQSfTc1UbGImng0N0nJ71o1vE24mQRXQZR3_zyy-_TQq9TvoQEyud1ZVl9tAbHM/pub?start=false&loop=false&delayms=3000)

{% include presentation id="2PACX-1vTAjs5-1YMXJq2bzNQSfTc1UbGImng0N0nJ71o1vE24mQRXQZR3_zyy-_TQq9TvoQEyud1ZVl9tAbHM" %}

## Задачи от час

```c
// factorial.c
#include<stdio.h>

int fact(int num);

int main() {

    unsigned long long result = fact(20);

    printf("fact(20) = %llu\n", result);

    return 0;
}

int fact(int num) {
    if (num == 1) {
        return 1;
    }

    return num * fact(num - 1);
}
```

```c
// max_in_array.c
#include<stdio.h>

int max(int[], int size);

int main() {
    int arr[] = {1, 13, 20, 7, 16, 3};

    printf("max is = %d\n", max(arr, 6));

    return 0;
}

int max(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }

    int max_ = max(arr, size - 1);

    printf("DBG: %d > %d\n", arr[size - 1], max_);

    if (arr[size - 1] > max_) {
        return arr[size - 1];
    } else {
        return max_;
    }

    // Short version
    // return arr[size - 1] > max_ ? arr[size - 1] : max_;
}
```

```c
// digits_sum_non_recursive.c
#include<stdio.h>

int main() {

    int sum = 0;
    int number = 2356;

    while(number) { // or number == 0
        int digit = number % 10;
        number /= 10; // same as number = number / 10
        sum += digit; // same as sum = sum + digit
    }

    printf("sum of digits of 2356 = %d\n", sum);

    return 0;
}
```
