#include <stdlib.h>
#include <stdio.h>

#include "binary_tree.h"
#include "queue.h"

struct node_t* add(struct node_t* tree, int value) {
  if (tree == NULL) {
    struct node_t* new_node = malloc(sizeof(struct node_t));
    new_node->value = value;
    new_node->left = new_node->right = NULL;

    return new_node;
  }

  if (value < tree->value) {
    tree->left = add(tree->left, value);
  }
  else if (value > tree->value) {
    tree->right = add(tree->right, value);
  }

  return tree;
}

// Assume the tree is a balanced BST
// O(n) = n * log(log(n))
// Number of items in the tree is n. Maximum length of a branch in a balanced BST is log(n).
// Need to traverse all elements and for each element might need to traverse an additional branch, but branch length is log(n) only for the root and every other branch is shorter.
struct node_t* remove_too_small(struct node_t *root) {
  if(root == NULL) return NULL;

  root->left = remove_too_small(root->left);
  root->right = remove_too_small(root->right);

  int child_sum = (root->left ? root->left->value : 0) + (root->right ? root->right->value : 0);
  //printf("%d %d\n", root->value, child_sum);
  if(root->value < child_sum * 2) {
    //printf("Remove %d\n", root->value);
    struct node_t *tmp = root;

    // Simplified tree rotation. Assume at least 1 branch exists
    if(root->left == NULL) {
      // Move the right subtree up
      root = root->right;
    } else if(root->right == NULL) {
      // Move the left subtree up
      root = root->left;
    } else {
      // Transfer the right branch of the left subtree to the right subtree
      if(root->left->right != NULL) {
        struct node_t *right_finder = root->right;
        while(right_finder->left != NULL) right_finder = right_finder->left;
        right_finder->left = root->left->right;
      }
      // Move the right subtree to be a right branch of the left subtree
      root->left->right = root->right;
      // Move the left subtree up
      root = root->left;
    }

    free(tmp);
  }

  return root;
}

void print_bfs(struct node_t* tree) {
  struct queue_t * queue = queue_push(NULL, tree);
  struct queue_t * buffer = NULL;

  while(queue != NULL) { // iterate over all levels
    while(queue != NULL) { // iterate the current level
      struct node_t *curr_node = queue->node;
      queue = queue_pop(queue);

      if(curr_node != NULL) {
        printf("%d ", curr_node->value);

        buffer = queue_push(buffer, curr_node->left);
        buffer = queue_push(buffer, curr_node->right);
      }
    }
    puts(""); // new line after the level
    queue = buffer;
    buffer = NULL;
  }

  puts("");
}
