#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->data = data;
        new_node->left = new_node->right = NULL;

        return new_node;
    }

    /*struct node_t *curr = tree;
    while(curr != NULL) {
      if(data < curr->data) curr = curr->left;
      else if(data > curr->data) curr = curr->right;

      //if(curr == NULL) break;
    }

    curr = new_node;*/
    if (data < tree->data) {
        tree->left = add(tree->left, data);
    }
    else if (data > tree->data) {
        tree->right = add(tree->right, data);
    }

    return tree;
}

int search_tree(struct node_t* tree, int data)
{
    if (tree == NULL)
        return 0;

    if (data == tree->data)
        return 1;
    if (data < tree->data)
        return search_tree(tree->left, data);
    else
        return search_tree(tree->right, data);
}

struct node_t* remove_node(struct node_t* tree, int data)
{
    if (tree == NULL) return NULL;
    if (data == tree->data)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            tree = NULL;
            return tree;
        }

        if (tree->left && tree->right)
        {
            free(tree);
            tree = tree->right;

            return tree;
        }

        if (tree->left && tree->right == NULL)
        {
            free(tree);
            tree = tree->left;
            return tree;
        }

        if (tree->left == NULL && tree->right)
        {
            free(tree);
            tree = tree->right;
            return tree;
        }


    }

    /*if (data < tree->data)
        return search_tree(tree->left, data);
    else
        return search_tree(tree->right, data);*/
}


int cnt_elements(struct node_t* tree)
{
    if (tree == NULL) return 0;
    return cnt_elements(tree->left) + cnt_elements(tree->right) + 1;
}


void print_tree(struct node_t* tree) {
    if (tree == NULL) return;

    printf("%d\n", tree->data);

    print_tree(tree->left);
    print_tree(tree->right);
}


struct node_t** gather_elements(struct node_t* tree, struct node_t** values) {
    if (tree == NULL) return values;

    values = gather_elements(tree->left, values);
    (*values) = tree;
    values++;
    values = gather_elements(tree->right, values);

    return values;
}
/*
struct node_t* balance_tree_elements(int* array, int element_cnt)
{
    if (element_cnt == 0) return 0;

    int index = element_cnt / 2;

    struct node_t* tree = add(NULL, array[index]);
    tree->left = balance_tree_elements(array, index);

    tree->right = balance_tree_elements(array + index + 1, element_cnt - index - 1);

    return tree;
}

struct node_t* balance_tree(struct node_t* tree) {
    int element_count = cnt_elements(tree);
    int* array = malloc(sizeof(int) * element_count);
    gather_elements(tree, array);

    /*for(int i = 0; i < element_count; i++) {
      printf("%d ", array[i]);
    }
    puts("");

    return balance_tree_elements(array, element_count);
}
*/

struct node_t* balance_tree_elements(struct node_t** array, int element_cnt)
{
    if (element_cnt == 0) return NULL;

    int index = element_cnt / 2;

    struct node_t* tree = array[index];



    tree->left = balance_tree_elements(array, index);

    tree->right = balance_tree_elements(array + index + 1, element_cnt - index - 1);

    return tree;
}

struct node_t* balance_tree(struct node_t* tree)
{
    int element_count = cnt_elements(tree);
    struct node_t** array = malloc(sizeof(struct node_t*) * element_count);
    gather_elements(tree, array);

    return balance_tree_elements(array, element_count);
}


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
    print_tree(tree);
    puts("");

    tree = balance_tree(tree);
    print_tree(tree);



    return 0;
}
