#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node_t {
  int value;
  struct node_t *next;
};

struct node_t* add(struct node_t *head, int value);
struct node_t* reverse(struct node_t *head);

#endif
