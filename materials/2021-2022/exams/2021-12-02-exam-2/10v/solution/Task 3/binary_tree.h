#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct node_t {
    int value;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* tree, int value);
struct node_t* remove_too_small(struct node_t *root);
void print_bfs(struct node_t* tree);

#endif
