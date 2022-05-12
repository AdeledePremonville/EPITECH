/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** buildings_price
*/

#include "struct.h"

void square_init(struct square *s)
{
    for (int i = 0; i < 4; i++) {
        s->sprite_square[i] = sfSprite_create();
        s->text_square[i] = sfTexture_createFromFile("images/square", NULL);
        sfSprite_setTexture(s->sprite_square[i], s->text_square[i], sfTrue);
    }
}

void square_pos(struct square *s)
{
    s->position_square[0].x = 560;
    s->position_square[0].y = 811;
    s->position_square[1].x = 760;
    s->position_square[1].y = 811;
    s->position_square[2].x = 960;
    s->position_square[2].y = 811;
    s->position_square[3].x = 1160;
    s->position_square[3].y = 811;
    for (int i = 0; i < 4; i++)
        sfSprite_setPosition(s->sprite_square[i], s->position_square[i]);
}

void buildings_square_init(struct buildings *b)
{
    for (int i = 0; i < 3; i++) {
        b->sprite_wall[i] = sfSprite_create();
        b->text_wall[i] = sfTexture_createFromFile("images/wall", NULL);
        sfSprite_setTexture(b->sprite_wall[i], b->text_wall[i], sfTrue);
    }
    for (int i = 0; i < 3; i++) {
        b->sprite_sniper[i] = sfSprite_create();
        b->text_sniper[i] = sfTexture_createFromFile("images/sniper", NULL);
        sfSprite_setTexture(b->sprite_sniper[i], b->text_sniper[i], sfTrue);
    }
    for (int i = 0; i < 3; i++) {
        b->sprite_roblox[i] = sfSprite_create();
        b->text_roblox[i] = sfTexture_createFromFile("images/roblox", NULL);
        sfSprite_setTexture(b->sprite_roblox[i], b->text_roblox[i], sfTrue);
    }
    for (int i = 0; i < 3; i++) {
        b->sprite_tesla[i] = sfSprite_create();
        b->text_tesla[i] = sfTexture_createFromFile("images/tesla", NULL);
        sfSprite_setTexture(b->sprite_tesla[i], b->text_tesla[i], sfTrue);
    }
}

void buildings_square_pos(struct buildings *b)
{
    for (int i = 0; i < 3; i++) {
        b->position_wall[i] = (sfVector2f) {630, 831};
        b->position_sniper[i] = (sfVector2f) {790, 841};
        b->position_roblox[i] = (sfVector2f) {990, 841};
        b->position_tesla[i] = (sfVector2f) {1215, 841};
        sfSprite_setPosition(b->sprite_sniper[i], b->position_sniper[i]);
        sfSprite_setPosition(b->sprite_roblox[i], b->position_roblox[i]);
        sfSprite_setPosition(b->sprite_tesla[i], b->position_tesla[i]);
        sfSprite_setPosition(b->sprite_wall[i], b->position_wall[i]);
    }
    b->text_shadow = sfTexture_createFromFile("images/shadow", NULL);
    for (int i = 0; i < 2; i++) {
        b->sprite_shadow[i] = sfSprite_create();
        sfSprite_setTexture(b->sprite_shadow[i], b->text_shadow, sfTrue);
    }
}

void shadow(sfRenderWindow *window, struct buildings *b)
{
    if (b->step == 4 || b->step == 6) {
        b->position_shadow[0].x = 1480;
        b->position_shadow[0].y = 360;
        b->position_shadow[1].x = 1480;
        b->position_shadow[1].y = 660;
    }
    if (b->step == 7 || b->step == 9) {
        b->position_shadow[0].x = 520;
        b->position_shadow[0].y = 600;
        b->position_shadow[1].x = 1320;
        b->position_shadow[1].y = 600;
    }
    if (b->step == 10 || b->step == 12) {
        b->position_shadow[0].x = 752;
        b->position_shadow[0].y = 500;
        b->position_shadow[1].x = 1060;
        b->position_shadow[1].y = 505;
    }
}