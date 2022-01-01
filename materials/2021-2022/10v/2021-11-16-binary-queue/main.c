#include <stdio.h>
#include "bin_queue.h"

int main() {
  struct node_t* tree = add_to_tree(tree, 20);
  print_bfs(tree);

  tree = add_to_tree(tree, 10);
  print_bfs(tree);

  tree = add_to_tree(tree, 30);
  print_bfs(tree);

  tree = add_to_tree(tree, 50);
  print_bfs(tree);

  tree = add_to_tree(tree, 5);
  print_bfs(tree);

  tree = add_to_tree(tree, 25);
  print_bfs(tree);

  tree = add_to_tree(tree, 75);
  print_bfs(tree);

  tree = add_to_tree(tree, -20);
  print_bfs(tree);

  return 0;
}
