---
title: Код от консултацията
category: новини
tags:
  - материали
---

[Линк към презентацията](https://drive.google.com/open?id=1Ul5qXQRbLzZPJ4Up2c2FdFsyaQ1JBkJ-bo2YUaqUBQw)

```c
#include <stdlib.h>
#include <stdio.h>

struct node_t {
  struct node_t* next;
  int val;
};

struct list_t {
  struct node_t* head;
  int size;
};

void destroy_next(struct node_t* curr) {
  printf("destroy_next called for: [%p] %d %p\n", curr, curr->val, curr->next);
  if(curr->next != NULL) {
    destroy_next(curr->next);
  }
  printf("free %p\n", curr);
  free(curr);
}

void destroy_list(struct list_t l) {
  /*struct node_t curr = l.head;
  while(curr != NULL) {
    struct node_t* tmp = curr->next;
    free(curr);
    curr = tmp;
    //curr = curr->next;
  }*/

  destroy_next(l.head);
}

void print_list(struct list_t l) {
  struct node_t* c = l.head;
  while(c != NULL) {
    printf("[%p] %d %p\n", c, c->val, c->next);
    c = c->next;
  }
}


int main() {
  struct list_t l;
  struct node_t* n1 = malloc(sizeof(struct node_t));
  n1->val = 1;
  struct node_t* n2 = malloc(sizeof(struct node_t));
  n2->val = 2;
  struct node_t* n3 = malloc(sizeof(struct node_t));
  n3->val = 3;
  struct node_t* n4 = malloc(sizeof(struct node_t));
  n4->val = 4;
  l.head = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = NULL;

  print_list(l);
//  destroy_list(l);
  destroy_next(n3);
  return 0;
}
```
