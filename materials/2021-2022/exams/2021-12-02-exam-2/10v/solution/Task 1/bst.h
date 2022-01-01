#ifndef BST_TREE_H
#define BST_TREE_H

struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* tree, int data);
void print_bfs(struct node_t* tree);

#endif
