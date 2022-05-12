/*
** EPITECH PROJECT, 2022
** attack.c
** File description:
** attack - myrpg
*/

#include "p.h"

void move_attack(bool *state, sfIntRect *rect, bool *turn, int max)
{
    if (rect->left >= max) {
        *state = false;
        rect->left = 0;
        *turn = false;
    } else
        rect->left += 192;
}

void move_enemy_attack(bool *state, sfIntRect *rect, struct fight *fight,
struct character *chara)
{
    double dmg = chara->attacks->basic_physic->damage - rand_max(5);

    if (rect->left >= 960) {
        state = false;
        fight->spam = true;
        rect->left = 0;
        fight->turn = true;
        if (chara->health->life - chara->health->dmg < dmg)
            chara->health->dmg += chara->health->life - chara->health->dmg;
        else
            chara->health->dmg += dmg;
    } else
        rect->left += 192;
}

int get_crit(int dmg, struct enemy *enemy)
{
    int rand_nb = rand_max(4);

    if (rand_nb == 3) {
        if (dmg * 1.5 > (enemy->health->life - enemy->health->dmg))
            return (enemy->health->life - enemy->health->dmg);
        return dmg * 1.5;
    }
    if (dmg > (enemy->health->life - enemy->health->dmg))
        return (enemy->health->life - enemy->health->dmg);
    return dmg;
}

void move_basic_spell(sfIntRect *rect, bool *turn, int max_left, bool *state)
{
    if (rect->left >= max_left
    && rect->top >= 576) {
        *state = false;
        rect->left = 0;
        rect->top = 0;
        *turn = false;
    } else if (rect->left >= max_left) {
        rect->left = 0;
        rect->top += 192;
    } else
        rect->left += 192;
}

void move_spell2(sfIntRect *rect, bool *turn, int max_left, bool *state)
{
    if (rect->left >= max_left
    && rect->top >= 768) {
        *state = false;
        rect->left = 0;
        rect->top = 0;
        *turn = false;
    } else if (rect->left >= max_left) {
        rect->left = 0;
        rect->top += 192;
    } else
        rect->left += 192;
}
