/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** building_shoot
*/

#include "struct.h"

void tesla_damage(struct buildings *b, struct characters *c, int i)
{
    for (int a = 0; a < 2; a++) {
        if (b->position_tesla[a].y < 800 && c->position_dragon_walk[i].x > \
        b->position_tesla[a].x - 110 && c->position_dragon_walk[i].x < \
        b->position_tesla[a].x + 190)
            c->life_dragon[i] -= 10;
        if (b->position_tesla[a].y < 800 && c->position_demon_walk[i].x > \
        b->position_tesla[a].x - 110 && c->position_demon_walk[i].x < \
        b->position_tesla[a].x + 190)
            c->life_demon[i] -= 10;
        if (b->position_tesla[a].y < 800 && c->position_lizard_walk[i].x > \
        b->position_tesla[a].x - 110 && c->position_lizard_walk[i].x < \
        b->position_tesla[a].x + 190)
            c->life_lizard[i] -= 10;
    }
}

void sniper_damage(struct buildings *b, struct characters *c, int i)
{
    for (int a = 0; a < 2; a++) {
        if (b->position_sniper[a].y < 800 && c->position_dragon_walk[i].x > 0)
            c->life_dragon[i] -= 15;
        if (b->position_sniper[a].y < 800 && c->position_demon_walk[i].x > 0)
            c->life_demon[i] -= 15;
        if (b->position_sniper[a].y < 800 && c->position_lizard_walk[i].x > 0)
            c->life_lizard[i] -= 15;
    }
}

void roblox_damage(struct buildings *b, struct characters *c, int i)
{
    for (int a = 0; a < 2; a++) {
        if (b->position_roblox[a].y < 800 && c->position_dragon_walk[i].x > \
        b->position_roblox[a].x - 140 && c->position_dragon_walk[i].x < \
        b->position_roblox[a].x + 260)
            c->life_dragon[i] -= 30;
        if (b->position_roblox[a].y < 800 && c->position_demon_walk[i].x > \
        b->position_roblox[a].x - 140 && c->position_demon_walk[i].x < \
        b->position_roblox[a].x + 260)
            c->life_demon[i] -= 30;
        if (b->position_roblox[a].y < 800 && c->position_lizard_walk[i].x > \
        b->position_roblox[a].x - 140 && c->position_lizard_walk[i].x < \
        b->position_roblox[a].x + 260)
            c->life_lizard[i] -= 30;
    }
}

int tesla_shoot(struct characters *c, struct buildings *b)
{
    sfTime time_tesla = sfClock_getElapsedTime(b->clock_tesla);
    float seconds_tesla = sfTime_asSeconds(time_tesla);

    if (seconds_tesla > 0.5) {
        for (int i = 0; i < 10; i++) {
            tesla_damage(b, c, i);
            sfClock_restart(b->clock_tesla);
        }
    }
    return (0);
}

int sniper_shoot(struct characters *c, struct buildings *b)
{
    sfTime time = sfClock_getElapsedTime(b->clock_sniper);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 1.25) {
        for (int i = 0; i < 10; i++) {
            sniper_damage(b, c, i);
            sfClock_restart(b->clock_sniper);
        }
    }
    return (0);
}

int roblox_shoot(struct characters *c, struct buildings *b)
{
    sfTime time = sfClock_getElapsedTime(b->clock_roblox);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.75) {
        for (int i = 0; i < 10; i++) {
            roblox_damage(b, c, i);
            sfClock_restart(b->clock_roblox);
        }
    }
    return (0);
}