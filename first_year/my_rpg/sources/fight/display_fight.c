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

void display_enemy_attack(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    if (fight->turn == false && is_end(event, fight, chara, enemy) == -1)
        sfRenderWindow_drawSprite(fight->window,
        enemy->attacks->basic_physic->sprite, NULL);
    if (chara->attacks->kick->state == true)
        sfRenderWindow_drawSprite(fight->window, chara->attacks->kick->sprite,
        NULL);
    if (chara->attacks->basic_spell->state)
        sfRenderWindow_drawSprite(fight->window,
        chara->attacks->basic_spell->sprite, NULL);
    if (chara->attacks->spell2->state)
        sfRenderWindow_drawSprite(fight->window,
        chara->attacks->spell2->sprite, NULL);
}

void help_display_fight_state(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (fight->state == 3) {
        draw_button(chara->items->potion_100hp->button, fight->window, mouse);
        draw_button(chara->items->potion_200hp->button, fight->window, mouse);
        sfRenderWindow_drawText(fight->window, chara->items->potion_100hp->nb,
        NULL);
        draw_button(fight->buttons_fight->back, fight->window, mouse);
        sfRenderWindow_drawText(fight->window, chara->items->potion_200hp->nb,
        NULL);
    }
    sfText_setString(chara->health->text,
    int_to_str(chara->health->life - chara->health->dmg));
    sfRenderWindow_drawText(fight->window, chara->health->text, NULL);
    sfText_setString(enemy->health->text,
    int_to_str(enemy->health->life - enemy->health->dmg));
    sfRenderWindow_drawText(fight->window, enemy->health->text, NULL);
}

void display_fight_state(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);

    if (fight->state == 0) {
        draw_button(fight->buttons_fight->escape, fight->window, mouse);
        draw_button(fight->buttons_fight->button_attack, fight->window, mouse);
        draw_button(fight->buttons_fight->button_spell, fight->window, mouse);
        draw_button(fight->buttons_fight->button_item, fight->window, mouse);
    }
    if (fight->state == 1) {
        draw_button(chara->attacks->basic_physic->text, fight->window, mouse);
        draw_button(chara->attacks->kick->text, fight->window, mouse);
        draw_button(fight->buttons_fight->back, fight->window, mouse);
    }
    if (fight->state == 2) {
        draw_button(chara->attacks->spell2->text, fight->window, mouse);
        draw_button(chara->attacks->basic_spell->text, fight->window, mouse);
        draw_button(fight->buttons_fight->back, fight->window, mouse);
    }
    help_display_fight_state(fight, event, chara, enemy);
}

void draw_sprite_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfRenderWindow_drawSprite(fight->window, enemy->sprite, NULL);
    sfRectangleShape_setSize(enemy->health->damage,
    calc_damage(enemy->health));
    sfRectangleShape_setPosition(enemy->health->damage,
    calc_pos_damage(enemy->health));
    sfRenderWindow_drawRectangleShape(fight->window,
    enemy->health->health, NULL);
    sfRenderWindow_drawRectangleShape(fight->window,
    enemy->health->damage, NULL);
    sfRectangleShape_setSize(chara->health->damage,
    calc_damage(chara->health));
    sfRectangleShape_setPosition(chara->health->damage,
    calc_pos_damage(chara->health));
    sfRenderWindow_drawRectangleShape(fight->window, chara->health->health,
    NULL);
    sfRenderWindow_drawRectangleShape(fight->window, chara->health->damage,
    NULL);
    sfRenderWindow_drawSprite(fight->window, chara->sprite_character, NULL);
    display_enemy_attack(fight, event, chara, enemy);
}

int display_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(fight->window);
    sfTime time = sfClock_getElapsedTime(chara->attacks->basic_physic->clock);
    int seconds = sfTime_asMilliseconds(chara->attacks->basic_physic->time);

    sfRenderWindow_drawSprite(fight->window, fight->sprite_bg, NULL);
    display_fight_state(fight, event, chara, enemy);
    draw_sprite_fight(fight, event, chara, enemy);
    if (chara->attacks->basic_physic->state == true)
        sfRenderWindow_drawSprite(fight->window,
        chara->attacks->basic_physic->sprite, NULL);
    sfRenderWindow_display(fight->window);
    chara->attacks->basic_physic->time = time;
    chara->attacks->basic_physic->seconds = seconds;
    manage_clock_fight(fight, event, chara, enemy);
    while (sfRenderWindow_pollEvent(fight->window, &event))
        if (event_fight(event, fight, chara, enemy) != 0)
            return event_fight(event, fight, chara, enemy);
    sfRenderWindow_clear(fight->window, sfBlack);
    return 0;
}
