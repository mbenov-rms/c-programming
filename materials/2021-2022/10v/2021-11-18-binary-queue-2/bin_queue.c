#include <stdio.h>
#include <stdlib.h>

#include "bin_queue.h"
#include "queue.h"

struct node_t* create_node(int data) {
  struct node_t* new_node = malloc(sizeof(struct node_t));

  new_node->child_count = 0;
  new_node->data = data;
  new_node->left = new_node->right = new_node->parent = NULL;

  return new_node;
}

// 32 bit integer, leftmost bit is 1 and everything else is 0
// The value should be 2147483648
unsigned int leftmost_mask = 1 << ((sizeof(unsigned int) * 8) - 1);

// Taken from https://stackoverflow.com/a/27627015
void print_binary(unsigned int number) {
  if (number >> 1) {
    print_binary(number >> 1);
  }
  putc((number & 1) ? '1' : '0', stdout);
}

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void adjust_node_chain(struct node_t* node) {
  if(node == NULL) return;

  while(node->parent != NULL && node->data > node->parent->data) {
    swap(&node->data, &node->parent->data);
    node = node->parent;
  }
}
/*
struct node_t* add_to_tree(struct node_t* tree, int data) {
  struct node_t* new_node = create_node(data);
  if(tree == NULL) return new_node;

  // The consecutive number of the new element, i.e. the total number of nodes in the tree after adding
  // will give us the path to follow. Total nodes = root->child_count + 1(root) + 1(new node)
  unsigned int bit_path = tree->child_count + 2;
  // The number of levels in the tree. depth = 0 means the new node will bea child of the root
  short depth = 0;

  printf("bit path: ");
  print_binary(bit_path);
  puts("");

  // shift left until a 1 bit reaches the leftmost position
  while((bit_path & leftmost_mask) == 0) {
    depth++;
    bit_path <<= 1;
  }
  // Shift again to drop a single 1 bit which corresponds to the root
  bit_path <<= 1;
  // depth = <number of left shifts> - <bit size of the type used>
  depth = (sizeof(unsigned int) * 8) - depth - 2;

  printf("path depth: %u, tree size: %u \n", depth, tree->child_count + 1);

  struct node_t *curr = tree;
  // 0 means go left, 1 means go right
  // bit_path & leftmost_mask will be either equal to 0 or greater than 0. Compare to explicitly convert to 1 and 0
  unsigned char direction = (bit_path & leftmost_mask) != 0;

  if(depth > 0) {
    // Go down the tree levels
    for(short level = 0; level < depth; level++) {
      printf("level: %u, direction: %d\n", level + 1, direction);
      if(direction == 0) {
          curr = curr->left;
      } else {
          curr = curr->right;
      }
      // Increment the child count in each visited node
      curr->child_count++;
      // Drop the leftmost bit because it's already used
      bit_path <<= 1;
      direction = (bit_path & leftmost_mask) != 0;
    }
  }

  printf("level: %u, direction: %d\n", depth + 1, direction);
  if(direction == 0) {
    curr->left = new_node;
  } else {
    curr->right = new_node;
  }
  // The parent pointer will be used to iterate back up and swap nodes
  new_node->parent = curr;

  tree->child_count++;

  adjust_node_chain(new_node);

  return tree;
}
*/

// Same as above, but works recursively
struct node_t* add_to_tree(struct node_t* tree, int data) {
  if(tree == NULL) return create_node(data);

  unsigned int bit_path = tree->child_count + 2;
  tree->child_count++;

  // Shift the value to the left
  while((bit_path & leftmost_mask) == 0) {
    bit_path <<= 1;
  }
  bit_path <<= 1;

  // Pointer that points to the left or right pointer. Used to avoid if-else statements
  struct node_t **subtree = (bit_path & leftmost_mask) == 0 ? &tree->left : &tree->right;
  if(*subtree == NULL) {
    // Create and assign a new node if the subtree is empty
    *subtree = create_node(data);
    if(tree->data < (*subtree)->data) swap(&tree->data, &(*subtree)->data);
  } else {
    // Walk down the tree recursively
    add_to_tree(*subtree, data);
    // The recursion also handles the swaps back up to the root
    if(tree->data < (*subtree)->data) swap(&tree->data, &(*subtree)->data);
  }

  return tree;
}

// Remove the root node by recursively moving valus up from the larger child
// Actually removes the bottom child in the branch that gets moved
// Return the value from the root through the data pointer
struct node_t* remove_from_tree(struct node_t *tree, int *data) {
  if(tree == NULL) return NULL;

  // Assign the value from the root
  *data = tree->data;

  // Special case - if there are no children then the node can just be removed
  if(tree->child_count == 0) {
    free(tree);
    return NULL;
  }

  // Pointer to pointer. Will avoid multiple if-else by pointing to the pointer to the left or right child
  struct node_t **subtree = NULL;
  // No left and child_count > 0 means 1 or more children are in right
  if(tree->left == NULL) subtree = &tree->right;
  // Same for left
  else if (tree->right == NULL) subtree = &tree->left;
  // Both children exist. Compare their values and choose the larger
  else subtree = tree->left->data > tree->right->data ? &tree->left : &tree->right;

  // Call recursively for the chosen child and assign the returned value to the current node
  *subtree = remove_from_tree(*subtree, &tree->data);
  // Most checks depend on the child count being correct
  tree->child_count--;

  return tree;
}

void print_tree(struct node_t *tree) {
  if (tree == NULL) return;

  printf("%d [%d]\n", tree->data, tree->child_count);

  print_tree(tree->left);
  print_tree(tree->right);
}

void print_bfs(struct node_t* tree) {
  struct queue_t * queue = queue_push(NULL, tree);
  struct queue_t * buffer = NULL;

  while(queue != NULL) { // iterate over all levels
    while(queue != NULL) { // iterate the current level
      struct node_t *curr_node = queue->node;
      queue = queue_pop(queue);

      if(curr_node != NULL) {
        printf("%d [%d] ", curr_node->data, curr_node->child_count);

        buffer = queue_push(buffer, curr_node->left);
        buffer = queue_push(buffer, curr_node->right);
      }
    }
    puts(""); // new line after the level
    queue = buffer;
    buffer = NULL;
  }

  puts("");
}
