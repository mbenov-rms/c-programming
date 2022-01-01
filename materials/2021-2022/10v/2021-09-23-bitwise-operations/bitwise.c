#include <stdio.h>

void printbits(void* a, size_t size) {
  /*unsigned int leftmost = 1 << (size * 8) - 1;
  for(int i = 0; i < size*8; i++) {
    printf("%d", !!((*(unsigned long long *)a) & leftmost));
    leftmost = leftmost >> 1;
  }*/
  
  for(int i = 0; i < size; i++) {
    unsigned char byte = ???;
    unsigned char leftmost = 1 << 7;
    for(int j = 0; j < 8; j++) {
      printf("%d", !!(byte & leftmost));
      leftmost = leftmost >> 1;
    }
  }
  
  puts("\n");
  //printf("\n");
  //putchar('\n');
}

struct point_t {
  unsigned long long x;
  unsigned long long y;
  unsigned long long z;
};

int main() {
  /*int a = 16; // 0001 0000
  int b = 10; // 0000 1010
  
  printf("%d %d %d %d %d %d %d\n", 
    a & b, a | b, a ^ b, ~a & b, ~(a | b) ^ b, 
    a >> 3, a << 3
  ); */ 
  
  short c = 254;
  printbits(&c, sizeof(short));
  
  signed long long d = 254;
  printbits(&d, sizeof(signed long long));
  
  struct point_t p = {~128, 256, 1025};
  printbits(&p, sizeof(struct point_t));
  
  return 0;
}
