#include <stdio.h>
#include <stdlib.h>

struct list
{
  struct list *p;
  int data;
}; 

void* xor(void* a, void* b) {
  return (void*)((long unsigned int)a ^ (long unsigned int)b);
}

struct list* add(struct list *list, int data)
{
  struct list *item = malloc(sizeof(struct list));
  item->data = data;
 
  /*if(!list->p)
    list->p = list->p ^ item;
     
  else
    list->p = (list->p ^ item) ^ list->p;*/
  
  //item -> p = NULL ^ list;
  item->p = list;
  // list->p = item ^ list->p;
  list->p = xor(item, list->p);
  printf("add item %d\n", data);
  printf("item=%p data=%d p=%p\n", item, item->data, item->p);
  printf("list=%p data=%d p=%p\n", list, list->data, list->p);
  puts("===========");
  return item;
}

void print_list(struct list* list) {
  struct list* prev = NULL;
  struct list* tmp = list;
  
  while(tmp != NULL) {
    printf("tmp=%p data=%d p=%p\n", tmp, tmp->data, tmp->p);
    
    struct list* tmp2 = tmp;
    //tmp = tmp->p ^ prev;
    tmp = xor(tmp->p, prev);
    prev = tmp2;
  }

  puts("");
}

int main() {
  struct list list1= {NULL,5};
  struct list* list = &list1;
  
  list = add(list, 10);
  list = add(list, 15);
  list = add(list, 20);
  print_list(list);
  
  /*for(struct list* tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("%d ", tmp->data);
  }
  puts("");*/
  return 0;
}
