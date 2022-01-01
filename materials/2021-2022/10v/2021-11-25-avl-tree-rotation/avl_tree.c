#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "avl_tree.h"
#include "queue.h"

// Conveniece to compare 2 numbers and pick the larger
#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

// The items to rotate are root->right->right and need to rotate to the left
struct node_t* rotate_left(struct node_t* tree) {
  puts("rotate left");

  struct node_t *temp = tree->right;

  temp->parent = tree->parent;
  tree->parent = temp;
  tree->right = temp->left;
  temp->left = tree;

  return temp;
}

// The items to rotate are root->left->left and need to rotate to the right
struct node_t* rotate_right(struct node_t* tree) {
  puts("rotate right");

  struct node_t *temp = tree->left;

  temp->parent = tree->parent;
  tree->parent = temp;
  tree->left = temp->right;
  temp->right = tree;

  return temp;
}

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->data = data;
        new_node->factor = new_node->longest_branch = 0;
        new_node->left = new_node->right = new_node->parent = NULL;

        return new_node;
    }

    // Pointer to the left or right pointer attribute in the tree node. Used to reduce code repetition.
    // *subtree will let us point the actual attribute instead of just modifying the pointed value.
    struct node_t ** subtree = NULL;

    // Point subtree to the correct subtree attribute in the node
    if (data < tree->data) subtree = &tree->left;
    else if (data > tree->data) subtree = &tree->right;

    // Add the new value in the correct branch
    *subtree = add(*subtree, data);

    /*struct node_t * subtree = NULL;
    if(data < tree->data) {
      tree->left = add(tree->left, data);
      subtree = tree->left;
      subtree = add(subtree, data);
    } else ...*/

    // Branch length is 0 if empty or the branch length of the child + 1 for the child itself
    unsigned int left_length = tree->left ? tree->left->longest_branch + 1 : 0;
    unsigned int right_length = tree->right ? tree->right->longest_branch + 1 : 0;
    tree->longest_branch = max(left_length, right_length);
    // factor is 0 if lengths are equal, negative if left is longer, positive if right is longer
    tree->factor = right_length - left_length;

    // A factor of 2 means the tree is not balanced
    if(abs(tree->factor) >= 2) {
      struct node_t *child1 = tree->factor > 0 ? tree->right : tree->left;
      struct node_t *child2 = child1->factor > 0 ? child1->right : child1->left;
      printf("need to rotate %d-%d-%d\n", tree->data, child1->data, child2->data);

      // Negative means the left side is longer and needs to be rotated
      if(tree->factor < 0) {
        if(tree->left->factor < 0) {
          // Items are in a straight line and the rotation is simple
          tree = rotate_right(tree);
        } else {
          // Items are not in a straight line and need to make a complex rotation
          puts("zigzag right");
        }
      // Positive means the right side is longer
      } else {
        if(tree->right->factor > 0) {
          // Items are in a straight line and the rotation is simple
          tree = rotate_left(tree);
        } else {
          // Items are not in a straight line and need to make a complex rotation
          puts("zigzag left");
        }
      }
    }

    return tree;
}

void print_tree(struct node_t* tree) {
  struct queue_t * queue = queue_push(NULL, tree);
  struct queue_t * buffer = NULL;

  while(queue != NULL) { // iterate over all levels
    while(queue != NULL) { // iterate the current level
      struct node_t *curr_node = queue->node;
      queue = queue_pop(queue);

      if(curr_node != NULL) {
        printf("%d (%d,%d) ", curr_node->data, curr_node->factor, curr_node->longest_branch);

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
