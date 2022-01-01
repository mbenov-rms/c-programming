#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int hash_func(char* key) {
  long long int val = 0;
  for(int i = 0; i < strlen(key); i++) {
    val += key[i] * (i + 1);
    //val += key[i];
  }
  return val;
}

struct list_t {
  struct list_t* next;
  int value;
  char* key;
};

struct bst_list {
  struct list_t* list;
  int hash_value;
  struct bst_list* right, *left;
};
/*
struct table_t {
  struct list_t** values;
  int capacity;
};

int get_at(struct table_t* table, char* key) {
  long long int index = hash_func(key) % table->capacity;
  struct list_t* branch = table->values[index];
  //if(branch == NULL) {
  //  return 0;
    /*branch = malloc(sizeof(struct list_t);
    branch->next = NULL;
    branch->value = 
 // }
  
  while(branch != NULL) {
    if(strcmp(branch->key, key) == 0) return branch->value;
    branch = branch->next;
  }
  return -1;
}

void set_at(struct table_t* table, char* key, int value) {
  long long int index = hash_func(key) % table->capacity;
  struct list_t* branch = table->values[index];
  
  if(branch == NULL) {
    branch = malloc(sizeof(struct list_t));
    branch->next = NULL;
    branch->value = value;
    branch->key = key;
    
    table->values[index] = branch;
    return;
  }
  
  while(branch->next != NULL || strcmp(branch->key,key)==0) {
    branch = branch->next;
  }
  
  if(strcmp(branch->key,key) == 0) {
    branch->value = value;
  } else {
    branch->next = malloc(sizeof(struct list_t));
    branch->next->next = NULL;
    branch->next->value = value;
    branch->next->key = key;
  }
}

struct table_t* init_table(unsigned int capacity)
{
  struct table_t* table = malloc(sizeof (struct table_t));
  table -> capacity = capacity;
  //table -> values = malloc(sizeof (struct list_t*) * capacity);
//  memset(table->values, 1, sizeof (struct list_t*) * capacity);

  table -> values = calloc(capacity, sizeof (struct list_t*));
  return table;
}

void delete_element(struct table_t *table, char *key)
{
  long long int index = hash_func(key) % table->capacity;
  struct list_t* branch = table->values[index]; 
  struct list_t* prev;
  if(!branch) return;
  if(strcmp(branch->key, key) == 0)
  {
    table->values[index] = branch->next;
    free(branch);
    return;
  }
  while(branch != NULL) 
  {
    if(strcmp(branch->key, key) == 0)
    {
      prev->next = branch->next;
      free(branch);
      return;
    }
    prev = branch;
    branch = branch->next;
  }
}*/

struct bst_list* init_hash(int value, char* key)
{
  struct list_t* new_list = malloc(sizeof(struct list_t));
  struct bst_list* new_element = malloc(sizeof(struct bst_list));
  
  new_list->next = 0;
  new_list->value = value;
  new_list->key = key;
  
  new_element->list = new_list;
  new_element->hash_value = hash_func(key);
  new_element->right = 0;
  new_element->left = 0;
  
  return new_element;
}

struct bst_list* new_bst(int value, char* key)
{
  struct bst_list* new_element = malloc(struct bst_list));
  int new_value = hash_func(key);
  new_element->hash_value = new_value;
  

}

struct bst_list* add_hashtree(struct bst_list* hash_tree, int value, char* key)
{

  if (!hash_tree)
  {
    struct new_bst = init_hash(hash_tree);
    return new_bst;
  }
  struct bst_list* new_bst;
  int new_key = hash_func(key);
  if (hash_key > hash_tree->key_value)
  {
    new_bst = init_hash(value, key);
    bst_list->right = new_bst;
  
  }
  else if(hash_key < hash_tree->key_value
  {
    new_bst = init_hash(value, key;
    bst_list->left = new_bst;
  }
  else
  {
    
  }
}

int main() 
{
  /*printf("%lld %lld %lld %lld %lld\n", 
    hash_func("asd"),
    hash_func("dsa"),
    hash_func("Hello"),
    hash_func("Ivan"),
    hash_func("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
  );*/
  
  struct table_t* table = init_table(317);

  
  set_at(table, "asd", 15);
  set_at(table, "dsa", 18);
  delete_element(table, "dsa");
  printf("%d\n", get_at(table, "asd"));
  printf("%d\n", get_at(table, "dsa"));
  printf("%d\n", get_at(table, "daa"));
  return 0;
}
