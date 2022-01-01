#include "tester.h"

int hash_func(char* str, size_t byte_count) {
  // return strlen(str);

  int res = 0;

  for(int i = 0; i < strlen(str); i++)
    res += str[i] * (i + 1);
    // res += str[i];

  return res;
}

int main() {
  test_hf(4000, "input1.txt", &hash_func);
  return 0;
}
