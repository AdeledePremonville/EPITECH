/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Imperfect maps for Generator.
*/

#include "my.h"
#include "dante.h"

void loop_for_imperfect_generator(char **map, int x, int i, int nb)
{
    for (int j = x - 1; (j - 1) >= 0; j--) {
        fill_imperfect_map(map, i, j, nb);
        if (j - 1 == 0 && (map[i][j - 1] == 'a' || map[i][j - 1] == '*')) {
            map[i][j - 1] = '*';
            map[i - 1][j - 1] = '*';
        }
        if (i - 1 == 0 && (map[i - 1][j] == 'a' || map[i - 1][j] == '*')) {
            map[i - 1][j] = '*';
            map[i - 1][j - 1] = '*';
        }
        imperfect_conditions(map, i, j);
    }
}

void case_o(char **map, int i, int j, int nb)
{
    if (map[i][j] == 'o') {
        if (i - 1 == 0)
            nb = 0;
        else if ((i - 2) == 0)
            nb = 1;
        else
            nb = rand() % 2;
        if (nb == 0)
            first_cond_imp_map_o(map, i, j);
        if (nb == 1)
            second_cond_imp_map_o(map, i, j);
    }
}

void fill_imperfect_map(char **map, int i, int j, int nb)
{
    if (map[i][j] != 'X' && map[i][j] != 'o') {
        if (i - 1 == 0)
            nb = 0;
        else if ((i - 2) == 0)
            nb = 1;
        else
            nb = rand() % 2;
        map[i][j] = '*';
        if (nb == 0)
            first_cond_imp_map(map, i, j);
        if (nb == 1)
            second_cond_imp_map(map, i, j);
    }
    case_o(map, i, j, nb);
}

void first_cond_imp_map(char **map, int i, int j)
{
    if ((map[i][j - 1] == 'a' || (map[i][j - 1] == 'X')) && (i - 1 != 0)) {
        map[i - 1][j] = '*';
        map[i][j - 1] = 'X';
    }
    if ((map[i][j - 1] == '*' || map[i][j - 1] == 'o') && (i - 1 != 0)) {
        map[i - 1][j] = 'X';
        map[i][j - 1] == 'o' ? (map[i][j - 1] = 'o') : (map[i][j - 1] = '*');
    }
}

void second_cond_imp_map(char **map, int i, int j)
{
    if (map[i][j - 1] == 'a' || map[i][j - 1] == '*') {
        map[i][j - 1] = '*';
        map[i - 1][j] = 'X';
    }
    if (map[i][j - 1] == 'X')
        map[i - 1][j] = '*';
    if (map[i][j - 1] == 'o') {
        map[i][j - 1] = 'o';
        map[i - 1][j] = 'X';
    }
}
