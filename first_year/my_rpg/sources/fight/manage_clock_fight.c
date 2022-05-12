/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** fight
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>

int is_end(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    if (chara->health->dmg >= chara->health->life)
        return LOSE;
    if (enemy->health->dmg >= enemy->health->life)
        return WIN;
    return -1;
}

void help_clock_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfTime time = sfClock_getElapsedTime(chara->attacks->basic_spell->clock);
    int seconds = sfTime_asMilliseconds(chara->attacks->basic_spell->time);

    chara->attacks->basic_spell->time = time;
    chara->attacks->basic_spell->seconds = seconds;
    if (chara->attacks->basic_spell->seconds > 200
    && chara->attacks->basic_spell->state) {
        move_basic_spell(&chara->attacks->basic_spell->rect, &fight->turn,
        783, &chara->attacks->basic_spell->state);
        sfSprite_setTextureRect(chara->attacks->basic_spell->sprite,
        chara->attacks->basic_spell->rect);
        sfClock_restart(chara->attacks->basic_spell->clock);
    }
    manage_anim_spell2(event, fight, chara, enemy);
}

void manage_enemy_attack(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->attacks->basic_physic->clock);
    int seconds = sfTime_asMilliseconds(enemy->attacks->basic_physic->time);

    enemy->attacks->basic_physic->time = time;
    enemy->attacks->basic_physic->seconds = seconds;
    if (enemy->attacks->basic_physic->seconds > 200 && !fight->turn) {
        move_enemy_attack(&enemy->attacks->basic_physic->state,
        &enemy->attacks->basic_physic->rect, fight, chara);
        sfSprite_setTextureRect(enemy->attacks->basic_physic->sprite,
        enemy->attacks->basic_physic->rect);
        sfClock_restart(enemy->attacks->basic_physic->clock);
    }
    help_clock_fight(fight, event, chara, enemy);
}

void help_manage_clock_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    if (chara->seconds > 200) {
        move_rect_fight(&chara->rect, 128, 64);
        sfSprite_setTextureRect(chara->sprite_character, chara->rect);
        sfClock_restart(chara->clock);
    }
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = sfTime_asMilliseconds(enemy->time);
    if (enemy->seconds > 200) {
        move_enemy(&enemy->rect, enemy->type + 96, 48, &enemy->dir);
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
        sfClock_restart(enemy->clock);
    }
    if (chara->attacks->kick->seconds > 200 && chara->attacks->kick->state) {
        move_attack(&chara->attacks->kick->state,
        &chara->attacks->kick->rect, &fight->turn, 768);
        sfSprite_setTextureRect(chara->attacks->kick->sprite,
        chara->attacks->kick->rect);
        sfClock_restart(chara->attacks->kick->clock);
    }
    manage_enemy_attack(fight, event, chara, enemy);
}

void manage_clock_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfTime time = sfClock_getElapsedTime(chara->attacks->basic_physic->clock);
    int seconds = sfTime_asMilliseconds(chara->attacks->basic_physic->time);
    sfTime time_kick = sfClock_getElapsedTime(chara->attacks->kick->clock);
    int seconds_kick = sfTime_asMilliseconds(chara->attacks->kick->time);

    chara->attacks->basic_physic->time = time;
    chara->attacks->basic_physic->seconds = seconds;
    if (chara->attacks->basic_physic->seconds > 200 &&
    chara->attacks->basic_physic->state) {
        move_attack(&chara->attacks->basic_physic->state,
        &chara->attacks->basic_physic->rect, &fight->turn, 960);
        sfSprite_setTextureRect(chara->attacks->basic_physic->sprite,
        chara->attacks->basic_physic->rect);
        sfClock_restart(chara->attacks->basic_physic->clock);
    }
    chara->time = sfClock_getElapsedTime(chara->clock);
    chara->seconds = sfTime_asMilliseconds(chara->time);
    chara->attacks->kick->time = time_kick;
    chara->attacks->kick->seconds = seconds_kick;
    help_manage_clock_fight(fight, event, chara, enemy);
}
