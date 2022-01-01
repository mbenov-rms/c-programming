#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "avl_tree.h"
#include "queue.h"

#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->data = data;
        new_node->factor = new_node->longest_branch = 0;
        new_node->left = new_node->right = new_node->parent = NULL;

        return new_node;
    }

    struct node_t ** subtree = NULL;

    if (data < tree->data) subtree = &tree->left;
    else if (data > tree->data) subtree = &tree->right;

    *subtree = add(*subtree, data);

    unsigned int left_length = tree->left ? tree->left->longest_branch + 1 : 0;
    unsigned int right_length = tree->right ? tree->right->longest_branch + 1 : 0;
    tree->longest_branch = max(left_length, right_length);
    tree->factor = right_length - left_length;

    if(abs(tree->factor) >= 2) {
      struct node_t *child1 = tree->factor > 0 ? tree->right : tree->left;
      struct node_t *child2 = child1->factor > 0 ? child1->right : child1->left;
      printf("need to rebalance %d-%d-%d\n", tree->data, child1->data, child2->data);
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
