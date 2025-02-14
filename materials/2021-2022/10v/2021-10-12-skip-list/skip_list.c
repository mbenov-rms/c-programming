#include <stdio.h>
#include <stdlib.h>

struct list
{
  struct list *prev, *next;
  int data;
  struct list **skip;
};

struct list* add(struct list *list, int data)
{
  struct list *item = malloc(sizeof(struct list));

  item->data = data;
  item->prev = NULL;
  item->skip = NULL;
  item->next = list;

  if(!list) {
 // item->skip = malloc(sizeof(struct list*));
    return item;
  }

  list->prev = item;

  /*if(!list->skip) {
    //item->skip = malloc(sizeof(struct list*));
    free(list->skip);
    item->skip[0] = list->next;
  }*/
  /*if(list->skip) {
    free(list->skip);
    list->skip = NULL;
  }*/

  struct list* tmp = item;
  // Remove the skips from all items
  while(tmp != NULL) {
    if(tmp->skip) {
      free(tmp->skip);
      tmp->skip = NULL;
    }

    tmp = tmp->next;
  }

  tmp = item;
  while(tmp != NULL) {
    if(tmp->next && tmp->next->next) { // There are at least 2 items after tmp
      tmp->skip = malloc(sizeof(struct list*));
      tmp->skip[0] = tmp->next->next; // Assign the jump pointer
      tmp = tmp->skip[0]; // And jump because we do not care about items between tmp and skip
    } else {
      break; // Less  than 2 items after skip, nothing more to do
    }
  }

  return item;
}

void print_list(struct list* list) {
  for(struct list* tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("*=%p d=%d next=%p skip=%p", tmp, tmp->data, tmp->next, tmp->skip);
    if(tmp->skip) {
      printf(" skip[0]=%p", tmp->skip[0]);
    }
    puts("");
  }
}

int main() {
 // struct list list1= {NULL,NULL,5};
  struct list* list = NULL;

  list = add(list, 14);
  list = add(list, 7);
  list = add(list, 4);
  list = add(list, 2);
  list = add(list, 1);

  print_list(list);
  return 0;
}
