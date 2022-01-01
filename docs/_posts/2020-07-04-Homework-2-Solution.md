---
title: Решение на домашно 2
category: задачи
tags:
  - материали
  - задачи
  - домашни
---

[Условие](https://docs.google.com/document/d/1zIB0772FGLK0FhUUf-ta6lGcMm9FKT-1yev2WW_ePRY/edit?usp=sharing)

```c
// game.h
#ifndef GAME_H
#define GAME_H

#define BOARD_SIZE 16
#define PLAYER_COUNT 4

struct player_t {
  char name[11];
  int number;
};

struct game_t {
  int curr_round;
  struct player_t** players;
  int player_count;
  int alive_player_count;
  int board[BOARD_SIZE];
};

struct game_t* init_game();

void add_player(struct game_t* game, char* player_name);

struct game_t* read_from_file();

void play_game(struct game_t* game);

#endif
```

```c
// game_private.h
#ifndef GAME_PRIVATE_H
#define GAME_PRIVATE_H

#include "game.h"

void print_board(struct game_t* game);

void print_players(struct game_t* game);

void print_game_info(struct game_t* game);


int find_pos_from_player(struct game_t* game, struct player_t* player);

struct player_t* find_player_from_pos(struct game_t* game, int pos);


int roll_die();

void remove_player(struct game_t* game, struct player_t* player);

void move_player(struct game_t* game, struct player_t* player);

int play_round(struct game_t* game);

struct player_t* find_winner(struct game_t* game);

#endif
```

```c
// game.c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "game.h"
#include "game_private.h"

int roll_die() {
  return 1 + rand() % 6;
}

int find_pos_from_player(struct game_t* game, struct player_t* player) {
  for(int i = 0; i < BOARD_SIZE; i++) {
    if(game->board[i] == player->number) {
      return i;
    }
  }

  return 0;
}

struct player_t* find_player_from_pos(struct game_t* game, int pos) {
  for(int i = 0; i < game->player_count; i++) {
    if(game->players[i] != NULL && game->players[i]->number == pos) {
      return game->players[i];
    }
  }

  return NULL;
}

void remove_player(struct game_t* game, struct player_t* player) {
  for(int i = 0; i < game->player_count; i++) {
    if(game->players[i] == player) {
      game->players[i] = NULL;
      game->alive_player_count--;
      break;
    }
  }
}

void print_board(struct game_t* game) {
  printf("[D] [");
  for(int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", game->board[i]);
  }
  puts("]");
}

void print_players(struct game_t* game) {
  for(int i = 0; i < game->player_count; i++) {
    struct player_t* p = game->players[i];
    printf("[D] i=%d name=%s number=%d\n", i, p->name, p->number);
  }
}

void move_player(struct game_t* game, struct player_t* player) {
  printf("Moving player %s\n", player->name);
  int roll = roll_die();
  printf("Rolled %d\n", roll);
  int old_pos = find_pos_from_player(game, player);
  int new_pos = (old_pos + roll) % BOARD_SIZE;
  #ifdef DEBUG
    printf("[D] old_pos=%d new_pos=%d\n", old_pos, new_pos);
  #endif

  if(game->board[new_pos] != 0) {
    struct player_t* other = find_player_from_pos(game, game->board[new_pos]);
    remove_player(game, other);
    printf("Eliminated player %s\n", other->name);
  }
  game->board[new_pos] = player->number;
  game->board[old_pos] = 0;
}

int play_round(struct game_t* game) {
  printf("Starting round %d\n", ++game->curr_round);

  for(int i = 0; i < game->player_count; i++) {
    if(game->players[i] != NULL) {
      move_player(game, game->players[i]);
      #ifdef DEBUG
        print_board(game);
      #endif
    }

    if(game->alive_player_count == 1) {
      return 1;
    }
  }

  return 0;
}

struct player_t* find_winner(struct game_t* game) {
  for(int i = 0; i < game->player_count; i++) {
    if(game->players[i] != NULL) {
      return game->players[i];
    }
  }

  return NULL;
}

void print_game_info(struct game_t* game) {
  printf("[D] Start playing with:\n");
  printf("[D] round=%d players=%d alive players=%d\n", game->curr_round, game->player_count, game->alive_player_count);
  print_players(game);
  print_board(game);
}

void play_game(struct game_t* game) {
  #ifdef DEBUG
    print_game_info(game);
  #endif

  while(!play_round(game)) {}
  printf("Game Over. Player %s wins.\n", find_winner(game)->name);
}

struct game_t* init_game() {
  struct game_t* game = malloc(sizeof(struct game_t));

  game->curr_round = 0;
  game->alive_player_count = 0;
  game->player_count = 0;

  game->players = NULL;

  for(int i = 0; i < BOARD_SIZE; i++) {
    game->board[i] = 0;
  }

  return game;
}

void add_player(struct game_t* game, char* player_name) {
  struct player_t* new_player = malloc(sizeof(struct player_t));

  strcpy(new_player->name, player_name);
  new_player->number = game->player_count + 1;

  game->players = realloc(game->players, sizeof(struct player_t*) * (game->player_count + 1));
  game->players[game->player_count] = new_player;
  game->player_count++;
  game->alive_player_count++;
}

struct game_t* read_from_file() {
  struct game_t* game = init_game();

  FILE* game_file = fopen("game.txt", "r");
  if(!game_file) {
    puts("Error reading file!");
    exit(EXIT_FAILURE);
  }
  fscanf(game_file, "%d", &game->curr_round);

  char player_name[11];
  int player_number;
  int player_pos;
  while(fscanf(game_file, "%s %d %d", player_name, &player_number, &player_pos) != EOF) {
    #ifdef DEBUG
    printf("[D] Read line for player: %s %d %d\n", player_name, player_number, player_pos);
    #endif
    add_player(game, player_name);
    game->players[game->player_count-1]->number = player_number;
    game->board[player_pos] = player_number;
  }

  fclose(game_file);

  return game;
}
```

```c
// main.c
#include <time.h>
#include <stdlib.h>

#define DEBUG

#include "game.h"

int main() {
  srand(time(NULL));

  /*struct game_t* game = init_game();
  add_player(game, "player1");
  add_player(game, "player2");
  add_player(game, "player3");
  add_player(game, "player4");*/

  struct game_t* game = read_from_file();

  play_game(game);

  return 0;
}
```

```c
// makefile
default:
	gcc -Wall -pedantic -std=c11 main.c game.c -o game

clean:
	rm game
```

```c
// game.txt
2
Todor 1 5
Ivan 2 7
Petar 3 13
Georgi 4 10
```
