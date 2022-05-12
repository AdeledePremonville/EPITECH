/*
** EPITECH PROJECT, 2022
** attack_event.c
** File description:
** fight event - rpg
*/

#include "p.h"

void manage_anim_spell2(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfTime time = sfClock_getElapsedTime(chara->attacks->spell2->clock);
    int seconds = sfTime_asMilliseconds(chara->attacks->spell2->time);

    chara->attacks->spell2->time = time;
    chara->attacks->spell2->seconds = seconds;
    if (chara->attacks->spell2->seconds > 200
    && chara->attacks->spell2->state) {
        move_spell2(&chara->attacks->spell2->rect, &fight->turn,
        384, &chara->attacks->spell2->state);
        sfSprite_setTextureRect(chara->attacks->spell2->sprite,
        chara->attacks->spell2->rect);
        sfClock_restart(chara->attacks->spell2->clock);
    }
}

int event_attack(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, chara->attacks->basic_spell->text_size,
    chara->attacks->basic_spell->text_pos) && fight->state == 2
    && fight->spam && !chara->attacks->basic_spell->spell) {
        chara->attacks->basic_spell->spell = true;
        chara->attacks->basic_spell->state = true;
        enemy->health->dmg += chara->attacks->basic_spell->damage;
        fight->spam = false;
    }
    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, chara->attacks->spell2->text_size,
    chara->attacks->spell2->text_pos) && fight->state == 2
    && fight->spam && !chara->attacks->spell2->spell) {
        chara->attacks->spell2->spell = true;
        chara->attacks->spell2->state = true;
        enemy->health->dmg += chara->attacks->spell2->damage;
        fight->spam = false;
    }
    return 0;
}
