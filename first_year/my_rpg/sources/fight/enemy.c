/*
** EPITECH PROJECT, 2022
** enemy.c
** File description:
** enemy fight - myrpg
*/

#include <stdlib.h>
#include "p.h"

sfIntRect case_enemy(struct param_fight *p)
{
    switch (p->enemy) {
        case BAT:
        return (sfIntRect){0, 48, 48, 48};
        case SLIME:
        return (sfIntRect){144, 48, 48, 48};
        case GOBELIN:
        return (sfIntRect){288, 48, 48, 48};
        default:
        return (sfIntRect){0, 0, 0, 0};
    }
}

struct enemy *create_enemy(struct param_fight *p)
{
    struct enemy *res = malloc(sizeof(struct enemy));

    res->sprite = sfSprite_create();
    res->texture = sfTexture_createFromFile("sprite/fight/enemies.png", NULL);
    sfSprite_setTexture(res->sprite, res->texture, sfFalse);
    res->rect = case_enemy(p);
    res->type = res->rect.left;
    sfSprite_setTextureRect(res->sprite, res->rect);
    res->clock = sfClock_create();
    res->time = sfClock_getElapsedTime(res->clock);
    res->seconds = sfTime_asSeconds(res->time);
    res->health = create_health((double)p->enemy_max_hp,
    (sfVector2f){1200, 200}, (sfVector2f){300, 40});
    res->attacks = create_attacks_fight(p->enemy_attack);
    sfSprite_setPosition(res->attacks->basic_physic->sprite,
    (sfVector2f){300, 350});
    sfSprite_setPosition(res->sprite, (sfVector2f){1300, 400});
    sfSprite_setScale(res->sprite, (sfVector2f){4.3, 4.3});
    res->dir = 0;
    return res;
}

void move_enemy(sfIntRect *rect, int max, int add, int *dir)
{
    if (*dir == 0)
        rect->left += add;
    else
        rect->left -= add;
    if (rect->left >= max && *dir == 0)
        *dir = 1;
    if (rect->left <= (max - 96) && *dir == 1)
        *dir = 0;
}

void destroy_enemy_help(struct enemy *chara)
{
    sfSprite_destroy(chara->attacks->basic_physic->sprite);
    sfTexture_destroy(chara->attacks->basic_physic->texture);
    sfClock_destroy(chara->attacks->basic_physic->clock);
    free(chara->attacks->basic_physic);
    destroy_button(chara->attacks->basic_spell->text);
    sfSprite_destroy(chara->attacks->basic_spell->sprite);
    sfTexture_destroy(chara->attacks->basic_spell->texture);
    sfClock_destroy(chara->attacks->basic_spell->clock);
    free(chara->attacks->basic_spell);
    destroy_button(chara->attacks->kick->text);
    sfSprite_destroy(chara->attacks->kick->sprite);
    sfTexture_destroy(chara->attacks->kick->texture);
    sfClock_destroy(chara->attacks->kick->clock);
    free(chara->attacks->kick);
    destroy_button(chara->attacks->spell2->text);
    sfSprite_destroy(chara->attacks->spell2->sprite);
    sfTexture_destroy(chara->attacks->spell2->texture);
    sfClock_destroy(chara->attacks->spell2->clock);
    free(chara->attacks->spell2);
    free(chara->attacks);
}

void destroy_enemy_fight(struct enemy *enemy)
{
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    sfClock_destroy(enemy->clock);
    sfRectangleShape_destroy(enemy->health->health);
    sfRectangleShape_destroy(enemy->health->damage);
    free(enemy->health);
    destroy_button(enemy->attacks->basic_physic->text);
    destroy_enemy_help(enemy);
}
