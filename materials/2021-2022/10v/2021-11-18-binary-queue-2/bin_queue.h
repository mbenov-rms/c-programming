#ifndef BIN_QUEUE_H
#define BIN_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int data;

  struct node_t *left;
  struct node_t *right;
  struct node_t *parent;
  unsigned int child_count;
};

struct node_t* create_node(int data);
struct node_t* add_to_tree(struct node_t* tree, int data);
struct node_t* remove_from_tree(struct node_t* tree, int *data);
void print_tree(struct node_t *tree);
void print_bfs(struct node_t* tree);
void adjust_node_chain(struct node_t* node);

#endif
