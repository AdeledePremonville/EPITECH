/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Tools for Dante Project.
*/

#include "my.h"
#include "solver.h"

void fill_tab(map_t *map)
{
    map->map = my_str_to_word_array(map->buffer, '\n');
}

void display_map(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++)
        printf("%s\n", map->map[i]);
}

void display_int_tab(map_t *map)
{
    for (int i = 0; i < count_lines(map->buffer); i++) {
        for (int j = 0; j < count_columns(map->buffer); j++)
            printf("%d", map->tab[i][j]);
        printf("\n");
    }
}

int count_lines(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            counter++;
    }
    return (counter);
}

int count_tab_line(int i, int j, map_t *map)
{
    int counter = 0;

    while (map->map[i][j] != '\0') {
        counter++;
        j++;
    }
    return counter;
}
