---
title: Упражнение 05 продължение - Skip List
category: новини
tags:
  - упражнения
  - материали
---

## Код от час
### В клас

```c
#include <stdio.h>
#include <stdlib.h>

struct list
{
  struct list *prev, *next;
  int data;
  struct list **skip;
};

void adjust_skips(struct list *list) {
  struct list* tmp = list;
  // Remove the skips from all items
  while(tmp != NULL) {
    if(tmp->skip) {
      free(tmp->skip);
      tmp->skip = NULL;
    }

    tmp = tmp->next;
  }

  tmp = list;
  while(tmp != NULL) {
    if(tmp->next && tmp->next->next) { // There are at least 2 items after tmp
      tmp->skip = malloc(sizeof(struct list*));
      tmp->skip[0] = tmp->next->next; // Assign the jump pointer
      tmp = tmp->skip[0]; // And jump because we do not care about items between tmp and skip
    } else {
      break; // Less  than 2 items after skip, nothing more to do
    }
  }
}

struct list* add(struct list *list, int data)
{
  struct list *item = malloc(sizeof(struct list));

  item->data = data;
  item->prev = NULL;
  item->skip = NULL;
  item->next = list;

  if(!list) { // The list is empty and item becomes the first and only element
    return item;
  }

  if(data < list->data) { // item should become the new first element
    item->next = list;
    list->prev = item;
    list = item;
  } else {
      struct list *curr = list;
      while(curr->skip != NULL && curr->skip[0]->data < data) curr = curr->skip[0]; // Iterate over skips while they exist and data < skip->data

      while(curr->next != NULL && curr->next->data < data) curr = curr->next; // Iterate over nexts while they exist and data < next->data

      // Add the new item between curr and curr->next
      item->prev = curr;
      item->next = curr->next;

      if(curr->next != NULL) // If curr is the last item there is no next
        curr->next->prev = item;
      curr->next = item;
  }

  adjust_skips(list);

  return list;
}

void print_list(struct list* list) {
  for(struct list* tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("*=%p d=%d next=%p skip=%p", tmp, tmp->data, tmp->next, tmp->skip);
    if(tmp->skip) {
      printf(" skip[0]=%p", tmp->skip[0]);
    }
    puts("");
  }
}

int if_val(struct list* list, int val)
{
  if(!list) return 0;

  //if(list->data > val) return 0;

  struct list* curr_item = list;
  struct list* tmp = NULL;


  for(; curr_item->skip != NULL && curr_item->skip[0] != NULL; curr_item = curr_item->skip[0])
  {
    if(curr_item->data == val)
      return 1;

    if(curr_item->data > val)
      break;

    tmp = curr_item;
  }

  while(tmp != NULL && tmp->data <= val)
  {
    if(tmp->data == val)
      return 1;
    tmp = tmp->next;
  }

  return 0;
}


int main() {
 // struct list list1= {NULL,NULL,5};
  struct list* list = NULL;     

  list = add(list, 7);
  list = add(list, 48);
  list = add(list, 27);
  list = add(list, 3);
  list = add(list, 41);
  list = add(list, 1);

  puts("");

  printf(" if_val(0) = %d\n", if_val(list, 0));
  printf(" if_val(1) = %d\n", if_val(list, 1));
  printf(" if_val(26) = %d\n", if_val(list, 26));
  printf(" if_val(27) = %d\n", if_val(list, 27));
  printf(" if_val(41) = %d\n", if_val(list, 41));
  printf(" if_val(48) = %d\n", if_val(list, 48));
  printf(" if_val(50) = %d\n", if_val(list, 50));

  print_list(list);
  return 0;
}
```
