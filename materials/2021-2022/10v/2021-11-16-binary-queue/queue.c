#include <stdlib.h>

#include "queue.h"

struct queue_t * queue_push(struct queue_t *queue, struct node_t *node) {
  struct queue_t *new_node = malloc(sizeof(struct queue_t));
  new_node->next = NULL;
  new_node->node = node;

  if(queue == NULL) {
    return new_node;
  }

  struct queue_t *curr = queue;
  while(curr->next != NULL) curr = curr->next;
  curr->next = new_node;

  return queue;
}

struct queue_t * queue_pop(struct queue_t *queue) {
  if(queue == NULL) {
    return NULL;
  }

  struct queue_t * old_head = queue;
  queue = queue->next;

  free(old_head);

  return queue;
}
