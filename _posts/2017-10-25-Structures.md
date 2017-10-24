---
title: Лекция 04 - Структури
category: лекции
---

Качена е презентацията от лекцията за структури в С.

[Линк към презентацията](https://docs.google.com/presentation/d/e/2PACX-1vSh4b5QguWkQvGVejnEZIeb8hGSHd0kn5tab78IeLNTCuYPeyiXs1IrXVlTPfYtDCoH7xMOStvTJrvk/pub?start=false&loop=false&delayms=3000)

{% include presentation id="2PACX-1vSh4b5QguWkQvGVejnEZIeb8hGSHd0kn5tab78IeLNTCuYPeyiXs1IrXVlTPfYtDCoH7xMOStvTJrvk" %}

## Задачи от час

```c
// points.c
#include<stdio.h>

struct point_t {
    int x;
    int y;
};

struct point_t add(struct point_t one, struct point_t another);

int main() {

    struct point_t begin = {0, 0};
    struct point_t end = {
        .x = 25,
        .y = 45
    };

    printf("begin[%d, %d]\n", begin.x, begin.y);
    printf("end[%d, %d]\n", end.x, end.y);

    struct point_t third = add(begin, end);

    return 0;
}

struct point_t add(struct point_t one, struct point_t another) {
    struct point_t result;

    // also valid:
    // struct point_t result_cool = {one.x + another.x, one.y + another.y};

    result.x = one.x + another.x;
    result.y = one.y + another.y;

    return result;

}
```

```c
// time.c
#include<stdio.h>

struct time_t {
    int hours;
    int minutes;
};

int is_lunch_break(struct time_t current_time);
int is_before(struct time_t one, struct time_t another);

int main() {

    {
        struct time_t current = {13, 40};
        printf("13:40 is time for a brake = %d\n", is_lunch_break(current));
        struct time_t in_future = {19, 59};

        printf("is 19:59 before 13:40 = %d\n", is_before(current, in_future));
    }

    return 0;
}

int is_lunch_break(struct time_t time) {
    int lunch_time = 0;

    if (time.hours == 12 && time.minutes > 15) {
       lunch_time = 1;
    } else if (time.hours == 13) {
        lunch_time = 1;
    } else if (time.hours == 14 && time.minutes < 23) {
        lunch_time = 1;
    }

    // Ne sega, ne nikoga
    // lunch_time = time.hours == 12 && time.minutes > 15;
    // lunch_time |= time.hours == 13
    // lunch_time |= time.hours == 14 && time.minutes < 23;

    return lunch_time;
}

int is_before(struct time_t one, struct time_t another) {
    int before = 0;

    if (another.hours < one.hours) {
        before = 1;
    } else if (another.hours == one.hours) {
        if (another.minutes < one.minutes) {
            before = 1;
        }
    }

    return before;
}
```
