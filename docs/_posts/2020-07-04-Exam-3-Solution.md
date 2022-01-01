---
title: Решение на контролно 3
category: задачи
tags:
  - материали
  - задачи
  - контролни
---

## А, Б
[Условие](https://docs.google.com/document/d/1yj9TkzUXSBYADHnnxXAoYH2ddiJaXBm_tKZLwvEaxec/edit?usp=sharing)

### Задача 1
```c
#include <stdio.h>
#include <string.h>

struct brick_t {
  int width;
  int height;
  char colour[21];
};

struct lego_set_t {
  char name[101];
  struct brick_t bricks[10];
  int brick_count;
};

void print_set(struct lego_set_t set) {
  printf("%s (%d bricks)\n", set.name, set.brick_count);
  for(int i = 0; i < set.brick_count; i++) {
    struct brick_t brick = set.bricks[i];
    printf("%dx%d, %s\n", brick.width, brick.height, brick.colour);
  }
}

int main() {
  struct brick_t br1 = {1, 1, "yellow"};
  struct brick_t br2 = {1, 1, "red"};
  struct brick_t br3 = {1, 2, "yellow"};
  struct brick_t br4 = {2, 2, "green"};
  struct brick_t br5 = {2, 4, "blue"};

  struct lego_set_t set;
  strcpy(set.name, "House");
  set.brick_count = 5;
  set.bricks[0] = br1;
  set.bricks[1] = br2;
  set.bricks[2] = br3;
  set.bricks[3] = br4;
  set.bricks[4] = br5;

  print_set(set);

  return 0;
}
```

### Задача 2
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct truck_t {
  int max_load;
  char brand[21];
  char model[41];
};

struct company_t {
  char name[51];
  struct truck_t* trucks;
  int truck_count;
};

struct truck_t* create_truck(char brand[], char model[], int load) {
  struct truck_t* new_truck = malloc(sizeof(struct truck_t));

  new_truck->max_load = load;
  strcpy(new_truck->brand, brand);
  strcpy(new_truck->model, model);

  return new_truck;
}

void add_truck(struct company_t* company, struct truck_t* truck) {
  company->trucks = realloc(company->trucks, sizeof(struct truck_t) * (company->truck_count + 1));
  company->trucks[company->truck_count] = *truck;
  company->truck_count++;
}

void print_company(struct company_t company) {
  printf("%s (%d trucks)\n", company.name, company.truck_count);
  for(int i = 0; i < company.truck_count; i++) {
    struct truck_t truck = company.trucks[i];
    printf("%s %s (%dkg)\n", truck.brand, truck.model, truck.max_load);
  }
}

int main() {
  struct truck_t* tr1 = create_truck("BMW", "Smal Truk", 2000);
  struct truck_t* tr2 = create_truck("BMW", "Big Truk", 20000);
  struct truck_t* tr3 = create_truck("VW", "Mega Truk", 200000);

  struct company_t company;
  strcpy(company.name, "Elsys Cargo");
  company.truck_count = 0;
  company.trucks = NULL;

  add_truck(&company, tr1);
  add_truck(&company, tr2);
  add_truck(&company, tr3);

  print_company(company);

  return 0;
}
```

### Задача 3
```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int val;
  struct node_t* prev;
  struct node_t* next;
};

struct node_t* init_list() {
  struct node_t* new_list = malloc(sizeof(struct node_t));

  new_list->val = 0;
  new_list->prev = new_list->next = new_list;

  return new_list;
}

void add(struct node_t* head, int val) {
  struct node_t* new_node = malloc(sizeof(struct node_t));

  new_node->val = val;
  new_node->prev = head->prev;
  new_node->next = head;

  head->prev->next = new_node;
  head->prev = new_node;
}

void print_list(struct node_t* head) {
  struct node_t* curr = head->next;
  int count = 0;
  while(curr != head) {
    printf("[%d] %d\n", count++, curr->val);
    curr = curr->next;
  }
}

void sort(struct node_t* head) {
  struct node_t* curr = head->next;

  while(curr->next != head) {
    struct node_t* next = curr->next;

    while(next != head) {
      if(curr->val > next->val) {
        int c = curr->val;
        curr->val = next->val;
        next->val = c;
      }
      next = next->next;
    }

    curr = curr->next;
  }
}

struct node_t* combine_lists(struct node_t* head1, struct node_t* head2) {
  struct node_t* combined = init_list();

  struct node_t* curr = head1->next;
  while(curr != head1) {
    add(combined, curr->val);
    curr = curr->next;
  }

  curr = head2->next;
  while(curr != head2) {
    add(combined, curr->val);
    curr = curr->next;
  }

  sort(combined);

  return combined;
}

int main() {
  struct node_t* l1 = init_list();
  add(l1, 3);
  add(l1, 7);
  add(l1, 5);
  add(l1, 1);
  add(l1, 9);
  add(l1, 11);

  struct node_t* l2 = init_list();
  add(l2, 12);
  add(l2, 4);
  add(l2, 3);
  add(l2, 2);
  add(l2, 10);
  add(l2, 8);

  puts("List 1:");
  print_list(l1);
  puts("List 2:");
  print_list(l2);

  struct node_t* combined = combine_lists(l1, l2);

  puts("Combined:");
  print_list(combined);

  return 0;
}
```


## В
[Условие](https://docs.google.com/document/d/1sNzoiEwZnVJqcEGDrOvu8tl_jeJIUMyNGKMU6w36fKQ/edit?usp=sharing)

### Задача 1
```c
#include <stdio.h>
#include <string.h>

struct truck_t {
  int max_load;
  char brand[21];
  char model[41];
};

struct company_t {
  char name[51];
  struct truck_t trucks[10];
  int truck_count;
};

void print_company(struct company_t company) {
  printf("%s (%d trucks)\n", company.name, company.truck_count);
  for(int i = 0; i < company.truck_count; i++) {
    struct truck_t truck = company.trucks[i];
    printf("%s %s (%dkg)\n", truck.brand, truck.model, truck.max_load);
  }
}

int main() {
  struct truck_t tr1 = {2000, "BMW", "Smal Truk"};
  struct truck_t tr2 = {20000, "BMW", "Big Truk"};
  struct truck_t tr3 = {200000, "VW", "Mega Truk"};

  struct company_t company;
  strcpy(company.name, "Elsys Cargo");
  company.truck_count = 3;
  company.trucks[0] = tr1;
  company.trucks[1] = tr2;
  company.trucks[2] = tr3;

  print_company(company);

  return 0;
}
```

### Задача 2
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct brick_t {
  int width;
  int height;
  char colour[21];
};

struct lego_set_t {
  char name[101];
  struct brick_t* bricks;
  int brick_count;
};

struct brick_t* create_brick(char colour[], int width, int height) {
  struct brick_t* new_brick = malloc(sizeof(struct brick_t));

  new_brick->width = width;
  new_brick->height = height;
  strcpy(new_brick->colour, colour);

  return new_brick;
}

void add_brick(struct lego_set_t* set, struct brick_t* brick) {
  set->bricks = realloc(set->bricks, sizeof(struct brick_t) * (set->brick_count + 1));
  set->bricks[set->brick_count] = *brick;
  set->brick_count++;
}

void print_set(struct lego_set_t set) {
  printf("%s (%d bricks)\n", set.name, set.brick_count);
  for(int i = 0; i < set.brick_count; i++) {
    struct brick_t brick = set.bricks[i];
    printf("%dx%d, %s\n", brick.width, brick.height, brick.colour);
  }
}

int main() {
  struct brick_t* br1 = create_brick("yellow", 1, 1);
  struct brick_t* br2 = create_brick("red", 1, 1);
  struct brick_t* br3 = create_brick("yellow", 1, 2);
  struct brick_t* br4 = create_brick("green", 2, 2);
  struct brick_t* br5 = create_brick("blue", 2, 4);

  struct lego_set_t set;
  strcpy(set.name, "House");
  set.brick_count = 0;
  set.bricks = NULL;

  add_brick(&set, br1);
  add_brick(&set, br2);
  add_brick(&set, br3);
  add_brick(&set, br4);
  add_brick(&set, br5);

  print_set(set);

  return 0;
}
```

### Задача 3
```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int val;
  struct node_t* prev;
  struct node_t* next;
};

struct node_t* init_list() {
  struct node_t* new_list = malloc(sizeof(struct node_t));

  new_list->val = 0;
  new_list->prev = new_list->next = new_list;

  return new_list;
}

void add(struct node_t* head, int val) {
  struct node_t* new_node = malloc(sizeof(struct node_t));

  new_node->val = val;
  new_node->prev = head->prev;
  new_node->next = head;

  head->prev->next = new_node;
  head->prev = new_node;
}

void print_list(struct node_t* head) {
  struct node_t* curr = head->next;
  int count = 0;
  while(curr != head) {
    printf("[%d] %d\n", count++, curr->val);
    curr = curr->next;
  }
}

int contains(struct node_t* head, int val) {
  struct node_t* curr = head->next;

  while(curr != head) {
    if(curr->val == val) {
      return 1;
    }
    curr = curr->next;
  }

  return 0;
}

struct node_t* combine_lists(struct node_t* head1, struct node_t* head2) {
  struct node_t* combined = init_list();

  struct node_t* curr = head1->next;
  while(curr != head1) {
    if(contains(head2, curr->val)) {
      add(combined, curr->val);
    }
    curr = curr->next;
  }

  return combined;
}

int main() {
  struct node_t* l1 = init_list();
  add(l1, 3);
  add(l1, 7);
  add(l1, 5);
  add(l1, 1);
  add(l1, 9);
  add(l1, 11);

  struct node_t* l2 = init_list();
  add(l2, 1);
  add(l2, 4);
  add(l2, 3);
  add(l2, 2);
  add(l2, 10);
  add(l2, 7);

  puts("List 1:");
  print_list(l1);
  puts("List 2:");
  print_list(l2);

  struct node_t* combined = combine_lists(l1, l2);

  puts("Combined:");
  print_list(combined);

  return 0;
}
```
