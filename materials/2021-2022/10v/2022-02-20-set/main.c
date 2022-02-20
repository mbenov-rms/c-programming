#include <stdio.h>
#include <stdlib.h>

#include "set.h"

int main() {
  srand(0);

  struct set_t* s = init_set();

  for(int i = 0; i < 10000; i++) {
    long val = rand();
    add_to_set(s, (void*)val);
  }

  for(int i = 0; i < 10000; i++) {
    long val = rand();
    has_in_set(s, (void*)val);
  }

  for(int i = 0; i < 10000; i++) {
    long val = rand();
    remove_from_set(s, (void*)val);
  }

  // add_to_set(s, (void*)4);
  // add_to_set(s, (void*)40);
  // add_to_set(s, (void*)-4);
  // add_to_set(s, (void*)-40);
  // add_to_set(s, (void*)400);
  //
  // printf("%d\n", has_in_set(s, (void*)40));
  // printf("%d\n", has_in_set(s, (void*)50));
  //
  // remove_from_set(s, (void*)40);
  // printf("%d\n", has_in_set(s, (void*)40));
  //
  // print_all_in_set(s);

  return 0;
}
