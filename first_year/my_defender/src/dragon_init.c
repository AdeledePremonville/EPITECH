/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** dragon_init
*/

#include "struct.h"

int draw_dragon_init(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b, int i)
{
    if (c->position_dragon_walk[i].y < 510 && c->position_dragon_walk[i].y > 410 \
    && c->position_dragon_walk[i].x == 770 && c->step_dragon[i] == 2)
        return (0);
    else if (c->position_dragon_walk[i].y < 510 && c->position_dragon_walk[i].y > \
    410 && c->position_dragon_walk[i].x == 950 && c->step_dragon[i] == 5)
        return (0);
    if (c->position_dragon_walk[i].x == 1480 || (c->position_dragon_walk[i].x \
    >= b->position_wall[i].x - 203 && c->position_dragon_walk[i].x \
    < b->position_wall[i].x - 50 && b->walk_dragon[i] != 2 && \
    c->position_dragon_walk[i].y <= b->position_wall[i].y + 120 && \
    c->position_dragon_walk[i].y >= b->position_wall[i].y - 100))
        attack_pos_dragon(a, b, c, i);
    if (b->walk_dragon[i] == 2) {
        sfRenderWindow_drawSprite(window, a->sprite_dragon_attack[i], NULL);
        sfRenderWindow_drawSprite(window, a->sprite_fire[i], NULL);
    }
    else
        sfRenderWindow_drawSprite(window, c->sprite_dragon_walk[i], NULL);
    return (0);
}

void attack_pos_dragon(struct attack *a, struct buildings *b, \
struct characters *c, int i)
{
    a->position_dragon_attack[i].x = c->position_dragon_walk[i].x;
    a->position_dragon_attack[i].y = c->position_dragon_walk[i].y;
    a->position_fire[i].x = a->position_dragon_attack[i].x + 135;
    a->position_fire[i].y = a->position_dragon_attack[i].y + 52;
//    a->dragon_attack++;
    b->walk_dragon[i] = 2;
}

void walk_on_map_dragon(struct characters *c, struct buildings *b, int i)
{
    c->rect_dragon_walk[i].left += 153;
    if (c->rect_dragon_walk[i].left >= 765 && b->walk_dragon[i] != 2)
        c->rect_dragon_walk[i].left = 0;
    if (c->position_dragon_walk[i].x < 430 && c->step_dragon[i] == 0 && \
    b->walk_dragon[i] != 2)
        c->position_dragon_walk[i].x += 10;
    if (c->position_dragon_walk[i].x == 430) {
        c->position_dragon_walk[i].y -= 10;
        c->step_dragon[i] = 1;
    }
    if (c->position_dragon_walk[i].y == 290 && c->step_dragon[i] == 1 && \
    b->walk_dragon[i] != 2)
        c->position_dragon_walk[i].x += 10;
    if (c->position_dragon_walk[i].x == 770 && c->step_dragon[i] != 3) {
        c->position_dragon_walk[i].y += 10;
        c->step_dragon[i] = 2;
    }
    if (c->position_dragon_walk[i].y == 590 && (c->step_dragon[i] == 2 \
    || c->step_dragon[i] == 4) && b->walk_dragon[i] != 2)
        c->position_dragon_walk[i].x -= 10;
    if (c->position_dragon_walk[i].x == 620 && c->position_dragon_walk[i].y > 450) {
        c->position_dragon_walk[i].y -= 10;
        c->step_dragon[i] = 3;
    }
}

void walk_on_map2_dragon(struct characters *c, struct buildings *b, int i)
{
    if (c->position_dragon_walk[i].y == 450 && c->step_dragon[i] == 3 && \
    b->walk_dragon[i] != 2)
        c->position_dragon_walk[i].x += 10;
    if (c->position_dragon_walk[i].x == 1120 && c->step_dragon[i] != 5) {
        c->position_dragon_walk[i].y += 10;
        c->step_dragon[i] = 4;
    }
    if (c->position_dragon_walk[i].x == 950 && (c->step_dragon[i] == 4 || \
    c->step_dragon[i] == 5) && b->walk_dragon[i] != 2) {
        c->position_dragon_walk[i].y -= 10;
        c->step_dragon[i] = 5;
    }
    if (c->position_dragon_walk[i].y == 290 && c->step_dragon[i] != 1 && \
    b->walk_dragon[i] != 2)
        c->position_dragon_walk[i].x += 10;
    if (c->position_dragon_walk[i].x == 1290) {
        c->position_dragon_walk[i].y += 10;
        c->step_dragon[i] = 6;
    }
    if (c->position_dragon_walk[i].y == 470 && c->step_dragon[i] == 6 && \
    c->position_dragon_walk[i].x < 1480 && b->walk_dragon[i] != 2)
        c->position_dragon_walk[i].x += 10;
}

void dragon_attack(struct characters *c, struct attack *a, struct buildings *b, int i)
{
    if (c->position_dragon_walk[i].x == 1480) {
        a->rect_dragon_attack[i].left += 130;
        a->rect_fire[i].left += 82;
        if (a->rect_dragon_attack[i].left >= 520) {
            a->rect_dragon_attack[i].left = 0;
            b->life_base -= 50;
        }
        if (a->rect_fire[i].left >= 492)
            a->rect_fire[i].left = 164;
    }
    else if (b->walk_dragon[i] == 2) {
        a->rect_dragon_attack[i].left += 130;
        a->rect_fire[i].left += 82;
        if (a->rect_dragon_attack[i].left >= 520)
            a->rect_dragon_attack[i].left = 0;
        if (a->rect_fire[i].left >= 492)
            a->rect_fire[i].left = 164;
    }
}
