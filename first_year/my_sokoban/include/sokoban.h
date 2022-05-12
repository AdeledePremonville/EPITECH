/*
** EPITECH PROJECT, 2022
** SOKOBAN.H
** File description:
** sokoban projet
*/

#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>

#ifndef SOKOBAN_H
    #define SOKOBAN_H

typedef struct position_t
{
    int line;
    int column;
} position_t;

typedef struct map_t
{
    int i;
    int j;
} map_t;

int sokoban(char *buffer);
char **new_map(int key, char **map, char **map1);
position_t *init_position(int line, int column);
int *get_player_pos(char **map);
void print_map(char **map);
bool is_term_small(int LINES, int COLS, char **map);
int is_game_finished(char **map, char **map1);
void move_player(char **map, position_t *pos, char **map1);
void case_move(char **map, position_t *pos, char **map1, int key);
void case2(int key, char **map, char **map1, char **res);
void player_pos(char **map, int i, int j, char **res);
int boxes_stuck(char **map, int i, int j, int nb);
int nb_stockage(char **map, int nb, map_t *co, char type);
void init_soko(char **map);
int boxes_on_place(char **map, char **map1, map_t *co, int nb);

#endif //SOKOBAN_H
