#ifndef AVL_TREE_H
#define AVL_TREE_H

struct node_t {
    int data;
    // factor = rightside_levels - leftside_levels
    char factor;
    // The number of levels in the longer subtree
    unsigned int longest_branch;
    struct node_t* left;
    struct node_t* right;
    struct node_t* parent;
};

struct node_t* add(struct node_t* tree, int data);
void print_tree(struct node_t* tree);

#endif
