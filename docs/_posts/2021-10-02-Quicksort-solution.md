---
title: Упражнение 03 продължение - Работещ вариант на quicksort
category: новини
tags:
  - упражнения
  - материали
---

Разкоментирайте `#define PRINT_LOGS` за да се принтират подробности за стъпки от алгоритъма.

```c
#include <stdio.h>

// #define PRINT_LOGS

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int arrange_around_pivot(int arr[], int n, int pivot_index) {
#ifdef PRINT_LOGS
    printf("arrange_around_pivot with n=%d and pivot_index=%d\n", n, pivot_index);
    puts("Before arranging:");
    print_array(arr, n);
#endif

    // iterate items to the left of the pivot
    for(int i = 0; i < pivot_index; i++) {
        if(arr[i] > arr[pivot_index]) {
            if(i == pivot_index - 1) {
                swap(arr + i, arr + pivot_index);  // item is next to the pivot so just swap them
            } else {
                swap(arr + pivot_index - 1, arr + pivot_index); // push the pivot left by swapping with the item to the left
                swap(arr + i, arr + pivot_index); // swap current item with the old pivot position - the item that used to be to the left of the pivot
                i--; // there's a new item at the current i so make sure to re-check the index
            }
            pivot_index--; // 1 item moved to the right of the pivot
        }
    }

    // iterate items to the right of the pivot
    // notice it's almost identical
    for(int i = pivot_index + 1; i < n; i++) {
        if(arr[i] < arr[pivot_index]) {
            if(i == pivot_index + 1) {
                swap(arr + i, arr + pivot_index);  // item is next to the pivot so just swap them
            } else {
                swap(arr + pivot_index + 1, arr + pivot_index); // push the pivot right by swapping with the item to the right
                swap(arr + i, arr + pivot_index); // swap current item with the old pivot position - the item that used to be to the right of the pivot
                i--; // there's a new item at the current i so make sure to re-check the index
            }
            pivot_index++; // 1 item moved to the right of the pivot
        }
    }

#ifdef PRINT_LOGS
    puts("After arranging:");
    print_array(arr, n);
    puts("");
#endif

    return pivot_index;
}

void quicksort(int arr[], int n) {
#ifdef PRINT_LOGS
    printf("quicksort with n=%d\n", n);
    if(n >= 1)    
        print_array(arr, n);
#endif

    if(n <= 1) return; // 1 item or less is already sorted, stop the recursion

    int pivot_index = n / 2; // Use the middle item as a pivot

#ifdef PRINT_LOGS
    printf("Pivot at [%d] is %d\n", pivot_index, arr[pivot_index]);
#endif

    pivot_index = arrange_around_pivot(arr, n, pivot_index); // move items around the pivot and get the new pivot position

    quicksort(arr, pivot_index); // Sort the left side of the pivot
    quicksort(arr + pivot_index + 1, n - pivot_index - 1); // Sort the right side of the pivot
}


int main()
{
    int test1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // properly sorted
    int test2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // reversed
    int test3[] = {4, 8, 3, 1, 9, 6, 0, 5, 7, 2}; // shuffled
    int test4[] = {4, 6, 3, 1, 8, 9, 0, 5, 7, 2}; // middle element is the largest
    int test5[] = {4, 0, -2, -1, 3, 1, -3, 2, -4, 5}; // with negatives

    quicksort(test1, 10);
    print_array(test1, 10);

    quicksort(test2, 10);
    print_array(test2, 10);

    quicksort(test3, 10);
    print_array(test3, 10);

    quicksort(test4, 10);
    print_array(test4, 10);

    quicksort(test5, 10);
    print_array(test5, 10);

    return 0;
}

```
