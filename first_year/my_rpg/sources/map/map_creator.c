/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** map_creator.c
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>

void set_map_rects(struct map_info *mi)
{
    sfIntRect rec;

    for (int i = 0; i < mi->size_x; ++i) {
        for (int j = 0; j < mi->size_y; ++j) {
            rec = get_floor_rect(mi->rect_map[i][j], mi);
            sfSprite_setTextureRect(mi->map[i][j], rec);
        }
    }
}

int **create_rect_map(unsigned int x, unsigned int y)
{
    int **rect_map = malloc(sizeof(int*) * x);

    for (int i = 0; i < x; ++i) {
        rect_map[i] = malloc(sizeof(int) * y);
        for (int j = 0; j < y; ++j) {
            rect_map[i][j] = FLOOR;
        }
    }
    return rect_map;
}

void create_map(struct map_info *mi)
{
    sfSprite ***map = malloc(mi->size_x * sizeof(sfSprite**));
    sfTexture *t = sfTexture_createFromFile("sprites/cavern_sheet.png", NULL);

    for (int i = 0; i < mi->size_x; ++i)
        map[i] = malloc(mi->size_y * sizeof(sfSprite*));
    for (int i = 0; i < mi->size_x; ++i) {
        for (int j = 0; j < mi->size_y; ++j) {
            map[i][j] = sfSprite_create();
            sfSprite_setTexture(map[i][j], t, sfFalse);
        }
    }
    mi->map = map;
    mi->items = map;
}

void create_walls(struct map_info *mi)
{
    sfSprite ***walls = malloc((mi->size_x + 2)  * sizeof(sfSprite**));
    sfTexture *t = sfTexture_createFromFile("sprites/cavern_sheet.png", NULL);
    sfIntRect rec = {.width = 1, .height = 1};

    for (int i = 0; i < (mi->size_x + 2); ++i)
        walls[i] = malloc((mi->size_y) * sizeof(sfSprite*));
    for (int i = 0; i < (mi->size_x + 2); ++i) {
        for (int j = 0; j < (mi->size_y); ++j) {
            walls[i][j] = sfSprite_create();
            sfSprite_setTexture(walls[i][j], t, sfFalse);
            sfSprite_setTextureRect(walls[i][j], rec);
        }
    }
    mi->walls = walls;
}

void display_map(struct map_info *mi, sfRenderWindow *win)
{
    sfVector2f pos = {.x = 0.0, .y = 0.0};
    sfVector2u w_size = sfRenderWindow_getSize(win);
    int xoffset = (w_size.x / 2) - ((mi->size_y * 16 * mi->scale.x) / 2);
    int yoffset = (w_size.y / 2) - ((mi->size_x * 16 * mi->scale.y) / 2)
    + 30 * mi->scale.y;

    for (int i = 0; i < mi->size_x; ++i) {
        for (int j = 0; j < mi->size_y; ++j) {
            pos.x = j * (16 * mi->scale.x) + xoffset;
            pos.y = i * (16 * mi->scale.y) + yoffset;
            sfRenderWindow_drawSprite(win, mi->map[i][j], NULL);
            sfSprite_setScale(mi->map[i][j], mi->scale);
            sfSprite_setPosition(mi->map[i][j], pos);
        }
    }
    display_walls(mi, win);
}
