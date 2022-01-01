#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test_hf(size_t table_size, char* file_path, int(*hash_func)(char*, size_t)) {
  unsigned char *table = calloc(table_size, sizeof(unsigned int));
  unsigned int collisions = 0;
  unsigned int key_count = 0;

  FILE* in = fopen(file_path, "r");
  if(in == NULL) exit(-1);

  int i = 0;
  while(!feof(in)) {
    char key[255];
    fgets(key, 255, in);
    if(feof(in)) break;

    key[strcspn(key, "\n")] = 0;
    key[strcspn(key, "\r")] = 0;

    key_count++;

    int hash_code = hash_func(key, strlen(key));
    int table_index = hash_code % table_size;

    // printf("[%d] %s %u %d\n", ++i, key, hash_code, table[table_index]);

    if(table[table_index]) collisions++;
    else table[table_index] = 1;
  }

  fclose(in);
  free(table);

  printf("Table size: %lu Key count: %u\n", table_size, key_count);
  printf("Collision count: %u => %f%%\n", collisions, ((double)collisions / key_count) * 100);
}
