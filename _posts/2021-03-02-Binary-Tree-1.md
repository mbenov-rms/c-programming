---
title: Лекция 15 - Бинарно дърво 1
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

struct node_t {
  int value;
  struct node_t* left;
  struct node_t* right;
};

void insert(struct node_t* tree, int value) {
  struct node_t* new_node =
    malloc(sizeof(struct node_t));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  struct node_t** branch;
  if(value > tree->value) {
    // right
    branch = &tree->right;
    /*if(tree->right == NULL) {
      tree->right = new_node;
    } else {
      insert(tree->right, value);
    }*/
  } else {
    // left
    branch = &tree->left;
    /*if(tree->left == NULL) {
      tree->left = new_node;
    } else {
      insert(tree->left, value);
    }*/
  }

  if(*branch == NULL) {
    *branch = new_node;
  } else {
    insert(*branch, value);
  }
}

void print_tree(struct node_t* root, int level) {
  if(root == NULL) return;

  printf("[%d] %d", level, root->value);

  if(root->left != NULL || root->right != NULL) {
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
    //puts("\n");
  }  
}

int main() {
  struct node_t n1 = {8, NULL, NULL};
  //struct node_t n2 = {13, NULL, NULL};
  //struct node_t n3 = {5, NULL, NULL};

  //n1.left = &n3;
  //n1.right = &n2;
  insert(&n1, 13);
  insert(&n1, 5);
  insert(&n1, 2);
  insert(&n1, 7);
  insert(&n1, 3);

  print_tree(&n1, 0);

  return 0;
}
```
