---
title: Контролно 1 - решение
category: новини
tags:
  - упражнения
  - материали
---

Това са примерни решения на задачите от контролното. В някои случаи има и по-оптимално, но дълги решения.

## В клас
### Задача 1

```c
#include <stdio.h>

unsigned int count_10(short data) {
  unsigned int count = 0;

  // Iterate all bits
  while(data > 0) {
    // Extract the last 2 bits and check if they match the pattern
    // 1010 1010 & 0000 0011 == 0000 0010
    if((data & 0b11) == 0b10) count++;
    // if((data & 3) == 2) count++; // 0b11 == 3, 0b10 == 2
    // Bitshift to the right once
    data >>= 1;
  }

  return count;
}

int main() {
  printf("11 => %d\n", count_10(11));
  printf("3 => %d\n", count_10(3));
  printf("21601 => %d\n", count_10(21601));
  return 0;
}
```

### Задача 2

```c
#include <stdio.h>
#include <string.h>

// Helper function to split the code
int find_most_common(int *array, unsigned int size) {
  // Helper variables to track the most common value
  int most_common = array[0];
  int most_occurances = 1;

  // size - most_occurances because if less than most_occurances items remain
  // then none of them can beat the current most common
  for(int i = 0; i < size - most_occurances; i++) {
    int curr_item = array[i];
    int curr_occurances = 1;

    // Search all reamaining items to the right
    for(int j = i + 1; j < size; j++) {
      if(array[j] == curr_item) curr_occurances++;
    }

    // Update the most common value if we found a new one
    if(curr_occurances > most_occurances) {
      most_common = curr_item;
      most_occurances = curr_occurances;
    }
  }

  return most_common;
}

void sort_most_common(int *array, unsigned int size) {
  int most_common = find_most_common(array, size);

  /*
  // Option 1 - use a front-to-back index to iterate all items and a back-to-front
  // index to track the last position that doesn't have a most_common value
  // This DOES NOT preserve the order of items
  int bf = size - 1;
  // In case the array ends with one or more most_common find where they end
  while(array[bf] == most_common) bf--;

  // Iterate all elements except the list of most_common at the end
  for(int fb = 0; fb < bf; fb++) {
    if(array[fb] == most_common) {
      // Swap
      int c = array[fb];
      array[fb] = array[bf];
      array[bf] = c;
      // Move the back-to-front index to the new last free position
      bf--;
    }
  }*/

  // Option 2 - use a temporary lsit of items to help store the correct order
  // This WILL preserve the order of items
  int buffer[size];
  int buffer_index = 0;
  for(int i = 0; i < size; i++) {
    // Move all items that are not most_common to the buffer in the same order as they appear
    if(array[i] != most_common) {
      buffer[buffer_index] = array[i];
      buffer_index++;
    }
  }

  // Fill all remaining positions with most_common
  for(int i = buffer_index; i < size; i++) {
    buffer[i] = most_common;
  }

  // Copy back to the original array
  memcpy(array, buffer, sizeof(int) * size);
}

void print_array(int *array, unsigned int size) {
  for(int i = 0; i < size; i++)
    printf("%d ", array[i]);

  puts("");
}

int main() {
  int arr1[] = {1, 3, 5, 3, 7};
  int arr2[] = {3, 4, 2, 4, 3};

  sort_most_common(arr1, 5);
  sort_most_common(arr2, 5);

  print_array(arr1, 5);
  print_array(arr2, 5);

  return 0;
}
```

### Задача 3

```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  struct node_t *next, *prev;
  struct node_t *s_next, *s_prev;
};

struct node_t* init_node(int value) {
  struct node_t *new_node = malloc(sizeof(struct node_t));

  new_node->value = value;
  new_node->next = new_node->prev = NULL;
  new_node->s_next = new_node->s_prev = NULL;

  return new_node;
}

// Insert a new node.
// Point next and prev as a new head.
// Point s_next and s_prev in ascending order from left to right.
struct node_t* add_node(struct node_t *list, int value) {
  struct node_t *new_node = init_node(value);

  // The list is empty so just return the node
  if(list == NULL) return new_node;

  // Insert the new node as the new head
  list->prev = new_node;
  new_node->next = list;

  // list can be anywhere in the sorted list. Find the correct place to put the new item
  struct node_t *curr = list;
  if(curr->value < value) {
    // Stop when we reach the end of the list
    // OR the new value is between curr and curr->next
    while(curr->s_next != NULL && curr->s_next->value < value)
      curr = curr->s_next;  

    // Insert between curr and curr->next
    new_node->s_next = curr->s_next;
    new_node->s_prev = curr;
    if(curr->s_next != NULL)
      curr->s_next->s_prev = new_node;
    curr->s_next = new_node;
  } else {
    // Stop when we reach the start of the list
    // OR the new value is between curr and curr->prev
    while(curr->s_prev != NULL && curr->s_prev->value > value)
      curr = curr->s_prev;

    // Insert between curr->prev and curr
    new_node->s_next = curr;
    new_node->s_prev = curr->s_prev;
    if(curr->s_prev != NULL)
      curr->s_prev->s_next = new_node;
    curr->s_prev = new_node;
  }

  return new_node;
}

void print_as_added(struct node_t *list) {
  struct node_t *curr = list;
  while(curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  puts("");
}

void print_as_sorted(struct node_t *list) {
  struct node_t *curr = list;

  // We don't store the sorted head so we need to find it
  while(curr->s_prev != NULL)
    curr = curr->s_prev;

  while(curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->s_next;
  }
  puts("");
}

int main() {
  struct node_t *list = add_node(NULL, 5);
  list = add_node(list, 1);
  list = add_node(list, 8);
  list = add_node(list, 4);
  list = add_node(list, 7);

  print_as_added(list);
  print_as_sorted(list);

  return 0;
}
```
