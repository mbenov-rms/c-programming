#include <stdio.h>

#include "bst.h"

int main() {
    struct  node_t* tree = add(NULL, 50);
    tree = add(tree, 55); // invalid
    tree = add(tree, 52); // valid 50 + 52 is even
    tree = add(tree, 46); // valid 50 + 46 is even
    tree = add(tree, 45); // valid 46 + 45 is odd, but abs(46 - 45) is 1
    tree = add(tree, 49); // invalid

    print_bfs(tree);

    return 0;
}
