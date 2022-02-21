#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "set.h"

struct set_t {
    struct list_node_t* head;
    int count;
};

struct set_t* init_set() {
    struct set_t* new_set = malloc(sizeof(struct set_t));

    new_set->head = NULL;
    new_set->count = 0;

    return new_set;
}

void add_to_set(struct set_t* set, void* value) {
    if (has_in_set(set, value)) return;

    set->head = add_to_list(set->head, value);
    set->count++;
}

int has_in_set(struct set_t* set, void* value) {
    return has_in_list(set->head, value);
}

void remove_from_set(struct set_t* set, void* value) {
    if (set->count <= 0) return;
    if (!has_in_set(set, value)) return;

    set->head = remove_from_list(set->head, value);
    set->count--;
}

void print_all_in_set(struct set_t* set) {
    struct list_node_t* curr = set->head;
    for (int i = 0; i < set->count; i++, curr = curr->next) {
        printf("[%.2d] %p\n", i, curr->value);
    }
}
struct connection_t {
    int a;
    int b;
};

struct graph_t {
    struct set_t* nodes; // int
    struct set_t* connections; // struct connection_t
};

void connect_nodes(struct graph_t* g, int a, int b) {
    if (!has_in_set(g->nodes, (void*)a))
        add_to_set(g->nodes, (void*)a);

    if (!has_in_set(g->nodes, (void*)b))
        add_to_set(g->nodes, (void*)b);

    struct connection_t* c = malloc(sizeof(struct connection_t));
    c->a = a;
    c->b = b;

    add_to_set(g->connections, c);
}

void print_graph(struct graph_t* graph) {
    for (struct list_node_t* curr = graph->nodes->head; curr != NULL; curr = curr->next) {
        printf("%d\n", (int)curr->value);
    }
    for (struct list_node_t* curr = graph->connections->head; curr != NULL; curr = curr->next) {
        struct connection_t* c = (struct connection_t*)curr->value;
        printf("%d <=> %d\n", c->a, c->b);
    }
}

struct dij_node_t {
    int value;
    int visited;
    int weight;
    struct dij_node_t* prev;
};

struct dij_node_t* dij_find_in_set(struct set_t* set, void* value) 
{
    for (struct list_node_t* curr = set->head; curr != NULL; curr = curr->next)
    {
        if (((struct dij_node_t*)curr->value)->value == value) return curr->value;
    }
}

void print_path_dij(struct set_t*all_nodes, int value)
{
    struct dij_node_t* v=dij_find_in_set(all_nodes, value);
    if (v == NULL)return;
    if (v->prev == NULL)
    {
        printf("%d\n", value);
        return;
    }
    print_path_dij(all_nodes,v->prev->value);
    printf("%d\n", value);
}

void find_shortest_path_dijkstra(
    struct graph_t* graph,
    int start,
    int end
) {
    struct set_t* all_nodes = init_set();
    for (struct list_node_t* curr = graph->nodes->head; curr != NULL; curr = curr->next) {
        struct dij_node_t* node = malloc(sizeof(struct dij_node_t));
        node->value = (int)curr->value;
        node->visited = 0;
        node->weight = -1;
        node->prev = NULL;
        add_to_set(all_nodes, node);
    }
    struct set_t* all_nodes_2 = init_set();
    for (struct list_node_t* curr = graph->nodes->head; curr != NULL; curr = curr->next) {
        struct dij_node_t* node = malloc(sizeof(struct dij_node_t));
        node->value = (int)curr->value;
        node->visited = 0;
        node->weight = -1;
        node->prev = NULL;
        add_to_set(all_nodes_2, node);
    }
    struct dij_node_t* node = dij_find_in_set(all_nodes, start);
    node->weight = 0;
    struct set_t* connections = init_set();
    while(all_nodes->count)
    {
        int lowest_val = -1;
        for (struct list_node_t* curr = all_nodes->head; curr != NULL; curr = curr->next) {
            struct dij_node_t* dij_node = curr->value;
            if ((dij_node->weight < lowest_val || lowest_val == -1) && dij_node->weight != -1)
                lowest_val = dij_node->weight,node=curr->value;
        }
        remove_from_set(all_nodes,node);
        for (struct list_node_t* curr = graph->connections->head; curr != NULL; curr = curr->next) {
            struct connection_t* c = curr->value;
            if (c->a == node->value || c->b == node->value)
                add_to_set(connections, c);
        }

        for (struct list_node_t* curr = connections->head; curr != NULL; curr = curr->next) {
            struct connection_t* c = curr->value;
            int other = c->a;
            if (c->a == node->value) other = c->b;

            struct dij_node_t* other_node = dij_find_in_set(all_nodes, other);
            if (!other_node->visited) {
                int new_weight = node->weight + 1;
                if (other_node->weight == -1 || other_node->weight > new_weight) {
                    struct dij_node_t* other_node_2 = dij_find_in_set(all_nodes_2, other);
                    other_node->prev = node;
                    other_node->weight = node->weight + 1;
                    other_node_2->prev = node;
                    other_node_2->weight = node->weight + 1;
                }
            }
        }
        node->visited = 1;
    }
    struct dij_node_t* res = dij_find_in_set(all_nodes_2, end);
    printf("%d\n",res->weight);
    print_path_dij(all_nodes_2,end);
}

int main() {
    struct graph_t graph;
    graph.nodes = init_set();
    graph.connections = init_set();


    connect_nodes(&graph, 10, 20);
    connect_nodes(&graph, 20, 10);

    connect_nodes(&graph, 20, 30);
    connect_nodes(&graph, 30, 20);

    connect_nodes(&graph, 10, 50);
    connect_nodes(&graph, 50, 10);

    connect_nodes(&graph, 50, 40);
    connect_nodes(&graph, 40, 50);

    connect_nodes(&graph, 10, 40);
    connect_nodes(&graph, 40, 10);

    connect_nodes(&graph, 20, 40);
    connect_nodes(&graph, 40, 20);

    connect_nodes(&graph, 40, 30);
    connect_nodes(&graph, 30, 40);

    print_graph(&graph);
    printf("\n\n");
    find_shortest_path_dijkstra(&graph, 50, 30);
   

    return 0;
}
