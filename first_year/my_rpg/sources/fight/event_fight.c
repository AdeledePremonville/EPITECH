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

int items_event_fight_potion(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, chara->items->potion_200hp->size,
    chara->items->potion_200hp->pos) == 1 && fight->state == 3 &&
    chara->items->potion_200hp->potion > 0 && chara->health->dmg != 0) {
        chara->items->potion_200hp->potion--;
        sfText_setString(chara->items->potion_200hp->nb,
        int_to_str(chara->items->potion_200hp->potion));
        if (chara->health->dmg >= chara->items->potion_200hp->dgt)
            chara->health->dmg -= chara->items->potion_200hp->dgt;
        else
            chara->health->dmg -= chara->health->dmg;
        fight->turn = false;
    }
    if (event.type == sfEvtMouseButtonPressed)
        sfSound_play(fight->sound);
    event_attack(event, fight, chara, enemy);
    return 0;
}

int items_event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, chara->items->potion_100hp->size,
    chara->items->potion_100hp->pos) == 1 && fight->state == 3 &&
    chara->items->potion_100hp->potion > 0 && chara->health->dmg != 0) {
        fight->turn = false;
        chara->items->potion_100hp->potion--;
        sfText_setString(chara->items->potion_100hp->nb,
        int_to_str(chara->items->potion_100hp->potion));
        if (chara->health->dmg >= chara->items->potion_100hp->dgt)
            chara->health->dmg -= chara->items->potion_100hp->dgt;
        else
            chara->health->dmg -= chara->health->dmg;
    }
    items_event_fight_potion(event, fight, chara, enemy);
    return 0;
}

int help_help_event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, chara->attacks->kick->text_size,
    chara->attacks->kick->text_pos) && fight->state == 1 && fight->spam) {
        chara->attacks->kick->state = true;
        enemy->health->dmg += get_crit(chara->attacks->kick->damage, enemy);
        fight->spam = false;
    }
    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, fight->buttons_fight->escape_size,
    fight->buttons_fight->escape_pos) == 1 && fight->state == 0)
        return ESCAPE;
    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, fight->buttons_fight->item_size,
    fight->buttons_fight->item_pos) == 1 && fight->state == 0)
        fight->state = 3;
    items_event_fight(event, fight, chara, enemy);
    return 0;
}

int help_event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, fight->buttons_fight->back_size,
    fight->buttons_fight->back_pos) == 1)
        fight->state = 0;
    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, fight->buttons_fight->spell_size,
    fight->buttons_fight->spell_pos) == 1 && fight->state == 0)
        fight->state = 2;
    if (event.type == sfEvtMouseButtonReleased
    && pos_is_inrect(mouse, fight->buttons_fight->attack_size,
    fight->buttons_fight->attack_pos) == 1 && fight->state == 0)
        fight->state = 1;
    if (help_help_event_fight(event, fight, chara, enemy) != 0)
        return help_help_event_fight(event, fight, chara, enemy);
    return 0;
}

int event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);
    int dmg = chara->attacks->basic_physic->damage;

    if (is_end(event, fight, chara, enemy) != -1)
        return is_end(event, fight, chara, enemy);
    if (event.type == sfEvtMouseButtonReleased && fight->spam
    && pos_is_inrect(mouse, chara->attacks->basic_physic->text_size,
    chara->attacks->basic_physic->text_pos) && fight->state == 1) {
        chara->attacks->basic_physic->state = true;
        enemy->health->dmg += (dmg - rand_max(5));
        fight->spam = false;
    }
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
        sfRenderWindow_close(fight->window);
    if (help_event_fight(event, fight, chara, enemy) != 0)
        return help_event_fight(event, fight, chara, enemy);
    return 0;
}
