---
title: Лекция 20 - Бинарно дърво 5
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

//
// Print
//
void print_tree(struct node_t* root, int level, char branch) {
  if(root == NULL) return;

  printf("[%c %d] %d ", branch, level, root->value);
  if(root->left != NULL || root->right != NULL) {
    print_tree(root->left, level + 1, 'L');
    print_tree(root->right, level + 1, 'R');
  }  
}

// Return 1 if the tree has more levels below the target level. Return 0 if it does not
int print_tree_bfs_recursive(struct node_t* root, int target_level, int curr_level) {
  if(root == NULL) {
      printf("[%d] - ", curr_level);
      return 0;
  }
  // If the current node is at the level we want - print it and return
  if(curr_level == target_level) {
    printf("[%d] %d ", curr_level, root->value);
    // Are there more levels below the current one?
    return root->left != NULL || root->right != NULL;
  }

  // Else call recursively for the child nodes
  int has_more_left = print_tree_bfs_recursive(root->left, target_level, curr_level + 1);
  int has_more_right = print_tree_bfs_recursive(root->right, target_level, curr_level + 1);

  // Finished iterating the child subtrees. Are there more levels below the target level?
  return has_more_left || has_more_right;
}

// Helper function to push nodes in the back of a list
struct list_node_t* push_back_in_list(struct list_node_t* list, struct node_t* node) {
    struct list_node_t* new_list_node = malloc(sizeof(struct list_node_t));
    new_list_node->node = node;

    if(list == NULL) return new_list_node;

    struct list_node_t* curr = list;
    while(curr->next != NULL) curr = curr->next;
    curr->next = new_list_node;

    return list;
}

// Use a list of nodes as a queue - pop from the front and push in the back
// node_number instead of curr_level because with this implementation
// we don't know about levels
void print_tree_bfs_recursive_with_queue(struct node_t* root, struct list_node_t* queue, int node_number) {
  if(root == NULL) {
      printf("[%d] - ", node_number);
      return;
  }

  printf("[%d] %d ", node_number, root->value);

  // Add the child nodes at the end of the queue
  queue = push_back_in_list(queue, root->left);
  queue = push_back_in_list(queue, root->right);

  // If the queue is NULL, i.e. empty, then there are no more nodes to iterate over
  if(queue != NULL) {
      // Take the first element in the queue. It is either the next one in the urrnet level
      // or the first one in the next level
      struct node_t* next = queue->node;
      // "pop" the first element in the queue - simply reassign the pointer to the second element
      queue = queue->next;

      print_tree_bfs_recursive_with_queue(next, queue, node_number + 1);
  }
}

// BFS but iterative instead of recursive
void print_tree_bfs_iterative(struct node_t* root) {
  if(root == NULL) return;

  // Start a queue with only the root node
  struct list_node_t* queue = push_back_in_list(NULL, root);
  int curr_level = 0;

  // When the queue runs out of nodes then we're done iterating
  while(queue != NULL) {
    // Start a second list as a helper
    struct list_node_t* new_list = NULL;

    // Iterate over all elements in the current queue
    // i.e. all elements in the current level
    while(queue != NULL) {
        // Take the first element in the queue
        struct node_t* curr = queue->node;

        if(curr == NULL) {
            // It's empty
            printf("[%d] - ", curr_level);
        } else {
            // If it has children - add them to the queue for the next level
            if(curr->left != NULL || curr->right != NULL) {
                new_list = push_back_in_list(new_list, curr->left);
                new_list = push_back_in_list(new_list, curr->right);
            }

            printf("[%d] %d ", curr_level, curr->value);
        }

        // Go to the next element in the queue
        queue = queue->next;
    }

    // Switch the queue for the new one for the next level
    queue = new_list;
    curr_level++;
    puts("");
  }
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
  puts("Print with DFS");
  print_tree(balanced_tree, 0, ' ');
  puts("\n");

  puts("Print with BFS recursive");
  int level = 0;
  while(print_tree_bfs_recursive(balanced_tree, level++, 0)) {
      puts("");
  }
  puts("\n");

  puts("Print with BFS recursive with a queue");
  print_tree_bfs_recursive_with_queue(balanced_tree, NULL, 0);
  puts("\n");

  puts("Print with BFS iterative with queue");
  print_tree_bfs_iterative(balanced_tree);
  puts("");

  return 0;
}
```
