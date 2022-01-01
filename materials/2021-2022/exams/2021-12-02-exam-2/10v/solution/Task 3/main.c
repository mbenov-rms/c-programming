#include <stdio.h>

#include "binary_tree.h"

int main() {
    struct node_t* tree = add(NULL, 50); // Root, will be removed

    tree = add(tree, 40); // L, will be removed because removing LL will rearrange the children
    tree = add(tree, 60); // R, will be removed because removing RR will rearrange the children

    tree = add(tree, 30); // LL, will be removed
    tree = add(tree, 44); // LR
    tree = add(tree, 65); // RR, will be removed

    tree = add(tree, 29); // LLL
    tree = add(tree, 39); // LLR
    tree = add(tree, 130); // RRR

    puts("Before:");
    print_bfs(tree);

    tree = remove_too_small(tree);
    puts("After:");
    print_bfs(tree);

    return 0;
}
