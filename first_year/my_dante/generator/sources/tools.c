/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Tools for Generator.
*/

#include "my.h"
#include "dante.h"

void first_condition_map(char **map, int i, int j)
{
    if (map[i][j - 1] == 'a' || (map[i][j - 1] == 'X' && (i - 1 != 0))) {
        map[i - 1][j] = '*';
        map[i][j - 1] = 'X';
    }
    if (map[i][j - 1] == '*' && (i - 1 != 0))
        map[i - 1][j] = 'X';
}

void second_condition_map(char **map, int i, int j)
{
    if (map[i][j - 1] == 'a' || map[i][j - 1] == '*') {
        map[i][j - 1] = '*';
        map[i - 1][j] = 'X';
    }
    if (map[i][j - 1] == 'X')
        map[i - 1][j] = '*';
}

void loop_for_perfect_generator(char **map, int x, int i, int nb)
{
    for (int j = x - 1; (j - 1) >= 0; j--) {
        fill_map(map, i, j, nb);
        if (j - 1 == 0 && (map[i][j - 1] == 'a' || map[i][j - 1] == '*')) {
            map[i][j - 1] = '*';
            map[i - 1][j - 1] = '*';
        }
        if (i - 1 == 0 && (map[i - 1][j] == 'a' || map[i - 1][j] == '*')) {
            map[i - 1][j] = '*';
            map[i - 1][j - 1] = '*';
        }
    }
}
