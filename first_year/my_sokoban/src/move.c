/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move file - sokoban
*/

#include "my.h"
#include "sokoban.h"

void move_player(char **map, position_t *pos, char **map1)
{
    int *player_pos = get_player_pos(map);
    int p_l = player_pos[0];
    int p_c = player_pos[1];
    char origin = map1[p_l][p_c];

    (origin == 'O')?(map[p_l][p_c] = origin):(map[p_l][p_c] = ' ');
    map[pos->line][pos->column] = 'P';
}

void move_box_case(char **map, position_t *pos, position_t *box, char **map1)
{
    char place = map[box->line][box->column];

    if (place == ' ' || place == 'O') {
        map[box->line][box->column] = 'X';
        move_player(map, pos, map1);
    }
}

void move_boxes(char **map, int key, position_t *pos, char **map1)
{
    position_t *box_pos;

    switch (key) {
        case KEY_UP:
        box_pos = init_position(pos->line - 1, pos->column);
        move_box_case(map, pos, box_pos, map1);
        break;
        case KEY_DOWN:
        box_pos = init_position(pos->line + 1, pos->column);
        move_box_case(map, pos, box_pos, map1);
        break;
        case KEY_RIGHT:
        box_pos = init_position(pos->line, pos->column + 1);
        move_box_case(map, pos, box_pos, map1);
        break;
        case KEY_LEFT:
        box_pos = init_position(pos->line, pos->column - 1);
        move_box_case(map, pos, box_pos, map1);
        break;
    }
}

void case_move(char **map, position_t *pos, char **map1, int key)
{
    switch (map[pos->line][pos->column]) {
        case ' ':
        case 'O':
        move_player(map, pos, map1);
        break;
        case 'X':
        move_boxes(map, key, pos, map1);
        break;
    }
}

void init_soko(char **map)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    print_map(map);
}