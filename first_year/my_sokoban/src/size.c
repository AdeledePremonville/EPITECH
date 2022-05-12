/*
** EPITECH PROJECT, 2022
** size.c
** File description:
** size file - sokoban
*/

#include "my.h"
#include "sokoban.h"

void case2(int key, char **map, char **map1, char **res)
{
    int *player_pos = get_player_pos(map);
    position_t *pos;

    switch (key) {
    case KEY_RIGHT:
        pos = init_position(player_pos[0], player_pos[1] + 1);
        case_move(res, pos, map1, key);
        break;
        case KEY_LEFT:
        pos = init_position(player_pos[0], player_pos[1] - 1);
        case_move(res, pos, map1, key);
        break;
    }
}

void player_pos(char **map, int i, int j, char **res)
{
    if (map[i][j] == 'P') {
        res[0] = i;
        res[1] = j;
    }
}

int boxes_stuck(char **map, int i, int j, int nb)
{
    int res = nb;

    if (map[i][j] == 'X' && box_possibilities(map, i, j) == false)
        res--;
    return res;
}

int nb_stockage(char **map, int nb, map_t *co, char type)
{
    int res = nb;

    if(map[co->i][co->j] == type)
        res++;
    return res;
}

int boxes_on_place(char **map, char **map1, map_t *co, int nb)
{
    int res = nb;

    if (map1[co->i][co->j] == 'O' && map[co->i][co->j] == 'X')
        res--;
    return res;
}