#include <stdlib.h>
#include <stdio.h>

#include "set.h"

struct set_t {
  void** items;
  int count;
};

struct set_t* init_set() {
  struct set_t* new_set = malloc(sizeof(struct set_t));

  new_set->items = NULL;
  new_set->count = 0;

  return new_set;
}

void add_to_set(struct set_t* set, void* value) {
  if(has_in_set(set, value)) return;

  set->count++;
  set->items = realloc(set->items, sizeof(void*) * set->count);
  set->items[set->count - 1] = value;
}

int has_in_set(struct set_t* set, void* value) {
  for(int i = 0; i < set->count; i++) {
    if(set->items[i] == value) return 1;
  }

  return 0;
}

void remove_from_set(struct set_t* set, void* value) {
  if(set->count <= 0) return;
  if(!has_in_set(set, value)) return;

  for(int i = 0; i < set->count; i++) {
    if(set->items[i] == value) {
      // Move all other items to the left
      for(; i < set->count - 1; i++)
        set->items[i] = set->items[i + 1];

      set->count--;

      return;
    }
  }
}

void print_all_in_set(struct set_t* set) {
  for(int i = 0; i < set->count; i++) {
    printf("[%.2d] %p\n", i, set->items[i]);
  }
}
