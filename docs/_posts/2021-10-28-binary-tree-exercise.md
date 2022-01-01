---
title: Упражнение 07 - Двоично дърво
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

struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
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
    if (data < tree->data) {
        tree->left = add(tree->left, data);
    }
    else if (data > tree->data) {
        tree->right = add(tree->right, data);
    }

    return tree;
}

struct node_t* remove(struct node_t* tree, int data)
{
    if (tree == NULL) return NULL;
    if (data == tree->data)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            tree = NULL;
            return tree;
        }

        if (tree->left && tree->right)
        {
            free(tree);
            tree = tree->right;

            return tree;
        }

        if (tree->left && tree->right == NULL)
        {
            free(tree);
            tree = tree->left;
            return tree;
        }

        if (tree->left == NULL && tree->right)
        {
            free(tree);
            tree = tree->right;
            return tree;
        }


    }

    if (data < tree->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}


int cnt_elements(struct node_t* tree)
{
    if (tree == NULL) return 0;
    return cnt_elements(tree->left)+cnt_elements(tree->right)+1;
}

int search(struct node_t* tree,int data)
{
    if (tree == NULL)
        return 0;

    if (data == tree->data)
        return 1;
    if (data < tree->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}

void print_tree(struct node_t* tree) {
    if (tree == NULL) return;

    printf("%d\n", tree->data);

    print_tree(tree->left);
    print_tree(tree->right);

}

int main() {
    struct  node_t* tree = add(NULL, 13);
    tree = add(tree, 4);
    tree = add(tree, 2);
    tree = add(tree, 7);
    tree = add(tree, 17);
    tree = add(tree, 53);
    tree = add(tree, 41);
    tree = add(tree, 42);
    tree = add(tree, 69);

    printf("%d ", search(tree,17));
    printf("%d ", search(tree, 41));
    printf("%d ", search(tree, 44));

    printf("%d ", cnt_elements(tree));

    print_tree(tree);
    return 0;
}
```
