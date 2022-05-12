/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Conditions for imperfect maps.
*/

#include "dante.h"
#include "my.h"

void imperfect_conditions(char **map, int i, int j)
{
    if (i - 1 == 0 && map[i][j] == 'o' && (map[i - 1][j] == 'a' ||
        map[i - 1][j] == '*' || map[i - 1][j] == 'o')) {
        map[i - 1][j] = 'o';
        map[i - 1][j - 1] = 'o';
    }
    if (i - 1 == 0 && map[i - 1][j] == 'o')
        map[i - 1][j - 1] = 'o';
    if (j - 1 == 0 && map[i][j] == 'o' && (map[i][j - 1] == 'a' ||
        map[i][j - 1] == '*' || map[i][j - 1] == 'o')) {
        map[i][j - 1] = 'o';
        map[i - 1][j - 1] = 'o';
    }
    if (j - 1 == 0 && map[i][j - 1] == 'o')
        map[i - 1][j - 1] = 'o';
}

void final_imp_loop(char **map, int i, int x)
{
    for (int j = 0; j < x; j++) {
        if (map[i][j] == 'o')
            map[i][j] = '*';
    }
}
