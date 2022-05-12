/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban EPITECH project
*/

#include "sokoban.h"
#include "my.h"

position_t *init_position(int line, int column)
{
    position_t *res = malloc(sizeof(position_t));

    res->line = line;
    res->column = column;
    return res;
}

void print_map(char **map)
{
    int len = my_arraylen(map);

    for (int i = len - 1; i >= 0; i--)
        mvprintw(LINES / 2 + i, COLS / 2, "%s", map[i]);
}

int *get_player_pos(char **map)
{
    int *res = malloc(sizeof(int) * (2 + 1));

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'P') {
                res[0] = i;
                res[1] = j;
            }
        }
    }
    return res;
}

char **new_map(int key, char **map, char **map1)
{
    int *player_pos = get_player_pos(map);
    char **res = map;
    position_t *pos;

    switch (key) {
        case KEY_UP:
        pos = init_position(player_pos[0] - 1, player_pos[1]);
        case_move(res, pos, map1, key);
        break;
        case KEY_DOWN:
        pos = init_position(player_pos[0] + 1, player_pos[1]);
        case_move(res, pos, map1, key);
        break;
        default:
        case2(key, map, map1, res);
        break;
    }
    return res;
}

int sokoban(char *buffer)
{
    int key;
    char **map = str_to_word_array(buffer, '\n');
    char **map1 = str_to_word_array(buffer, '\n');

    init_soko(map);
    while (key != ' ' && is_game_finished(map, map1) == 0) {
        key = getch();
        map = new_map(key, map, map1);
        print_map(map);
    }
    refresh();
    if (key == ' ')
        sokoban(buffer);
    sleep(5);
    endwin();
    if (is_game_finished(map, map1) == 1)
        return 1;
    return 0;
}
