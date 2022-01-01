#include <stdio.h>

unsigned int find_longest(char data[], int length) {
    int count = 1, max_count = 0;
    char last_seen;

    for(int i = 0; i <= length;i++){
      if(last_seen == data[i]) {
        count++;
      } else {
        last_seen = data[i];
        if(count > max_count) max_count = count;
        count = 1;
      }
    }

    return max_count;
}

int main() {
  printf("%d\n", find_longest("MERY", 4));
  printf("%d\n", find_longest("MMEERRYY", 8));
  printf("%d\n", find_longest("MEERRRYYYY", 10));
  printf("%d\n", find_longest("EEMRRRYYMM", 10));
/*
MERY => 1
MMEERRYY => 2
MEERRRYYYY => 4
EEMRRRYYMM=> 3*/

  return 0;
}
