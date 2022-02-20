#include <stdlib.h>

#include "bst.h"

struct tree_node_t* init_tree_node(void* value) {
  struct tree_node_t* new_node = malloc(sizeof(struct tree_node_t));

  new_node->value = value;
  new_node->left = new_node->right = NULL;

  return new_node;
}

struct tree_node_t* add_to_tree(struct tree_node_t* root, void* value) {
  if(root == NULL) {
    return init_tree_node(value);
  }

  // Add recursively
  if (value < root->value)
    root->left = add_to_tree(root->left, value);
  else if (value > root->value)
    root->right = add_to_tree(root->right, value);

  return root;
}

int has_in_tree(struct tree_node_t* root, void* value) {
  if(root == NULL) return 0;

  if(root->value == value) return 1;

  // Search recursively
  if (value < root->value)
    return has_in_tree(root->left, value);
  else
    return has_in_tree(root->right, value);
}

// https://www.techiedelight.com/deletion-from-bst/
struct tree_node_t* remove_from_tree(struct tree_node_t* root, void* value) {
  if(root == NULL) return root;

  // Delete the node and rearrange the children
  if(root->value == value) {
    // If the node has both children
    if(root->right != NULL && root->left != NULL) {
      // "move" the right node up
      root->value = root->right->value;
      // Recursively delete the right node and bubble its children up
      root->right = remove_from_tree(root->right, root->right->value);
      return root;
    }

    // If the node a single child just replace it with the child and delete the node
    struct tree_node_t* child = NULL;
    if(root->right != NULL)
      child = root->right;
    else if(root->left != NULL)
      child = root->left;

    free(root);
    return child;
  }

  // Search recursively
  if (value < root->value)
    root->left = remove_from_tree(root->left, value);
  else
    root->right = remove_from_tree(root->right, value);

  return root;
}
