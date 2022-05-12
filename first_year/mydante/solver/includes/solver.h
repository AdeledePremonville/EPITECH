/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Lib for Solver.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef SOLVER_H_
    #define SOLVER_H_

typedef struct map_s {
    int x;
    int y;
    int fd;
    char *buffer;
    char **map;
    int **tab;
} map_t;

void algorithm(map_t *map);

void moves(map_t *map);

void move_down_first(map_t *map);

void move_down_mid(map_t *map);

void move_up_mid(map_t *map);

void move_right_mid(map_t *map);

void move_left_mid(map_t *map);

void move_right_first(map_t *map);

void move_right_only(map_t *map);

void move_left_only(map_t *map);

void move_up_only(map_t *map);

void move_down_only(map_t *map);

int handle_errors(int argc);

void create_int_tab(map_t *map);

void convert_tab_into_map(map_t *map);

int count_columns(char *buffer);

int run_solver(map_t *map);

void transform_map(map_t *map);

void loop_for_map_tab(map_t *map, int **res, int i);

int **map_tab(map_t *map);

void loop_for_transform_map(map_t *map, int x, int y);

int count_tab_line(int i, int j, map_t *map);

int count_lines(char *str);

void fill_tab(map_t *map);

void display_map(map_t *map);

void display_int_tab(map_t *map);

char *extract_file(map_t *map, char const *path);

void convert_map(map_t *map, int i, int j);

void convert_end_map(map_t *map);

int count_columns(char *buffer);

int check_end(map_t *map);

int check_issues_nb(char **map, int i, int j);

#endif /* !SOLVER_H_ */
