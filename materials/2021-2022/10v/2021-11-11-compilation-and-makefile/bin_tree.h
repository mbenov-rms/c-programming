#ifndef BIN_TREE_H
#define BIN_TREE_H

struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* tree, int data);
int search_tree(struct node_t* tree, int data);
struct node_t* remove_node(struct node_t* tree, int data);
int cnt_elements(struct node_t* tree);
void print_tree(struct node_t* tree);
struct node_t** gather_elements(struct node_t* tree, struct node_t** values);
struct node_t* balance_tree_elements(struct node_t** array, int element_cnt);
struct node_t* balance_tree(struct node_t* tree);
void print_bfs(struct node_t* tree);

#endif
