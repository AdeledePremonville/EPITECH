/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Tools 2 for Solver.
*/

#include "my.h"
#include "solver.h"

int count_columns(char *buffer)
{
    int counter = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        counter++;
    return (counter);
}

int **map_tab(map_t *map)
{
    int **res = malloc(sizeof(int *) * (count_lines(map->buffer) + 1));

    for (int i = 0; i < count_lines(map->buffer); i++)
        res[i] = malloc(sizeof(int) * (count_columns(map->buffer) + 1));
    for (int i = 0; i < count_lines(map->buffer); i++)
        loop_for_map_tab(map, res, i);
    return res;
}

void loop_for_map_tab(map_t *map, int **res, int i)
{
    for (int j = 0; j < count_columns(map->buffer); j++) {
        if (map->map[i][j] == '*')
            res[i][j] = 1;
        if (map->map[i][j] == 'X')
            res[i][j] = 0;
    }
}
