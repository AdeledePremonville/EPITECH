/*
** EPITECH PROJECT, 2022
** health
** File description:
** health - myrpg
*/

#include "p.h"
#include "my.h"
#include <stdlib.h>

struct health_bar *create_health(double life, sfVector2f pos, sfVector2f size)
{
    char *font_str = "sprite/fight/font_fight/font_fight.ttf";
    sfFont *font = sfFont_createFromFile(font_str);
    struct health_bar *res = malloc(sizeof(struct health_bar));

    res->text = sfText_create();
    sfText_setString(res->text, int_to_str(life));
    sfText_setFont(res->text, font);
    sfText_setPosition(res->text, (sfVector2f){pos.x + 120, pos.y - 100});
    sfText_setScale(res->text, (sfVector2f){2, 2});
    sfText_setColor(res->text, sfWhite);
    res->life = life;
    res->dmg = 0;
    res->health = create_rect(size, pos, GREEN);
    res->damage = sfRectangleShape_create();
    sfRectangleShape_setFillColor(res->damage, sfRed);
    sfRectangleShape_setPosition(res->damage,
    (sfVector2f){pos.x + size.x, pos.y});
    sfRectangleShape_setSize(res->damage, (sfVector2f){0, 40});
    return res;
}

sfVector2f calc_damage(struct health_bar *health)
{
    sfVector2f res;
    double calc = health->dmg / health->life;

    res.x = ((health->dmg / health->life) * 300);
    res.y = 40;
    return res;
}

sfVector2f calc_pos_damage(struct health_bar *health)
{
    sfVector2f res;
    double calc = ((health->dmg / health->life) * 300);

    res.x = sfRectangleShape_getPosition(health->health).x - calc + 300;
    res.y = 200;
    return res;
}
