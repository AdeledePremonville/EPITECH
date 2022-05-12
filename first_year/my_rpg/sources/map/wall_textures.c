/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** wall_textures.c
*/

#include "my.h"
#include "p.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>

void set_w_rect_s(struct map_info *m, sfIntRect rec, sfIntRect rec_t, int t[2])
{
    int top_min = t[0];
    int top_max = t[1];

    for (int i = 1; i < m->size_x; ++i) {
        rec.top = ((rand() % (top_max - top_min + 1)) + top_min) * 16
        + m->y_offset;
        rec_t.top = ((rand() % ((11) - (7) + 1)) + (7)) * 16
        + m->y_offset;
        if (i == m->size_x - 1) {
            rec.top = (12 * 16) + m->y_offset;
            rec_t.top = (12 * 16) + m->y_offset;
            rec_t.left = (14 * 16) + m->x_offset;
        }
        sfSprite_setTextureRect(m->walls[i][0], rec);
        sfSprite_setTextureRect(m->walls[i][m->size_y - 1], rec_t);
    }
}

void set_wall_walls_rects(struct map_info *mi)
{
    sfIntRect rec = {.width = 16, .height = (4 * 16),
    .left = (4 * 16) + mi->x_offset, .top = (4 * 16) + mi->y_offset};
    sfIntRect rec_t = {.width = 16, .height = (4 * 16),
    .left = (15 * 16) + mi->x_offset, .top = (6 * 16) + mi->y_offset};
    int top_max = 10;
    int top_min = 5;

    sfSprite_setTextureRect(mi->walls[0][0], rec);
    sfSprite_setTextureRect(mi->walls[0][mi->size_y - 1], rec_t);
    rec.height = 16;
    rec.top += 16;
    rec_t.height = 16;
    rec_t.top += 16;
    set_w_rect_s(mi, rec, rec_t, (int[2]){top_min, top_max});
}

sfVector2f display_corner(struct map_info *mi, sfRenderWindow *win,
sfVector2f pos)
{
    sfSprite_setPosition(mi->walls[0][0], pos);
    sfSprite_setScale(mi->walls[0][0], mi->scale);
    sfRenderWindow_drawSprite(win, mi->walls[0][0], NULL);
    pos.y += (16 * mi->scale.y) * 4;
    for (int i = 1; i < (mi->size_x + 2); ++i) {
        sfSprite_setPosition(mi->walls[i][0], pos);
        sfSprite_setScale(mi->walls[i][0], mi->scale);
        sfRenderWindow_drawSprite(win, mi->walls[i][0], NULL);
        pos.y += (16 * mi->scale.y);
    }
    pos = sfSprite_getPosition(mi->map[0][0]);
    pos.y -= ((16 * mi->scale.y) * 3);
    return pos;
}

void display_final(struct map_info *mi, sfRenderWindow *win, sfVector2f pos)
{
    pos = sfSprite_getPosition(mi->map[0][mi->size_y - 1]);
    for (int i = 1; i < (mi->size_x); ++i) {
        pos.y += (16 * mi->scale.y);
        sfSprite_setPosition(mi->walls[i][mi->size_y - 1], pos);
        sfSprite_setScale(mi->walls[i][mi->size_y - 1], mi->scale);
        sfRenderWindow_drawSprite(win, mi->walls[i][mi->size_y - 1], NULL);
    }
    pos = sfSprite_getPosition(mi->map[mi->size_x - 1][0]);
    pos.x -= (16 * mi->scale.x);
    for (int i = 0; i < (mi->size_y - 1); ++i) {
        pos.x += (16 * mi->scale.x);
        sfSprite_setPosition(mi->walls[mi->size_x + 1][i], pos);
        sfSprite_setScale(mi->walls[mi->size_x + 1][i], mi->scale);
        sfRenderWindow_drawSprite(win, mi->walls[mi->size_x + 1][i], NULL);
    }
}

void display_walls(struct map_info *mi, sfRenderWindow *win)
{
    sfVector2f pos = sfSprite_getPosition(mi->map[0][0]);
    pos.y -= ((16 * mi->scale.y) * 3);

    pos = display_corner(mi, win, pos);
    for (int j = 0; j < (mi->size_y); ++j) {
        sfSprite_setPosition(mi->walls[0][j], pos);
        sfSprite_setScale(mi->walls[0][j], mi->scale);
        sfRenderWindow_drawSprite(win, mi->walls[0][j], NULL);
        pos.x += (16 * mi->scale.x);
    }
    display_final(mi, win, pos);
}
