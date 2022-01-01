#include <stdio.h>
#include <stdlib.h>

struct queue_t {
    struct queue_t* next;
    struct node_t* node;
};

struct queue_t* queue_push(struct queue_t* queue, struct node_t* node) {
    struct queue_t* new_node = malloc(sizeof(struct queue_t));
    new_node->next = NULL;
    new_node->node = node;

    if (queue == NULL) {
        return new_node;
    }

    struct queue_t* curr = queue;
    while (curr->next != NULL) curr = curr->next;
    curr->next = new_node;

    return queue;
}

struct queue_t* queue_pop(struct queue_t* queue) {
    if (queue == NULL) {
        return NULL;
    }

    struct queue_t* old_head = queue;
    queue = queue->next;

    free(old_head);

    return queue;
}



struct node_t {
    int data[5];
    int data_count;
    struct node_t* left;
    struct node_t* right;
};

struct node_t* add(struct node_t* tree, int data) {
    if (tree == NULL) {
        struct node_t* new_node = malloc(sizeof(struct node_t));
        new_node->data[0] = data;
        new_node->data_count = 1;

        new_node->left = new_node->right = NULL;

        return new_node;
    }

    if (tree->left != NULL ) {
        if (tree->left->data_count <= tree->right->data_count && tree->left->left==NULL)
            tree->left = add(tree->left, data);
        else tree->right = add(tree->right, data);
    }
    else if (tree->data_count == 4) {
        struct node_t* new_left = malloc(sizeof(struct node_t));
        new_left->data[0] = tree->data[0];
        new_left->data[1] = tree->data[1];
        new_left->data_count = 2;

        new_left->left = new_left->right = NULL;
        struct node_t* new_right = malloc(sizeof(struct node_t));
        new_right->data[0] = tree->data[3];
        new_right->data[1] = data;
        new_right->data_count = 2;
        new_right->left = new_right->right = NULL;
        tree->data[0] = tree->data[2];
        tree->data[1] = 0;
        tree->data[2] = 0;
        tree->data[3] = 0;
        tree->data[4] = 0;
        tree->data_count = 1;
        tree->left = new_left;
        tree->right = new_right;
    }
    else tree->data[tree->data_count] = data, tree->data_count++;

    return tree;
}
/*
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
}*/

void print_bfs(struct node_t* tree) {
    struct queue_t* queue = queue_push(NULL, tree);

    do {
        struct node_t* curr_node = queue->node;

        queue = queue_pop(queue);

        if (curr_node != NULL) {
            printf("[");
            for(int i=0;i<curr_node->data_count;i++)
                printf("%d , ", curr_node->data[i]);
            printf("]");
            char is_root = curr_node == tree;
            char has_next_node = queue != NULL && queue->node != NULL;
            char next_is_less = has_next_node && queue->node->data < curr_node->data;
            if (is_root || next_is_less) {
                puts("");
            }

            queue = queue_push(queue, curr_node->left);
            queue = queue_push(queue, curr_node->right);
        }
    } while (queue != NULL);
    puts("");
}
/*struct node_t* find_nearest_parent(struct node_t* tree, int d1, int d2)
{
    if (tree == NULL)
        return NULL;
    if (tree->left->data == d1 || tree->left->data == d2|| tree->right->data==d1||tree->right->data==d2)
        return tree ;
    if (tree->data > d1 && tree->data > d2)
         return find_nearest_parent(tree->left, d1, d2);
    else if (tree->data < d1 && tree->data < d2)
           return  find_nearest_parent(tree->right, d1, d2);
        else return tree;


}*/

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
    print_bfs(tree);
    /*
    print_tree(tree);
    puts("");

    puts("");
    print_bfs(tree);
    struct node_t* t=find_nearest_parent(tree, 44, 46);
    printf("%d", t->data);
    */
    return 0;
}
