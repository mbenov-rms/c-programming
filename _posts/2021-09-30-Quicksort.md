---
title: Упражнение 03 - Сортиране и quicksort
category: новини
tags:
  - упражнения
  - материали
---

[Какво е Quicksort](https://en.wikipedia.org/wiki/Quicksort)

## Код от час
### В клас

```c
void q_s(int nums[], int n)
{
  if(n <= 1) return;
  int kotva = n/2;
  for(int i = 0;i < n;i++)
  {
      if(nums[i] > nums[kotva] && i < kotva)
      {

          swap(nums[i], nums[kotva - 1]);
          swap(nums[kotva - 1], nums[kotva]);
          kotva--;
      }

      if(nums[i] < nums[kotva] && i > kotva)
      {
          swap(nums[i], nums[kotva + 1]);
          swap(nums[kotva + 1], nums[kotva]);
          kotva++;      
      }

  }

  //q_s(nums + kotva + 1, n - kotva - 1);
  q_s(&nums[kotva + 1], n - kotva - 1);
  q_s(nums, kotva);
}
```
