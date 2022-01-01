#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int hash_func(char* key) {
  long long int val = 0;
  for(int i = 0; i < strlen(key); i++) {
    //val += key[i] * (i + 1);
    val += key[i];
  }
  return val;
}

struct list_t {
  struct list_t* next;
  int value;
  char* key;
};

struct table_t {
  struct list_t* values[256];
  int capacity;
};

int get_at(struct table_t* table, char* key) {
  long long int index = hash_func(key) % table->capacity;
  struct list_t* branch = table->values[index];
  //if(branch == NULL) {
  //  return 0;
    /*branch = malloc(sizeof(struct list_t);
    branch->next = NULL;
    branch->value = */
 // }
  
  while(branch != NULL) {
    if(strcmp(branch->key, key) == 0) return branch->value;
    branch = branch->next;
  }
  return 0;
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

int main() {
  /*printf("%lld %lld %lld %lld %lld\n", 
    hash_func("asd"),
    hash_func("dsa"),
    hash_func("Hello"),
    hash_func("Ivan"),
    hash_func("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
  );*/
  
  struct table_t table;
  table.capacity = 256;
  
  set_at(&table, "asd", 15);
  set_at(&table, "dsa", 18);
  printf("%d\n", get_at(&table, "asd"));
  printf("%d\n", get_at(&table, "dsa"));

  return 0;
}
