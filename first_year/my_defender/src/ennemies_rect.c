/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** ennemies_rect
*/

#include "struct.h"

void dragon_walk_rect(struct characters *c)
{
    for (int i = 0; i < 10; i++) {
        c->rect_dragon_walk[i].top = 0;
        c->rect_dragon_walk[i].height = 75;
        c->rect_dragon_walk[i].left = 0;
        c->rect_dragon_walk[i].width = 153;
        c->position_dragon_walk[i].x = -200;
        c->position_dragon_walk[i].y = 470;
    }
}

void dragon_attack_rect(struct attack *a, struct characters *c)
{
    for (int i = 0; i < 10; i++) {
        a->rect_dragon_attack[i].top = 0;
        a->rect_dragon_attack[i].height = 129;
        a->rect_dragon_attack[i].left = 260;
        a->rect_dragon_attack[i].width = 130;
    }
}

void fire_rect(struct attack *a)
{
    for (int i = 0; i < 10; i++) {
        a->rect_fire[i].top = 0;
        a->rect_fire[i].height = 59;
        a->rect_fire[i].left = 164;
        a->rect_fire[i].width = 82;
    }
}

void demon_walk_rect(struct characters *c)
{
    for (int i = 0; i < 10; i++) {
        c->rect_demon_walk[i].top = 0;
        c->rect_demon_walk[i].height = 92;
        c->rect_demon_walk[i].left = 0;
        c->rect_demon_walk[i].width = 83;
        c->position_demon_walk[i].x = -150;
        c->position_demon_walk[i].y = 480;
    }
}

void demon_attack_rect(struct attack *a)
{
    for (int i = 0; i < 10; i++) {
        a->rect_demon_attack[i].top = 0;
        a->rect_demon_attack[i].height = 89;
        a->rect_demon_attack[i].left = 0;
        a->rect_demon_attack[i].width = 87;
    }
}

void lizard_walk_rect(struct characters *c)
{
    for (int i = 0; i < c->lizard; i++) {
        c->rect_lizard_walk[i].top = 0;
        c->rect_lizard_walk[i].height = 54;
        c->rect_lizard_walk[i].left = 0;
        c->rect_lizard_walk[i].width = 92;
        c->position_lizard_walk[i].x = -200;
        c->position_lizard_walk[i].y = 480;
    }
}

void lizard_attack_rect(struct attack *a)
{
    for (int i = 0; i < 10; i++) {
        a->rect_lizard_attack[i].top = 0;
        a->rect_lizard_attack[i].height = 59;
        a->rect_lizard_attack[i].left = 0;
        a->rect_lizard_attack[i].width = 97;
    }
}
