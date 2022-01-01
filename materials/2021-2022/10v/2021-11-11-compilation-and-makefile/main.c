#include <stdio.h>

#include "bin_tree.h"

int main() {
    struct  node_t* tree = add(NULL, 50);
    tree = add(tree, 55);
    tree = add(tree, 52);
    tree = add(tree, 46);
    tree = add(tree, 44);
    tree = add(tree, 42);
    tree = add(tree, 40);
    tree = add(tree, 30);
    tree = add(tree, 28);
    tree = add(tree, 26);
    tree = add(tree, 24);
    tree = add(tree, 27);
    tree = add(tree, 32);
    tree = add(tree, 35);
    tree = add(tree, 33);
    tree = add(tree, 34);

    /*printf("%d ", _tree(tree,17));
    printf("%d ", search_tree(tree, 41));
    printf("%d ", search_tree(tree, 44));

    printf("%d ", cnt_elements(tree));
    */
    print_bfs(tree);
    puts("");

    tree = balance_tree(tree);
    //print_tree(tree);
    
    puts("");
    print_bfs(tree);

    return 0;
}
