/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** map_destroyer.c
*/

#include "p.h"
#include "my.h"
#include <stdlib.h>

void clean_struct(struct map_info *mi)
{
    for (int i = 0; i < mi->size_x; ++i) {
        for (int j = 0; j < mi->size_y; ++j) {
            sfSprite_destroy(mi->map[i][j]);
            sfSprite_destroy(mi->items[i][j]);
        }
        free(mi->map[i]);
        free(mi->items[i]);
    }
    free(mi->map);
    free(mi->items);
    free(mi->rect_map);
    free(mi);
}
