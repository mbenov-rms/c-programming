#include <stdio.h>

#include "avl_tree.h"

int main() {
  struct node_t *tree = NULL;

  tree = add(tree, 8);
  print_tree(tree);
  tree = add(tree, 6);
  print_tree(tree);
  tree = add(tree, 4);
  print_tree(tree);

  return 0;
}
