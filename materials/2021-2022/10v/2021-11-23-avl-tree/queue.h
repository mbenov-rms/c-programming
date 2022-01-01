#pragma once
#include "avl_tree.h"

struct queue_t {
  struct queue_t *next;
  struct node_t *node;
};

struct queue_t * queue_push(struct queue_t *queue, struct node_t *node);
struct queue_t * queue_pop(struct queue_t *queue);
