#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int hash_function(char* key) {
  
  long long int val = 0;
  for(int i = 0; i < strlen(key); i++) {
    val += key[i] * (i + 1);
    //val += key[i];
  }
  return val;
}

int main()
{
  char *str12 = malloc(10), *str34 = malloc(10), 
  *str1234 = malloc(10);
  int h1 = hash_function("1234"),
  h2 = hash_function("5678"),
  h3 = hash_function("9123"),
  h4 = hash_function("4567");
  strcat(str12, itoa(h1)), strcat(str12, itoa(h2));
  strcat(str34, itoa(h3)), strcat(str34, itoa(h4));
  int h12 = hash_function(str12),
  h34 = hash_function(str34), 
  h1234;
  strcat(str1234, str12), strcat(str1234, str34);
  h1234 = hash_function(str1234);
  return 0;
} 
