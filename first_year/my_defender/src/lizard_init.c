/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** lizard_init
*/

#include "struct.h"

int draw_lizard_init(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b, int i)
{
    if (c->position_lizard_walk[i].y < 490 && c->position_lizard_walk[i].y > 380 \ 
    && c->position_lizard_walk[i].x == 820 && c->step_lizard[i] == 2)
        return (0);
    else if (c->position_lizard_walk[i].y < 490 && c->position_lizard_walk[i].y > \
    380 && c->position_lizard_walk[i].x == 1000 && c->step_lizard[i] == 5)
        return (0);
    if (c->position_lizard_walk[i].x == 1540 || (c->position_lizard_walk[i].x \
    >= b->position_wall[i].x - 100 && c->position_lizard_walk[i].x \
    < b->position_wall[i].x - 50 && b->walk_lizard[i] != 2 && c->position_lizard_walk[i].y \
    <= b->position_wall[i].y + 120 && c->position_lizard_walk[i].y \
    >= b->position_wall[i].y - 100))
        attack_pos_lizard(a, b, c, i);
    if (b->walk_lizard[i] == 2)
        sfRenderWindow_drawSprite(window, a->sprite_lizard_attack[i], NULL);
    else
        sfRenderWindow_drawSprite(window, c->sprite_lizard_walk[i], NULL);
    return (0);
}

void attack_pos_lizard(struct attack *a, struct buildings *b, \
struct characters *c, int i)
{
    a->position_lizard_attack[i].x = c->position_lizard_walk[i].x;
    a->position_lizard_attack[i].y = c->position_lizard_walk[i].y;
    b->walk_lizard[i] = 2;
}

void walk_on_map_lizard(struct characters *c, struct buildings *b, int i)
{
    c->rect_lizard_walk[i].left += 83;
    if (c->rect_lizard_walk[i].left >= 498 && b->walk_lizard[i] != 2)
        c->rect_lizard_walk[i].left = 0;
    if (c->position_lizard_walk[i].x < 480 && c->step_lizard[i] == 0 && \
    b->walk_lizard[i] != 2)
        c->position_lizard_walk[i].x += 10;
    if (c->position_lizard_walk[i].x == 480) {
        c->position_lizard_walk[i].y -= 10;
        c->step_lizard[i] = 1;
    }
    if (c->position_lizard_walk[i].y == 280 && c->step_lizard[i] == 1 && \
    b->walk_lizard[i] != 2)
        c->position_lizard_walk[i].x += 10;
    if (c->position_lizard_walk[i].x == 820 && c->step_lizard[i] != 3) {
        c->position_lizard_walk[i].y += 10;
        c->step_lizard[i] = 2;
    }
    if (c->position_lizard_walk[i].y == 580 && (c->step_lizard[i] == 2 \
    || c->step_lizard[i] == 4) && b->walk_lizard[i] != 2)
        c->position_lizard_walk[i].x -= 10;
    if (c->position_lizard_walk[i].x == 660 && c->position_lizard_walk[i].y > 430) {
        c->position_lizard_walk[i].y -= 10;
        c->step_lizard[i] = 3;
    }
}

void walk_on_map2_lizard(struct characters *c, struct buildings *b, int i)
{
    if (c->position_lizard_walk[i].y == 430 && c->step_lizard[i] == 3 && \
    b->walk_lizard[i] != 2)
        c->position_lizard_walk[i].x += 10;
    if (c->position_lizard_walk[i].x == 1170 && c->step_lizard[i] != 5) {
        c->position_lizard_walk[i].y += 10;
        c->step_lizard[i] = 4;
    }
    if (c->position_lizard_walk[i].x == 1000 && (c->step_lizard[i] == 4 || \
    c->step_lizard[i] == 5) && b->walk_lizard[i] != 2) {
        c->position_lizard_walk[i].y -= 10;
        c->step_lizard[i] = 5;
    }
    if (c->position_lizard_walk[i].y == 280 && c->step_lizard[i] != 1 && \
    b->walk_lizard[i] != 2 && c->position_lizard_walk[i].x > 990)
        c->position_lizard_walk[i].x += 10;
    if (c->position_lizard_walk[i].x == 1350) {
        c->position_lizard_walk[i].y += 10;
        c->step_lizard[i] = 6;
    }
    if (c->position_lizard_walk[i].y == 470 && c->step_lizard[i] == 6 && \
    c->position_lizard_walk[i].x < 1540 && b->walk_lizard[i] != 2)
        c->position_lizard_walk[i].x += 10;
}

void lizard_attack(struct characters *c, struct attack *a, struct buildings *b, int i)
{
    if (c->position_lizard_walk[i].x == 1530 || b->walk_lizard[i] == 2) {
        a->rect_lizard_attack[i].left += 97;
        if (a->rect_lizard_attack[i].left >= 485) {
            a->rect_lizard_attack[i].left = 0;
            b->life_base -= 10;
        }
    }
    else if (b->walk_lizard[i] == 2) {
        a->rect_lizard_attack[i].left += 97;
        if (a->rect_lizard_attack[i].left >= 485)
            a->rect_lizard_attack[i].left = 0;
    }
}