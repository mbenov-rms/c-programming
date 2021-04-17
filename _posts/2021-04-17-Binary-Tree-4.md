---
title: Лекция 19 - Бинарно дърво 4
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
    branch = &tree->right;
  } else {
    branch = &tree->left;
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

void print_tree(struct node_t* root, int level, char branch) {
  if(root == NULL) return;

  printf("[%c %d] %d ", branch, level, root->value);

  if(root->left != NULL || root->right != NULL) {
    print_tree(root->left, level + 1, 'L');
    print_tree(root->right, level + 1, 'R');
  }  
}


//
// Helper list structure
//
struct list_node_t {
  struct node_t* node;
  struct list_node_t* next;
};

struct list_node_t* gather_nodes(struct node_t* root) {
  if(root == NULL) return NULL;

  struct list_node_t* node = malloc(sizeof(struct list_node_t));

  node->node = root;
  node->next = gather_nodes(root->left);

  struct list_node_t* last = node;
  while(last->next != NULL) last = last->next;
  last->next = gather_nodes(root->right);

  return node;
}

void sort_list(struct list_node_t* head) {
  struct list_node_t* curr = head;
  while(curr->next != NULL) {
    struct list_node_t* other = curr->next;
    while(other != NULL) {
      if(curr->node->value > other->node->value) {
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

//
// Balance the tree
//
struct node_t* build_tree_from_list(struct list_node_t* list) {
  int list_length = get_list_length(list);
  int mid_index = list_length / 2;

  struct list_node_t* mid = get_list_at(list, mid_index);
  struct node_t* new_root = mid->node;

  if(mid_index > 0) {
    struct list_node_t* left_half = list; // left half of the list [start, mid)

    struct list_node_t* curr = left_half;
    while(curr->next != mid) {
      curr = curr->next;
    }
    curr->next = NULL; // "cut off" the left half

    new_root->left = build_tree_from_list(left_half);
  } else {
    new_root->left = NULL;
  }

  if(mid_index + 1 < list_length) {
    struct list_node_t* right_half = mid->next; // right half of the list (mid, end]
    mid->next = NULL; // "cut off" the right half

    new_root->right = build_tree_from_list(right_half);
  } else {
    new_root->right = NULL;
  }

  return new_root;
}

struct node_t* balance_tree(struct node_t* root) {
  struct list_node_t* nodes = gather_nodes(root);
  sort_list(nodes);

  return build_tree_from_list(nodes);
}


int main() {
  struct node_t n1 = {8, NULL, NULL};

  insert(&n1, 13);
  insert(&n1, 5);
  insert(&n1, 2);
  insert(&n1, 7);
  insert(&n1, 3);

  puts("Initial tree:");
  print_tree(&n1, 0, ' ');

  struct node_t* balanced_tree = balance_tree(&n1);
  puts("\n\nTree after balancing:");
  print_tree(balanced_tree, 0, ' ');
  puts("\n");

  return 0;
}
```
