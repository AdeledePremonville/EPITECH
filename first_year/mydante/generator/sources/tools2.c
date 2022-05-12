/*
** EPITECH PROJECT, 2022
** Dante Project
** File description:
** Tools 2 for Imperfect generator.
*/

#include "my.h"
#include "dante.h"

void first_cond_imp_map_o(char **map, int i, int j)
{
    if ((map[i][j - 1] == 'a' || (map[i][j - 1] == 'X')) && (i - 1 != 0)) {
        map[i - 1][j] = 'o';
        map[i][j - 1] = 'X';
    }
    if ((map[i][j - 1] == '*' || map[i][j - 1] == 'o') && (i - 1 != 0)) {
        map[i - 1][j] = 'X';
        map[i][j - 1] = 'o';
    }
    if (i - 1 == 0 && (map[i][j - 1] == '*' || map[i][j - 1] == 'a')) {
        map[i][j - 1] = 'X';
    }
}

void second_cond_imp_map_o(char **map, int i, int j)
{
    if (map[i][j - 1] == 'a' || map[i][j - 1] == '*') {
        map[i][j - 1] = 'o';
        map[i - 1][j] = 'X';
    }
    if (map[i][j - 1] == 'X')
        map[i - 1][j] = 'o';
    if (map[i][j - 1] == 'o') {
        map[i - 1][j] = 'X';
    }
}

int get_empty_path_nb(char **map, int y, int x)
{
    int res = 0;

    for (int i = y - 1; (i - 1) >= 0; i--) {
        for (int j = x - 1; (j - 1) >= 0; j--) {
            if (map[i][j] == '*')
                res++;
        }
    }
    return res;
}

void random_imperfect(char **map, int y, int x)
{
    int nb_empty = get_empty_path_nb(map, y, x);
    int randNum = rand() % (nb_empty - 1 + 1) + 1;
    int count = 0;
    int i = 0;
    int j = 0;

    while (count <= 1) {
        for (int k = 0; k <= randNum; k++) {
            i = rand() % (y - 1);
            j = rand() % (x - 1);
            if (map[i][j] == '*') {
                count++;
                map[i][j] = 'X';
            }
        }
    }
}

void final_imperfect(char **map, int y, int x)
{
    for (int i = 0; i < y; i++)
        final_imp_loop(map, i, x);
}
