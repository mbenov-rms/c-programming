#include <stdlib.h>

struct item_t {
  char* title;
  short important;
  short urgency;
};

struct list_t {
  struct list_t* next;
  struct list_t* prev;
  struct item_t* item;
};

void add(struct list_t* list, struct item_t* item) {
  if(list->item == NULL) {
    list->item = item;
    return;
  }

  while(list->next != NULL) {
    list = list->next;
  }

  list->next = malloc(sizeof(struct list_t));
  if(list->next == NULL) {
    return;
  }

  list->next->next = NULL;
  list->next->prev = list;

  list->next->item = item;
}

int main() {
  struct list_t l = {NULL, NULL, NULL};
  struct item_t i = {
    "asdf",
    1,
    1
  };
  add(&l, &i);
  return 0;
}
