/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** spawn
*/

#include "struct.h"
#include "score.h"
#include <stdlib.h>

void ennemies_spawn(struct attack *a, struct buildings *b, struct characters *c)
{
    sfTime time_spawn = sfClock_getElapsedTime(c->clock_spawn);
    float seconds_spawn = sfTime_asSeconds(time_spawn);

    if (seconds_spawn > 3) {
        int number = rand()%2;
        if (number == 0 && c->dragon < 10)
            c->dragon++;
        if (number == 1 && c->demon < 10)
            c->demon++;
        if (number == 2 && c->lizard < 10)
            c->lizard++;
        sfClock_restart(c->clock_spawn);
    }
}

int dragon_spawn(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b)
{
    sfTime time_walk = sfClock_getElapsedTime(c->clock_dragon_walk);
    float seconds_walk = sfTime_asSeconds(time_walk);
    sfTime time_attack = sfClock_getElapsedTime(a->clock_dragon_attack);
    float seconds_attack = sfTime_asSeconds(time_attack);
    sprite_characters_walk_init(c);
    sprite_characters_attack_init(a);
    set_init(c);
    set_attack_init(a);

    if (seconds_walk > 0.1) {
        for (int i = 0; i < c->dragon; i++) {
            walk_on_map_dragon(c, b, i);
            walk_on_map2_dragon(c, b, i);
            sfClock_restart(c->clock_dragon_walk);
        }
    }
    if (seconds_attack > 0.2) {
        for (int i = 0; i < c->dragon; i++) {
            dragon_attack(c, a, b, i);
            sfClock_restart(a->clock_dragon_attack);
        }
    }
    return (0);
}

int demon_spawn(struct characters *c, struct attack *a, struct buildings *b)
{
    sfTime time_walk = sfClock_getElapsedTime(c->clock_demon_walk);
    float seconds_walk = sfTime_asSeconds(time_walk);
    sfTime time_attack = sfClock_getElapsedTime(a->clock_demon_attack);
    float seconds_attack = sfTime_asSeconds(time_attack);
    sprite_characters_walk_init(c);
    sprite_characters_attack_init(a);
    set_init(c);
    set_attack_init(a);

    if (seconds_walk > 0.2) {
        for (int i = 0; i < c->demon; i++) {
            walk_on_map_demon(c, b, i);
            walk_on_map2_demon(c, b, i);
            sfClock_restart(c->clock_demon_walk);
        }
    }
    if (seconds_attack > 1) {
        for (int i = 0; i < c->demon; i++) {
            demon_attack(c, a, b, i);
            sfClock_restart(a->clock_demon_attack);
        }
    }
    return (0);
}

int lizard_spawn(struct characters *c, struct attack *a, struct buildings *b)
{
    sfTime time_walk = sfClock_getElapsedTime(c->clock_lizard_walk);
    float seconds_walk = sfTime_asSeconds(time_walk);
    sfTime time_attack = sfClock_getElapsedTime(a->clock_lizard_attack);
    float seconds_attack = sfTime_asSeconds(time_attack);
    sprite_characters_walk_init(c);
    sprite_characters_attack_init(a);
    set_init(c);
    set_attack_init(a);

    if (seconds_walk > 0.1) {
        for (int i = 0; i < c->lizard; i++) {
            walk_on_map_lizard(c, b, i);
            walk_on_map2_lizard(c, b, i);
            if (c->position_lizard_walk[i].x < 470)
                c->position_lizard_walk[i].x += 10;
            sfClock_restart(c->clock_lizard_walk);
        }
    }
    if (seconds_attack > 0.15) {
        for (int i = 0; i < c->lizard; i++) {
            lizard_attack(c, a, b, i);
            sfClock_restart(a->clock_lizard_attack);
        }
    }
    return (0);
}

void end_game(struct buildings *b, struct defender *def, sfRenderWindow *w)
{
    sfTime time_end = sfClock_getElapsedTime(b->clock_end);
    float seconds_end = sfTime_asSeconds(time_end);
    sfTime time_timer = sfClock_getElapsedTime(b->clock_timer);
    float seconds_timer = sfTime_asSeconds(time_timer);
    sfTime time_timer2 = sfClock_getElapsedTime(b->clock_timer2);
    float seconds_timer2 = sfTime_asSeconds(time_timer2);

    if (seconds_timer2 > 10 && def->rect_counter[3].left == 558) {
        def->rect_counter[4].left -= 62;
        sfClock_restart(b->clock_timer2);
    }
    if (seconds_timer > 1) {
        if (def->rect_counter[3].left <= 0)
            def->rect_counter[3].left = 620;
        def->rect_counter[3].left -= 62;
        sfClock_restart(b->clock_timer);
    }
    if (seconds_end > 5) {
        b->end = 1;
        check_score(b->life_base + b->money);
        end_menu(w , 0, b->life_base + b->money);
    }
    if (b->life_base <= 0) {
        end_menu(w, 1, b->money);
    }
}
