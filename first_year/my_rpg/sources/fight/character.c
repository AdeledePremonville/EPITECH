/*
** EPITECH PROJECT, 2022
** character.c
** File description:
** character fight - my_rpg
*/

#include "p.h"
#include "my.h"
#include <stdlib.h>

struct character *create_character_fight(struct param_fight *p)
{
    struct character *res = malloc(sizeof(struct character) * 1);

    if (res == NULL)
        return NULL;
    res->sprite_character = sfSprite_create();
    res->text_character = sfTexture_createFromFile("sprite/fight/chara.png",
    NULL);
    res->rect = (sfIntRect){0, 0, 64, 64};
    sfSprite_setTextureRect(res->sprite_character, res->rect);
    sfSprite_setTexture(res->sprite_character, res->text_character, sfFalse);
    sfSprite_setScale(res->sprite_character, (sfVector2f){-5, 5});
    sfSprite_setPosition(res->sprite_character, (sfVector2f){500, 350});
    res->clock = sfClock_create();
    res->time = sfClock_getElapsedTime(res->clock);
    res->seconds = sfTime_asSeconds(res->time);
    res->health = create_health((double)p->max_hp, (sfVector2f){200, 200},
    (sfVector2f){300, 40});
    res->items = create_items(p);
    res->attacks = create_attacks_fight(p->chara_attack);
    return res;
}

void set_fight_struct(struct fight *fight)
{
    fight->turn = true;
    fight->spam = true;
    fight->sound = sfSound_create();
    fight->buffer = sfSoundBuffer_createFromFile("sprite/menu/s_button.ogg");
    sfSound_setBuffer(fight->sound, fight->buffer);
}
