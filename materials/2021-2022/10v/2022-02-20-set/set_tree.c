#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "list.h"
#include "set.h"

struct set_t {
  struct tree_node_t* root;
  int count;
};

struct set_t* init_set() {
  struct set_t* new_set = malloc(sizeof(struct set_t));

  new_set->root = NULL;
  new_set->count = 0;

  return new_set;
}

void add_to_set(struct set_t* set, void* value) {
  if(has_in_set(set, value)) return;

  set->count++;
  set->root = add_to_tree(set->root, value);
}

int has_in_set(struct set_t* set, void* value) {
  return has_in_tree(set->root, value);
}

void remove_from_set(struct set_t* set, void* value) {
  if(set->count <= 0) return;
  if(!has_in_set(set, value)) return;

  set->root = remove_from_tree(set->root, value);
}

void print_all_in_set(struct set_t* set) {
  int i = 0;
  // Use a list like a basic stack with push and pop from the front
  struct list_node_t* nodes = add_to_list(NULL, set->root);
  while(nodes != NULL) {
    struct tree_node_t* root = nodes->value;
    nodes = remove_from_list(nodes, root);

    if(root->left != NULL)
      nodes = add_to_list(nodes, root->left);
    if(root->right != NULL)
      nodes = add_to_list(nodes, root->right);

    printf("[%.2d] %p\n", i++, root->value);
  }
}
