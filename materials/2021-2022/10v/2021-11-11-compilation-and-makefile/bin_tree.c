#include <stdlib.h>
#include <stdio.h>

#include "bin_tree.h"
#include "queue.h"

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->data = data;
        new_node->left = new_node->right = NULL;

        return new_node;
    }

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

void print_bfs(struct node_t* tree) {
  struct queue_t * queue = queue_push(NULL, tree);
  struct queue_t * buffer = NULL;
  
  while(queue != NULL) { // iterate over all levels
    while(queue != NULL) { // iterate the current level
      struct node_t *curr_node = queue->node;
      queue = queue_pop(queue);
      
      if(curr_node != NULL) {
        printf("%d ", curr_node->data);
        
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
