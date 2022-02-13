#include <stdlib.h>
#include <stdio.h>

struct graph_node_t {
  int value;
  struct graph_node_t** items;
  int item_count;
  
  char visited;
};

struct graph_node_t* init_graph_node(int value) {
  struct graph_node_t* new_node = malloc(sizeof(struct graph_node_t));
  
  new_node->value = value;
  new_node->item_count = 0;
  new_node->visited = 0;
  new_node->items = NULL;
  
  return new_node;
}

void connect_nodes(struct graph_node_t* a, struct graph_node_t* b) {
  a->item_count++;
  a->items = realloc(a->items, sizeof(struct graph_node_t*) * a->item_count);
  a->items[a->item_count - 1] = b;
}

void add_node(
  struct graph_node_t* start, 
  int new_value, 
  int parent_value) {
    
  if(start->value == parent_value) {
    struct graph_node_t* new_node = init_graph_node(new_value);
  
    connect_nodes(start, new_node);
    connect_nodes(new_node, start);
    return;
  }
  
  start->visited = 1;
  
  for(int i = 0; i < start->item_count; i++) {
    if(start->items[i]->visited == 1) continue;
    
    add_node(start->items[i], new_value, parent_value);
  }
  
  start->visited = 0;
}

void print_node(struct graph_node_t* node) {
  printf("value=%d item_count=%d visited=%d items=",
    node->value, node->item_count, node->visited
  );
  for(int i = 0; i < node->item_count; i++) {
    printf("%d,",node->items[i]->value);
  }
  puts("");
}

struct graph_node_t** get_all_nodes(
  struct graph_node_t* start, 
  struct graph_node_t** items, 
  int* item_count) {
  
  start->visited = 1;
  
  (*item_count)++;
  items = realloc(
    items, 
    sizeof(struct graph_node_t*) * (*item_count)
  );
  items[(*item_count) - 1] = start;
  
  for(int i = 0; i < start->item_count; i++) {
    if(start->items[i]->visited == 1) continue;
    
    get_all_nodes(start->items[i], items, item_count);
  }
  
  start->visited = 0;
  
  return items;
}


struct graph_node_t* find_node(
  struct graph_node_t* start, 
  int value) {
    
  if(start->value == value) {
    return start;
  }
  
  start->visited = 1;
  
  for(int i = 0; i < start->item_count; i++) {
    if(start->items[i]->visited == 1) continue;
    
    struct graph_node_t* found = find_node(start->items[i], value);
    if(found != NULL) {
      start->visited = 0;
      return found;
    }
  }
  
  start->visited = 0;
  return NULL;
}

void connect_random_nodes(
  struct graph_node_t* start,
  int first,
  int second
  ) {
  struct graph_node_t* first_n = find_node(start, first);
  struct graph_node_t* second_n = find_node(start, second);
  
  connect_nodes(first_n, second_n);
  connect_nodes(second_n, first_n);
}

int main() {
  struct graph_node_t* first = init_graph_node(5);
  /*struct graph_node_t* second = init_graph_node(10);
  
  connect_nodes(first, second);
  connect_nodes(second, first);*/
  
  add_node(first, 10, 5);
  add_node(first, 12, 5);
  add_node(first, 14, 5);
  
  add_node(first, 20, 10);
  add_node(first, 30, 20);
  
  add_node(first->items[0]->items[1], 40, 5);
  
  connect_nodes(first->items[1], first->items[0]->items[1]);
  connect_nodes(first->items[0]->items[1], first->items[1]);
  
  connect_random_nodes(first, 30, 40);
  
  /*print_node(first);
  for(int i = 0; i < first->item_count; i++)
    print_node(first->items[i]);

  for(int i = 0; i < first->items[0]->item_count; i++)
    print_node(first->items[0]->items[i]);*/
    
  int item_count = 0;
  struct graph_node_t** items = get_all_nodes(first, NULL, &item_count);
  
  for(int i = 0; i < item_count; i++)
    print_node(items[i]);
  
  return 0;
}
