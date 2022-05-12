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

static void update_pos_pnj_two(sfIntRect *rect, int direction, struct pnj **e,
int i)
{
    if (direction == 0) {
        rect->top = 192;
        e[i]->pos.y += e[i]->size_step;
    }
    if (direction == 1) {
        rect->top = 241;
        e[i]->pos.x -= e[i]->size_step;
    }
    if (direction == 2) {
        rect->top = 291;
        e[i]->pos.x += e[i]->size_step;
    }
    if (direction == 3) {
        rect->top = 337;
        e[i]->pos.y -= e[i]->size_step;
    }
    if (direction >= 4)
        rect->top = 194;
    sfSprite_setPosition(e[i]->sprite, e[i]->pos);
}

static void update_pos_pnj_one(sfIntRect *rect, int direction, struct pnj **e,
int i)
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
    sfSprite_setPosition(e[i]->sprite, e[i]->pos);
}

static void help_move_pnj(sfIntRect *rect, struct pnj **e, int i)
{
    update_pos_pnj_two(rect, e[i]->direction, e, i);
    if (e[i]->direction >= 4) {
        rect->left = 48 + ((i - 4) * 144);
        return;
    }
    i -= 4;
    if (rect->left < 90 + i * 144) {
        rect->left += 48;
    } else {
        rect->left = 0 + i * 144;
    }
}

void move_pnj(sfIntRect *rect, struct pnj **e, int i)
{
    if (i <= 3) {
        update_pos_pnj_one(rect, e[i]->direction, e, i);
        if (e[i]->direction >= 4) {
            rect->left = 48 + i * 144;
            return;
        }
        if (rect->left < 90 + i * 144) {
            rect->left += 48;
            return;
        }
        rect->left = 0 + i * 144;
        return;
    }
    help_move_pnj(rect, e, i);
}
