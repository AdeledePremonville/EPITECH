/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** demon_init
*/

#include "struct.h"

int draw_demon_init(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b, int i)
{
    if (c->position_demon_walk[i].y < 490 && c->position_demon_walk[i].y > 380 \ 
    && c->position_demon_walk[i].x == 820 && c->step_demon[i] == 2)
        return (0);
    else if (c->position_demon_walk[i].y < 490 && c->position_demon_walk[i].y > \
    380 && c->position_demon_walk[i].x == 1000 && c->step_demon[i] == 5)
        return (0);
    if (c->position_demon_walk[i].x == 1540 || (c->position_demon_walk[i].x \
    >= b->position_wall[i].x - 90 && c->position_demon_walk[i].x \
    < b->position_wall[i].x - 50 && b->walk_demon[i] != 2 && c->position_demon_walk[i].y \
    <= b->position_wall[i].y + 120 && c->position_demon_walk[i].y \
    >= b->position_wall[i].y - 100))
        attack_pos_demon(a, b, c, i);
    if (b->walk_demon[i] == 2)
        sfRenderWindow_drawSprite(window, a->sprite_demon_attack[i], NULL);
    else
        sfRenderWindow_drawSprite(window, c->sprite_demon_walk[i], NULL);
    return (0);
}

void attack_pos_demon(struct attack *a, struct buildings *b, \
struct characters *c, int i)
{
    a->position_demon_attack[i].x = c->position_demon_walk[i].x;
    a->position_demon_attack[i].y = c->position_demon_walk[i].y;
    b->walk_demon[i] = 2;
}

void walk_on_map_demon(struct characters *c, struct buildings *b, int i)
{
    c->rect_demon_walk[i].left += 83;
    if (c->rect_demon_walk[i].left >= 498 && b->walk_demon[i] != 2)
        c->rect_demon_walk[i].left = 0;
    if (c->position_demon_walk[i].x < 480 && c->step_demon[i] == 0 && \
    b->walk_demon[i] != 2)
        c->position_demon_walk[i].x += 10;
    if (c->position_demon_walk[i].x == 480) {
        c->position_demon_walk[i].y -= 10;
        c->step_demon[i] = 1;
    }
    if (c->position_demon_walk[i].y == 280 && c->step_demon[i] == 1 && \
    b->walk_demon[i] != 2)
        c->position_demon_walk[i].x += 10;
    if (c->position_demon_walk[i].x == 820 && c->step_demon[i] != 3) {
        c->position_demon_walk[i].y += 10;
        c->step_demon[i] = 2;
    }
    if (c->position_demon_walk[i].y == 580 && (c->step_demon[i] == 2 \
    || c->step_demon[i] == 4) && b->walk_demon[i] != 2)
        c->position_demon_walk[i].x -= 10;
    if (c->position_demon_walk[i].x == 660 && c->position_demon_walk[i].y > 430) {
        c->position_demon_walk[i].y -= 10;
        c->step_demon[i] = 3;
    }
}

void walk_on_map2_demon(struct characters *c, struct buildings *b, int i)
{
    if (c->position_demon_walk[i].y == 430 && c->step_demon[i] == 3 && \
    b->walk_demon[i] != 2)
        c->position_demon_walk[i].x += 10;
    if (c->position_demon_walk[i].x == 1170 && c->step_demon[i] != 5) {
        c->position_demon_walk[i].y += 10;
        c->step_demon[i] = 4;
    }
    if (c->position_demon_walk[i].x == 1000 && (c->step_demon[i] == 4 || \
    c->step_demon[i] == 5) && b->walk_demon[i] != 2) {
        c->position_demon_walk[i].y -= 10;
        c->step_demon[i] = 5;
    }
    if (c->position_demon_walk[i].y == 280 && c->step_demon[i] != 1 && \
    b->walk_demon[i] != 2 && c->position_demon_walk[i].x > 990)
        c->position_demon_walk[i].x += 10;
    if (c->position_demon_walk[i].x == 1350) {
        c->position_demon_walk[i].y += 10;
        c->step_demon[i] = 6;
    }
    if (c->position_demon_walk[i].y == 470 && c->step_demon[i] == 6 && \
    c->position_demon_walk[i].x < 1540 && b->walk_demon[i] != 2)
        c->position_demon_walk[i].x += 10;
}

void demon_attack(struct characters *c, struct attack *a, struct buildings *b, int i)
{
    if (c->position_demon_walk[i].x == 1540) {
        a->rect_demon_attack[i].left += 87;
        if (a->rect_demon_attack[i].left >= 348) {
            a->rect_demon_attack[i].left = 0;
            b->life_base -= 150;
        }
    }
    else if (b->walk_demon[i] == 2) {
        a->rect_demon_attack[i].left += 87;
        if (a->rect_demon_attack[i].left >= 348)
            a->rect_demon_attack[i].left = 0;
    }
}
