---
title: Лекция 07 - Качествен Код
category: новини
tags:
  - лекции
  - материали
---

[Линк към презентацията](https://docs.google.com/presentation/d/1bAITgBuzQCVxwql4V3jUczvbOdX3fk-GeIg-yI0j_IQ/)

{% include presentation id="2PACX-1vSuR9S5IcDM9Gi7UOLdKFVBikFXbvAHCLhmMBrLNt2Y41Aa4IuqIgAb5H9_Z_gvRnN2AEQM6k00mJ21" %}

```c
struct some_very_long_struct_name* some_very_long_function_name(struct other_long_long_struct_name arg1, unsigned long int arg2, struct third_long_struct_name* my_very_long_argument_name) {
  // ...
}

struct some_very_long_struct_name*
some_very_long_function_name(
  struct other_long_long_struct_name arg1,
  unsigned long int arg2,
  struct third_long_struct_name* my_very_long_argument_name
) {
  // ...
}



int main() {
    int side_a = 5, d = 9,
        e = 7;
    int side_b = 17;
    int area = side_a * side_b;

    for(int index_x = 0; index_x<10; index_x++) {
      for(int index_y = 0; index_y<10; index_y++) {
        for(int index_z = 0; index_z<10; index_z++) {
          // ...
        }
      }
    }

    printf("HELLO");

    return 0;
}
```                   
