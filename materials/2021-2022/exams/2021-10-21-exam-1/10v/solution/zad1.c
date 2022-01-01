#include <stdio.h>

unsigned int count_10(short data) {
  unsigned int count = 0;

  // Iterate all bits
  while(data > 0) {
    // Extract the last 2 bits and check if they match the pattern 
    // 1010 1010 & 0000 0011 == 0000 0010
    if((data & 0b11) == 0b10) count++;
    // if((data & 3) == 2) count++; // 0b11 == 3, 0b10 == 2
    // Bitshift to the right once
    data >>= 1; 
  }
  
  return count;
}

int main() {
  printf("11 => %d\n", count_10(11));
  printf("3 => %d\n", count_10(3));
  printf("21601 => %d\n", count_10(21601));
  return 0;
}
