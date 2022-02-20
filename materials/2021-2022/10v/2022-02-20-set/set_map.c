#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "set.h"

#define BUCKET_COUNT 20

struct set_t {
  struct list_node_t** buckets;
  int count;
};

struct set_t* init_set() {
  struct set_t* new_set = malloc(sizeof(struct set_t));

  // Allocate and array of pointers and set them to NULL
  new_set->buckets = calloc(BUCKET_COUNT, sizeof(struct list_node_t*));
  new_set->count = 0;

  return new_set;
}

unsigned int hash_func(void* value) {
  long _value = (long)value;
  unsigned int result = 0;

  // Iterate all bytes
  for(int i = 0; i < sizeof(void*); i++) {
    // Use rightmost 8 bits
    result += (_value & 0xFF) * (i + 1);
    // Move 8 bits to the right
    _value >>= 8;
  }

  return result;
}

void add_to_set(struct set_t* set, void* value) {
  if(has_in_set(set, value)) return;

  unsigned int bucket_index = hash_func(value) % BUCKET_COUNT;

  set->buckets[bucket_index] = add_to_list(set->buckets[bucket_index], value);
  set->count++;
}

int has_in_set(struct set_t* set, void* value) {
  unsigned int bucket_index = hash_func(value) % BUCKET_COUNT;

  if(set->buckets[bucket_index] == NULL) return 0;

  return has_in_list(set->buckets[bucket_index], value);
}

void remove_from_set(struct set_t* set, void* value) {
  if(set->count <= 0) return;
  if(!has_in_set(set, value)) return;

  unsigned int bucket_index = hash_func(value) % BUCKET_COUNT;
  struct list_node_t* bucket = set->buckets[bucket_index];

  set->buckets[bucket_index] = remove_from_list(bucket, value);
  set->count--;
}

void print_all_in_set(struct set_t* set) {
  for(int bucket_index = 0; bucket_index < BUCKET_COUNT; bucket_index++) {
    struct list_node_t* bucket = set->buckets[bucket_index];

    if(bucket == NULL) {
      printf("[%.2d] empty\n", bucket_index);
      continue;
    }

    struct list_node_t* curr = bucket;
    for(int i = 0; curr != NULL; i++, curr = curr->next) {
      printf("[%.2d] [%.2d] %p\n", bucket_index, i, curr->value);
    }
  }
}
