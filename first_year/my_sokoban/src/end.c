/*
** EPITECH PROJECT, 2022
** end.c
** File description:
** game end - sokoban project
*/

#include "my.h"
#include "sokoban.h"

int nb_storage(char **map, char type)
{
    int nb = 0;
    map_t *co = malloc(sizeof(map_t));

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            co->i = i;
            co->j = j;
            nb = nb_stockage(map, nb, co, type);
        }
    }
    return nb;
}

bool box_on_place(char **map, char **map1, int nb)
{
    map_t *co = malloc(sizeof(map_t));

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            co->i = i;
            co->j = j;
            nb = boxes_on_place(map, map1, co, nb);
        }
    }
    if (nb == 0)
        return true;
    return false;
}

bool box_possibilities(char **map, int i, int j)
{
    char line_b = map[i - 1][j];
    char line_a = map[i + 1][j];
    char col_b = map[i][j - 1];
    char col_a = map[i][j + 1];

    if ((line_b != '#' && line_b != 'X' && line_a != '#' && line_a != 'X'))
        return true;
    if ((col_b != '#' && col_b != 'X' && col_a != '#' && col_a != 'X'))
        return true;
    return false;
}

bool box_stuck(char **map)
{
    int nb = nb_storage(map, 'X');

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            nb = boxes_stuck(map, i, j, nb);
    }
    if (nb == 0)
        return true;
    return false;
}

int is_game_finished(char **map, char **map1)
{
    int nb1 = nb_storage(map1, 'O');
    int nb = nb_storage(map, 'O');

    if (nb == 0 && box_on_place(map, map1, nb1) == true)
        return 1;
    if (box_stuck(map) == true)
        return 2;
    return 0;
}
