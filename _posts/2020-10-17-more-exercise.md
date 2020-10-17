---
title: Задачи за упражнение
category: новини
tags:
  - лекции
  - материали
---

[Вариант 1](https://docs.google.com/document/d/1jWso7LGput2jhADiGBH0qA2MK9epSNnae-5m_G9AF9w/edit?usp=sharing)
[Вариант 2](https://docs.google.com/document/d/1UvW_G3xeR-s7AxBo_6Vl8ckbjSfjfgmP5BcU0SsNqg0/edit?usp=sharing)
[Вариант 3](https://docs.google.com/document/d/1AzcXlkEkNK-goU80bSSdrM38FHGZegJdPEp9v9q5I0Q/edit?usp=sharing)
[Вариант 4](https://docs.google.com/document/d/1s-8PAf79H_f_E7_v8WYIp_RGIzw8IacPQG8nLYvgeqo/edit?usp=sharing)

## Решение на Вариант 1
### Задача 1
```c
#include <stdio.h>
#include <string.h>

int is_valid_character(char c) {
  return (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z') ||
         (c >= '0' && c <= '9');
}

int verify_and_print_mac(char *mac) {
  if(strlen(mac) != 17) return 0;

  for(int i=0; i < strlen(mac); i++) {
    if(i % 3 == 0 && !is_valid_character(mac[i])) return 0;
    if(i % 3 == 1 && !is_valid_character(mac[i])) return 0;
    if(i % 3 == 2 && mac[i] != ':') return 0;
  }

  for(int i=0; i < strlen(mac); i++) {
    if(mac[i] == ':') {
      putchar('\n');
    } else {
      putchar(mac[i]);
    }
  }
  putchar('\n');

  return 1;
}

int main () {
  printf("%d\n", verify_and_print_mac("0a:1b:2c:3d:4e:5f"));
  printf("%d\n", verify_and_print_mac("0a:1b:2c:3d:4e:5ffff"));
  printf("%d\n", verify_and_print_mac("0a:1b:2c:3d:4e"));
  printf("%d\n", verify_and_print_mac("0a:1b:2c:3d:zz:5f"));

  return 0;
}
```

### Задача 2
```c
#include <stdio.h>

struct cpu_t {
  int core_count;
  float max_freq;
  int has_multithreading;
  int has_video;
};

float fakemark(struct cpu_t cpu) {
  return cpu.core_count * cpu.max_freq * (1 + 0.7 * cpu.has_multithreading) + 5 * cpu.has_video;
}

struct cpu_t best_cpu(struct cpu_t cpus[10], int cpus_count) {
  struct cpu_t best = cpus[0];

  for(int i=1; i < cpus_count; i++) {
    if(fakemark(cpus[i]) > fakemark(best)) best = cpus[i];
  }

  return best;
}

int main() {
  struct cpu_t cpus[] = {
    {1, 1.4, 0, 0},
    {2, 2.4, 0, 0},
    {3, 2.4, 0, 0},
    {4, 1.4, 1, 0},
    {2, 1.4, 1, 1}
  };

  struct cpu_t best = best_cpu(cpus, 5);
  printf("%d %f %d %d %f\n", best.core_count, best.max_freq, best.has_multithreading, best.has_video, fakemark(best));

  return 0;
}
```

### Задача 3
```c
#include <stdio.h>
#include <string.h>

struct article_t {
  char title[33];
  char content[501];
};

int count_occurances(char* str, char* word) {
  int occurances = 0;
  char* substring_start = str;

  while((substring_start = strstr(substring_start, word)) != NULL) {
    occurances++;
    substring_start++;
  }

  return occurances;
}

float get_word_occurance_score(struct article_t article, char word[25]) {
  int occurances = count_occurances(article.title, word) + count_occurances(article.content, word);

  return (float)(occurances * strlen(word)) / (strlen(article.title) + strlen(article.content));
}

void sort_articles_by_word_score(struct article_t *articles, char word[25], int article_count) {
  for(int i = 0; i < article_count - 1; i++) {
    for(int j = i + 1; j < article_count; j++) {
      struct article_t left = articles[i];
      struct article_t right = articles[j];

      if(get_word_occurance_score(left, word) > get_word_occurance_score(right, word)) {
        articles[i] = right;
        articles[j] = left;
      }
    }
  }
}

int main() {
  struct article_t articles[] = {
    {"asd asd asd asd", "asd asd asd asd asd"},
    {"asd asd asd asd", "asd asd"},
    {"asd zxc", "zxc zcx"},
  };

  sort_articles_by_word_score(articles, "asd", 3);

  for(int i=0; i < 3; i++) {
    printf("%s %s\n", articles[i].title, articles[i].content);
  }

  return 0;
}
```
