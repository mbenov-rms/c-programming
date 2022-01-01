#include <string.h>

struct package_t {
  /*char* from;
  char* to;
  char* content;*/
  char from[16];
  char to[16];
  char content[256];
  unsigned int weight;
};

int validate(struct package_t* package) {
  if(
     package->from[0] == 0
  || package->to[0] == 0
  || package->weight > 10) {
    return 0;
  }

  for(int i =0; i<strlen(package->content); i++) {
    if(
         !(
               (package->content[i] >= 'a' && package->content[i] <= 'z')
            || (package->content[i] >= '0' && package->content[i] <= '9')
            || (package->content[i] == ' ')
          )
      ) {
        return 0;
      }
  }

  return 1;
}
