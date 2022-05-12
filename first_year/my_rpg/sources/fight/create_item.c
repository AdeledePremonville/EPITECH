/*
** EPITECH PROJECT, 2022
** character.c
** File description:
** character fight - my_rpg
*/

#include "p.h"
#include "my.h"
#include <stdlib.h>

struct item *create_item(sfVector2f size, sfVector2f pos, char *str, int nb)
{
    char *font_str = "sprite/fight/font_fight/font_fight.ttf";
    sfFont *font = sfFont_createFromFile(font_str);
    struct item *res = malloc(sizeof(struct item));

    res->size = size;
    res->pos = pos;
    res->button = create_button(size, pos, str, GREEN);
    res->nb = sfText_create();
    sfText_setString(res->nb, int_to_str(nb));
    sfText_setFont(res->nb, font);
    sfText_setColor(res->nb, sfWhite);
    sfText_setPosition(res->nb, (sfVector2f){pos.x + 100, pos.y - 140});
    sfText_setScale(res->nb, (sfVector2f){3.5, 3.5});
    res->potion = nb;
    return res;
}

struct items *create_items(struct param_fight *p)
{
    struct items *res = malloc(sizeof(struct items));

    if (res == NULL)
        return NULL;
    res->has_shoes = false;
    res->level_shoes = 0;
    res->has_sword = false;
    res->level_sword = 0;
    res->has_scepter = false;
    res->level_scepter = 0;
    res->potion_100hp = create_item((sfVector2f){200, 170},
    (sfVector2f){600, 800}, "Heal\n50HP", p->nb_pot_100hp);
    res->potion_200hp = create_item((sfVector2f){230, 170},
    (sfVector2f){1200, 800}, "Heal\n100HP", p->nb_pot_200hp);
    res->potion_100hp->dgt = 50;
    res->potion_200hp->dgt = 100;
    return res;
}
