#include <stdio.h>
#include <stdlib.h>

struct list
{
  struct list *prev, *next;
  int data;
}; 

struct list* add(struct list *list, int data)
{
  struct list *item = malloc(sizeof(struct list));
  item->data = data;
  item->prev = 0;
  item->next = list;   
  
  list->prev = item;
  return item;
}

int main() {
  struct list list1= {NULL,NULL,5};
  struct list* list = &list1;
  
  list = add(list, 10);
  
  for(struct list* tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("%d ", tmp->data);
  }
  puts("");
  return 0;
}
