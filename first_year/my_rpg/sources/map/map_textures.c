/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** map_textures.c
*/

#include "my.h"
#include "p.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

sfIntRect random_floor(struct map_info *mi)
{
    sfIntRect rec = {.left = 16 * 9, .top = 16 * 8, .width = 16, .height = 16};
    int left_max = 11;
    int left_min = 9;
    int top_max = 10;
    int top_min = 8;

    rec.left = ((rand() % (left_max - left_min + 1)) + left_min) * 16
    + mi->x_offset;
    rec.top = ((rand() % (top_max - top_min + 1)) + top_min) * 16
    + mi->y_offset;
    return rec;
}

sfIntRect get_floor_rect(int index, struct map_info *mi)
{
    sfIntRect rec;

    switch (index) {
    case FLOOR:
        rec = random_floor(mi);
        break;
    default:
        break;
    }
    return rec;
}
