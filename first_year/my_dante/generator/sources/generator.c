/*
** EPITECH PROJECT, 2022
** dante
** File description:
** generator - dante
*/

#include "my.h"
#include "dante.h"

void fill_second_line(char **map, int x, int y)
{
    if (x >= 2 && y >= 2) {
        for (int i = 0; i < y; i++) {
            if (map[1][i] == '*') {
                map[1][i] = 'X';
            }
        }
        for (int j = 0; j < x; j++) {
            if (map[j][1] == '*') {
                map[j][1] = 'X';
            }
        }
    }
}

void maze_generator_imperfect(int x, int y)
{
    char **map = map_perfect_base(x, y);
    int nb = 0;

    map[y - 1][x - 1] = 'o';
    for (int i = y - 1; (i - 1) >= 0; i--)
        loop_for_imperfect_generator(map, x, i, nb);
    random_imperfect(map, y, x);
    fill_second_line(map, y, x);
    final_imperfect(map, y, x);
    for (int i = 0; i < y - 1; i++)
        printf("%s\n", map[i]);
    printf(map[y - 1]);
}

char **map_perfect_base(int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));

    srand(time(NULL));
    for (int i = 0; i < y; i++)
        map[i] = malloc(sizeof(char) * (x + 1));
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            map[i][j] = 'a';
    }
    return map;
}

void fill_map(char **map, int i, int j, int nb)
{
    if (map[i][j] != 'X') {
        if (i - 1 == 0)
            nb = 0;
        else if ((i - 2) == 0)
            nb = 1;
        else
            nb = rand() % 2;
        map[i][j] = '*';
        if (nb == 0)
            first_condition_map(map, i, j);
        if (nb == 1)
            second_condition_map(map, i, j);
    }
}

void maze_generator_perfect(int x, int y)
{
    char **map = map_perfect_base(x, y);
    int nb = 0;

    for (int i = y - 1; (i - 1) >= 0; i--)
        loop_for_perfect_generator(map, x, i, nb);
    for (int i = 0; i < y - 1; i++)
        printf("%s\n", map[i]);
    printf(map[y - 1]);
}
