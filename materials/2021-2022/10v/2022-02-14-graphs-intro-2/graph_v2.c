#include <stdlib.h>
#include <stdio.h>

struct set_t {
  void** items;
  int item_count;
};

struct set_t* init_set() {
  struct set_t* new_set = malloc(sizeof(struct set_t));
  
  new_set->items = NULL;
  new_set->item_count = 0;
  
  return new_set;
}

void add_to_set(struct set_t* set, void* value) {
  set->item_count++;
  set->items = realloc(set->items, sizeof(void*) * set->item_count);
  set->items[set->item_count - 1] = value;
}

int has_in_set(struct set_t* set, void* value) {
  for(int i = 0; i < set->item_count; i++) {
    if(set->items[i] == value) return 1;
  }
  
  return 0;
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
  if(!has_in_set(g->nodes, (void*)a)) 
    add_to_set(g->nodes, (void*)a);

  if(!has_in_set(g->nodes, (void*)b)) 
    add_to_set(g->nodes, (void*)b);
    
  struct connection_t* c = malloc(sizeof(struct connection_t));
  c->a = a;
  c->b = b;
  
  add_to_set(g->connections, c);
}

void print_graph(struct graph_t* graph) {
  for(int i = 0; i < graph->nodes->item_count; i++) {
    printf("%d\n", (int)graph->nodes->items[i]);
  }
  for(int i = 0; i < graph->connections->item_count; i++) {
    struct connection_t* c = (struct connection_t*)graph->connections->items[i];
    printf("%d <=> %d\n", c->a, c->b);
  }
}

int main() {
  struct graph_t graph;
  graph.nodes = init_set();
  graph.connections = init_set();
  
  connect_nodes(&graph, 10, 20);
  connect_nodes(&graph, 20, 10);
  
  print_graph(&graph);
  
  return 0;
}
