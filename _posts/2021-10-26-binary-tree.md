---
title: Лекция 07 - Двоично дърво
category: новини
tags:
  - лекции
  - материали
---

[Wikipedia](https://en.wikipedia.org/wiki/Binary_search_tree)

[Индиец в Youtube](https://www.youtube.com/watch?v=H5JubkIy_p8)

[Stanford](http://cslibrary.stanford.edu/110/BinaryTrees.html)


## Код от час
### В клас

```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int data;
  struct node_t *left;
  struct node_t *right;
};

struct node_t *add(struct node_t *tree, int data) {
  if(tree == NULL) {
    struct node_t *new_node = malloc(sizeof(struct node_t));
    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
  }

  /*struct node_t *curr = tree;
  while(curr != NULL) {
    if(data < curr->data) curr = curr->left;
    else if(data > curr->data) curr = curr->right;

    //if(curr == NULL) break;
  }

  curr = new_node;*/
  if(data < tree->data) {
    tree->left = add(tree->left, data);
  } else if(data > tree->data) {
    tree->right = add(tree->right, data);
  }

  return tree;
}

void print_tree(struct node_t *tree) {
  if(tree == NULL) return;

  printf("%d\n", tree->data);

  print_tree(tree->left);
  print_tree(tree->right);

}

int main() {
  struct  node_t *tree = add(NULL, 13);
  tree = add(tree, 4);
  tree = add(tree, 2);
  tree = add(tree, 7);
  tree = add(tree, 17);
  tree = add(tree, 53);
  tree = add(tree, 41);
  tree = add(tree, 42);
  tree = add(tree, 69);

  print_tree(tree);
  return 0;
}
```
