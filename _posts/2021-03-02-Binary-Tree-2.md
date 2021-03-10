---
title: Лекция 16 - Бинарно дърво 2
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

int tree_contains(struct node_t* root, int value, int level) {
  printf("Search for %d in [%d] %d \n", value, level, root->value);

  if(root->value == value) {
    return 1;
  }

  if(root->left != NULL && value < root->value ) {
    return tree_contains(root->left, value, level + 1);
  }

  if(root->right != NULL && value > root->value ) {
    return tree_contains(root->right, value, level + 1);
  }

  return 0;
}

struct list_node_t {
  struct node_t* node;
  struct list_node_t* next;
};

struct list_node_t* get_nodes(struct node_t* root) {
  if(root == NULL) return NULL;

  struct list_node_t* new_node = malloc(sizeof(struct list_node_t));
  new_node->node = root;

  new_node->next = get_nodes(root->left);
  struct list_node_t* last_node = new_node;
  while(last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = get_nodes(root->right);

  return new_node;
}

void sort_list(struct list_node_t* head) {
  struct list_node_t* curr = head;
  while(curr->next != NULL) {
    struct list_node_t* other = curr->next;
    while(other != NULL) {
      if(curr->node->value < other->node->value) {
        struct node_t* temp = curr->node;
        curr->node = other->node;
        other->node = temp;
      }

      other = other->next;
    }
    curr = curr->next;
  }
}

int get_list_length(struct list_node_t* head) {
  int length = 0;
  struct list_node_t* last_node = head;
  while(last_node != NULL) {
    length++;
    last_node = last_node->next;
  }
  return length;
}

struct list_node_t* get_list_at(struct list_node_t* head, int pos) {
  int index = 0;
  struct list_node_t* last_node = head;
  while(index != pos) {
    index++;
    last_node = last_node->next;
  }
  return last_node;
}

struct node_t* balance_tree(struct node_t* root) {
  struct list_node_t* nodes = get_nodes(root);
  sort_list(nodes);
  int list_length = get_list_length(nodes);
  struct list_node_t* middle = get_list_at(nodes, list_length / 2);

  printf("%d\n", middle->node->value);

  /*struct list_node_t* last_node = nodes;
  while(last_node != NULL) {
    printf("%d ", last_node->node->value);
    last_node = last_node->next;
  }*/


  return root;
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

  puts("\n\n");

  printf("%d\n", tree_contains(&n1, 7, 0));
  printf("%d\n", tree_contains(&n1, 25, 0));

  balance_tree(&n1);

  return 0;
}

```
