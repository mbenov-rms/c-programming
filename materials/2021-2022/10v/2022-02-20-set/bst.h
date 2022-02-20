#pragma once

struct tree_node_t {
  struct tree_node_t* left;
  struct tree_node_t* right;
  void* value;
};

struct tree_node_t* init_tree_node(void* value);

struct tree_node_t* add_to_tree(struct tree_node_t* root, void* value);

int has_in_tree(struct tree_node_t* root, void* value);

struct tree_node_t* remove_from_tree(struct tree_node_t* root, void* value);
