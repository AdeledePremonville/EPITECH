/*
** EPITECH PROJECT, 2021
** menu_rpg.c
** File description:
** menu for rpg
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void update_pos(sfIntRect *rect, int direction, struct enemy_map **e, int i)
{
    if (direction == 0) {
        rect->top = 0;
        e[i]->pos.y += e[i]->size_step;
    }
    if (direction == 1) {
        rect->top = 48;
        e[i]->pos.x -= e[i]->size_step;
    }
    if (direction == 2) {
        rect->top = 96;
        e[i]->pos.x += e[i]->size_step;
    }
    if (direction == 3) {
        rect->top = 144;
        e[i]->pos.y -= e[i]->size_step;
    }
    if (direction >= 4)
        rect->top = 0;
    sfSprite_setPosition(e[i]->sprite, e[i]->pos);
}

void move_monster(sfIntRect *rect, struct enemy_map **e, int i)
{
    update_pos(rect, e[i]->direction, e, i);
    if (rect->left < 90 + i * 144) {
        rect->left += 48;
    } else {
        rect->left = 0 + i * 144;
    }
}

void anim_monster(struct enemy_map **e)
{
    for (int i = 0; e[i] != NULL; i++) {
        e[i]->time = sfClock_getElapsedTime(e[i]->clock);
        if (e[i]->time.microseconds > e[i]->speed) {
            sfClock_restart(e[i]->clock);
            move_monster(e[i]->rect, e, i);
            e[i]->time.microseconds -= e[i]->speed;
            sfSprite_setTextureRect(e[i]->sprite, e[i]->rect[0]);
            e[i]->nb_step++;
        }
        if (e[i]->nb_step >= e[i]->max_step) {
            e[i]->direction = rand_max(e[i]->nb_dir);
            e[i]->nb_step = 0;
        }
    }
}

void draw_enemy_map(sfRenderWindow *window, struct enemy_map **e)
{
    for (int i = 0; e[i] != NULL; i++) {
        if (e[i]->alive == true && e[i]->pos.x <= LEN_X
        && e[i]->pos.y <= LEN_Y && e[i]->pos.x > POS_X && e[i]->pos.y > POS_Y)
            sfRenderWindow_drawSprite(window, e[i]->sprite, NULL);
    }
}
