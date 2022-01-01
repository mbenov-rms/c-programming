---
title: Лекция 18 - Бинарно дърво 3
category: новини
tags:
  - лекции
  - материали
---

### Код от час

#### А клас
```c
```

#### Б клас
```c
```

#### В клас
```c
#include <stdio.h>
#include <stdlib.h>

struct point_t {
  int x;
  int y;
};

struct node_t {
  struct point_t* points;
  int point_count;
  struct node_t* left;
  struct node_t* right;
};

void sort_points(struct point_t* points, int size)  {
  for(int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j < size; j++) {
      if(points[i].x > points[j].x) {
        struct point_t temp = points[i];
        points[i] = points[j];
        points[j] = temp;
      }
    }
  }
}
/*
?? insert(??) {
  ??
}
*/

struct node_t* init_node() {
  struct node_t* new_node = malloc(sizeof(struct node_t));

  new_node->points = NULL;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->point_count = 0;

  return new_node;
}

struct node_t* build_tree(struct point_t* points, int size, int limit) {
  sort_points(points, size);

  struct node_t* root = init_node();

  if(size <= limit) {
    root->points = realloc(root->points, sizeof(struct point_t) * size);
    for(int i = 0; i < size; i++) {
      root->points[i] = points[i]; // put in left
    }
    root->point_count = size;

    return root;
  }

  int half = size/2;
  root->left = build_tree(points, half, limit);
  root->right = build_tree(points +half, size - half, limit);

  /*
  //root->left->points = malloc(sizeof(struct point_t)* half);
  root->left->points = realloc(root->left->points, sizeof(struct point_t) * half);
  for(int i = 0; i < half; i++) {
    root->left->points[i] = points[i]; // put in left
  }
  root->left->point_count = half;

  root->right->points = realloc(root->right->points, sizeof(struct point_t) * (size - half));
  for(int i = half; i < size; i++) {
    root->right->points[i - half] = points[i]; // put in right
  }
  root->right->point_count = size - half;
  */
  return root;
}

void print_tree(struct node_t* root, int level) {
  if(root == NULL) return;

  printf("[%d] %d", level, root->point_count);

  if(root->left != NULL || root->right != NULL) {
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
    //puts("\n");
  }  
}



int main() {
  struct point_t points[] = {
    {1, 2},
    {2, 2},
    {7, 3},
    {5, 9},
    {4, 1}
  };

  struct node_t* root = build_tree(points, 5, 1);
  print_tree(root, 0);

  return 0;
}
```
