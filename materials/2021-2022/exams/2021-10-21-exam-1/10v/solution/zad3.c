#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  struct node_t *next, *prev;
  struct node_t *s_next, *s_prev;
};

struct node_t* init_node(int value) {
  struct node_t *new_node = malloc(sizeof(struct node_t));
  
  new_node->value = value;
  new_node->next = new_node->prev = NULL;
  new_node->s_next = new_node->s_prev = NULL;
  
  return new_node;
}

// Insert a new node. 
// Point next and prev as a new head.
// Point s_next and s_prev in ascending order from left to right.
struct node_t* add_node(struct node_t *list, int value) {
  struct node_t *new_node = init_node(value);
  
  // The list is empty so just return the node
  if(list == NULL) return new_node;
  
  // Insert the new node as the new head
  list->prev = new_node;
  new_node->next = list;
  
  // list can be anywhere in the sorted list. Find the correct place to put the new item
  struct node_t *curr = list;
  if(curr->value < value) {
    // Stop when we reach the end of the list
    // OR the new value is between curr and curr->next
    while(curr->s_next != NULL && curr->s_next->value < value) 
      curr = curr->s_next;  
      
    // Insert between curr and curr->next
    new_node->s_next = curr->s_next;
    new_node->s_prev = curr;
    if(curr->s_next != NULL)
      curr->s_next->s_prev = new_node;
    curr->s_next = new_node;
  } else {
    // Stop when we reach the start of the list
    // OR the new value is between curr and curr->prev
    while(curr->s_prev != NULL && curr->s_prev->value > value)
      curr = curr->s_prev;
      
    // Insert between curr->prev and curr
    new_node->s_next = curr;
    new_node->s_prev = curr->s_prev;
    if(curr->s_prev != NULL)
      curr->s_prev->s_next = new_node;
    curr->s_prev = new_node;
  }
  
  return new_node;
}

void print_as_added(struct node_t *list) {
  struct node_t *curr = list;
  while(curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  puts("");
}

void print_as_sorted(struct node_t *list) {
  struct node_t *curr = list;
  
  // We don't store the sorted head so we need to find it
  while(curr->s_prev != NULL) 
    curr = curr->s_prev;
  
  while(curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->s_next;
  }
  puts("");
}

int main() {
  struct node_t *list = add_node(NULL, 5);
  list = add_node(list, 1);
  list = add_node(list, 8);
  list = add_node(list, 4);
  list = add_node(list, 7);
  
  print_as_added(list);
  print_as_sorted(list);
  
  return 0;
}
