#include <stdlib.h>

#include "linked_list.h"

struct node_t* add(struct node_t *head, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->next = NULL;
  new_node->value = value;

  if(head == NULL) {
    return new_node;
  }

  struct node_t* curr = head;
  while(curr->next != NULL) curr = curr->next;

  curr->next = new_node;
  return head;
}

// O(n)
// Traverse the list once and build a new list by swapping pointers.
struct node_t* reverse(struct node_t *head) {
  if(head == NULL) return NULL;

  struct node_t *curr = head;
  struct node_t *new_list = NULL;

  while(curr != NULL) {
    struct node_t *tmp = curr->next;

    curr->next = new_list;
    new_list = curr;

    curr = tmp;
  }

  return new_list;
}
