/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** enemies.c
*/

#include "my.h"
#include "p.h"

enemy_s *create_enemy(unsigned int hp, unsigned int speed, int index)
{
    enemy_s *enemy = malloc(sizeof(*enemy));
    sfIntRect rec = {.height = 64, .width = 64, .left = 0, .top = 0};
    sfTexture *text = sfTexture_createFromFile("sprites/monsters_2.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, text, sfFalse);
    sfSprite_setTextureRect(sprite, (sfIntRect){.height = 64, .width = 64});
    enemy->hp = hp;
    enemy->speed = speed;
    enemy->sprite = sprite;
    return enemy;
}
