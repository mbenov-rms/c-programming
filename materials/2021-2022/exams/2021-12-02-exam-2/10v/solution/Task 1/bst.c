#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "queue.h"

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->data = data;
        new_node->left = new_node->right = NULL;

        return new_node;
    }

    if (data < tree->data) {
      if(tree->left == NULL) {
        if((tree->data + data) % 2 == 0 || abs(tree->data - data) <= 2) {
          tree->left = add(tree->left, data);
        }
      } else {
        tree->left = add(tree->left, data);
      }
    }
    else if (data > tree->data) {
      if(tree->right == NULL) {
        if((tree->data + data) % 2 == 0 || abs(tree->data - data) <= 2) {
          tree->right = add(tree->right, data);
        }
      } else {
        tree->right = add(tree->right, data);
      }
    }

    return tree;
}

void print_bfs(struct node_t* tree) {
  struct queue_t * queue = queue_push(NULL, tree);
  struct queue_t * buffer = NULL;

  while(queue != NULL) { // iterate over all levels
    while(queue != NULL) { // iterate the current level
      struct node_t *curr_node = queue->node;
      queue = queue_pop(queue);

      if(curr_node != NULL) {
        printf("%d ", curr_node->data);

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
