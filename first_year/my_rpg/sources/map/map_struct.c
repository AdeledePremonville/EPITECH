/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** map_struct.c
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>

void set_wall_top_rects(struct map_info *mi)
{
    int left_max = 12;
    int left_min = 9;
    sfIntRect rec = {.width = 16, .height = (4 * 16), .top = (4 * 16)
    + mi->y_offset,};
    sfIntRect rec_b = {.width = 16, .height = 16, .top = (13 * 16)
    + mi->y_offset};

    for (int j = 1; j < (mi->size_y); ++j) {
        rec.left = ((rand() % (left_max - left_min + 1)) + left_min) * 16
        + mi->x_offset;
        rec_b.left = ((rand() % (7 - 6 + 1)) + 6) * 16 + mi->x_offset;
        sfSprite_setTextureRect(mi->walls[0][j], rec);
        sfSprite_setTextureRect(mi->walls[mi->size_x + 1][j], rec_b);
    }
    set_wall_walls_rects(mi);
}

void set_level_offsets(struct map_info *mi)
{
    mi->x_offset = 0;
    mi->y_offset = 0;

    if (mi->level > 3 && mi->level < 7)
        mi->y_offset = 18 * 16;
    if (mi->level > 6)
        mi->y_offset = 2 * 18 * 16;
    if (mi->level == 2 || mi->level == 5 || mi->level == 8)
        mi->x_offset = 16 * 16;
    if (mi->level == 3 || mi->level == 6 || mi->level == 9)
        mi->x_offset = 2 * 16 * 16;
}

struct map_info *fill_map_sp(unsigned int x, unsigned int y, int lvl)
{
    struct map_info *mi = malloc(sizeof(struct map_info));
    sfVector2f scale = {.x = 3, .y = 3};

    if (mi == NULL)
        return (NULL);
    mi->level = lvl;
    mi->rect_map = create_rect_map(x, y);
    mi->scale = scale;
    mi->size_x = x;
    mi->size_y = y;
    set_level_offsets(mi);
    create_map(mi);
    create_walls(mi);
    set_map_rects(mi);
    set_wall_top_rects(mi);
    return mi;
}
