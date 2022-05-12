/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante_h - dante
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef DANTE_H
    #define DANTE_H

int error_handling(int argc, char **argv);

void first_condition_map(char **map, int i, int j);

void second_condition_map(char **map, int i, int j);

void case_o(char **map, int i, int j, int nb);

void first_cond_imp_map_o(char **map, int i, int j);

void second_cond_imp_map_o(char **map, int i, int j);

void loop_for_perfect_generator(char **map, int x, int i, int nb);

void final_imp_loop(char **map, int i, int x);

void imperfect_conditions(char **map, int i, int j);

void second_cond_imp_map(char **map, int i, int j);

void first_cond_imp_map(char **map, int i, int j);

void loop_for_imperfect_generator(char **map, int x, int i, int nb);

void maze_generator_imperfect(int x, int y);

void maze_generator_perfect(int x, int y);

char **map_perfect_base(int x, int y);

void fill_imperfect_map(char **map, int i, int j, int nb);

void fill_map(char **map, int i, int j, int nb);

void random_imperfect(char **map, int y, int x);

void final_imperfect(char **map, int y, int x);

#endif /* !DANTE_H */
