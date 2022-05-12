/*
** EPITECH PROJECT, 2022
** character.c
** File description:
** character fight - my_rpg
*/

#include "p.h"
#include "my.h"
#include <stdlib.h>

struct attack *create_attack(bool has, char *filepath, sfIntRect rect,
int dmg)
{
    struct attack *res = malloc(sizeof(struct attack));

    if (res == NULL)
        return NULL;
    res->spell = false;
    res->has_attack = has;
    res->state = false;
    res->damage = dmg;
    res->sprite = sfSprite_create();
    res->texture = sfTexture_createFromFile(filepath, NULL);
    res->rect = rect;
    sfSprite_setTextureRect(res->sprite, res->rect);
    sfSprite_setTexture(res->sprite, res->texture, sfFalse);
    res->clock = sfClock_create();
    res->time = sfClock_getElapsedTime(res->clock);
    res->seconds = sfTime_asSeconds(res->time);
    return res;
}

void help_create_attack(struct attacks *res)
{
    res->basic_spell->text_pos = (sfVector2f){450, 800};
    res->basic_spell->text_size = (sfVector2f){230, 80};
    res->basic_spell->text = create_button(res->basic_spell->text_size,
    res->basic_spell->text_pos, "flash", BLUE);
    res->kick->text_pos = (sfVector2f){1200, 800};
    res->kick->text_size = (sfVector2f){180, 80};
    res->kick->text = create_button(res->kick->text_size,
    res->kick->text_pos, "kick", RED);
    res->spell2->text_pos = (sfVector2f){1200, 800};
    res->spell2->text_size = (sfVector2f){215, 80};
    res->spell2->text = create_button(res->spell2->text_size,
    res->spell2->text_pos, "bomb", BLUE);
    sfSprite_setPosition(res->basic_physic->sprite, (sfVector2f){1300, 350});
    sfSprite_setScale(res->basic_physic->sprite, (sfVector2f){1.4, 1.4});
    sfSprite_setScale(res->kick->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(res->basic_spell->sprite, (sfVector2f){1230, 340});
    sfSprite_setScale(res->basic_spell->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(res->kick->sprite, (sfVector2f){1200, 350});
    sfSprite_setPosition(res->spell2->sprite, (sfVector2f){1200, 350});
    sfSprite_setScale(res->spell2->sprite, (sfVector2f){1.4, 1.4});
}

struct attacks *create_attacks_fight(int attack)
{
    struct attacks *res = malloc(sizeof(struct attacks));

    if (res == NULL)
        return NULL;
    res->basic_physic = create_attack(true, "sprite/fight/light.png",
    (sfIntRect){0, 0, 192, 192}, attack);
    res->basic_spell = create_attack(true, "sprite/fight/regeneration.png",
    (sfIntRect){0, 0, 192, 192}, attack);
    res->kick = create_attack(false, "sprite/fight/hit.png",
    (sfIntRect){0, 0, 192, 192}, attack);
    res->spell2 = create_attack(false, "sprite/fight/effect.png",
    (sfIntRect){0, 0, 192, 192}, attack);
    res->basic_physic->text_pos = (sfVector2f){450, 800};
    res->basic_physic->text_size = (sfVector2f){340, 80};
    res->basic_physic->text = create_button(res->basic_physic->text_size,
    res->basic_physic->text_pos, "scratch", RED);
    help_create_attack(res);
    return res;
}
