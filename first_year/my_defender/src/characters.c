/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** characters
*/

#include "struct.h"

void sprite_characters_walk_init(struct characters *c)
{
    c->text_dragon_walk = sfTexture_createFromFile("images/dragon_walk", NULL);
    for (int i = 0; i < c->dragon; i++) {
        c->sprite_dragon_walk[i] = sfSprite_create();
        sfSprite_setTexture(c->sprite_dragon_walk[i], c->text_dragon_walk, sfTrue);
    }
    c->text_demon_walk = sfTexture_createFromFile("images/demon_walk", NULL);
    for (int i = 0; i < c->demon; i++) {
        c->sprite_demon_walk[i] = sfSprite_create();
        sfSprite_setTexture(c->sprite_demon_walk[i], c->text_demon_walk, sfTrue);
    }
    c->text_lizard_walk = sfTexture_createFromFile("images/lizard_walk", NULL);
    for (int i = 0; i < c->lizard; i++) {
        c->sprite_lizard_walk[i] = sfSprite_create();
        sfSprite_setTexture(c->sprite_lizard_walk[i], c->text_lizard_walk, sfTrue);
    }
}

void sprite_characters_attack_init(struct attack *a)
{
    a->text_dragon_attack = sfTexture_createFromFile("images/dragon_attack", NULL);
    a->text_fire = sfTexture_createFromFile("images/fire", NULL);
    for (int i = 0; i < 10; i++) {
        a->sprite_dragon_attack[i] = sfSprite_create();
        a->sprite_fire[i] = sfSprite_create();
        sfSprite_setTexture(a->sprite_dragon_attack[i], a->text_dragon_attack, sfTrue);
        sfSprite_setTexture(a->sprite_fire[i], a->text_fire, sfTrue);
    }
    a->text_demon_attack = sfTexture_createFromFile("images/demon_attack", NULL);
    for (int i = 0; i < 10; i++) {
        a->sprite_demon_attack[i] = sfSprite_create();
        sfSprite_setTexture(a->sprite_demon_attack[i], a->text_demon_attack, sfTrue);
    }
    a->text_lizard_attack = sfTexture_createFromFile("images/lizard_attack", NULL);
    for (int i = 0; i < 10; i++) {
        a->sprite_lizard_attack[i] = sfSprite_create();
        sfSprite_setTexture(a->sprite_lizard_attack[i], a->text_lizard_attack, sfTrue);
    }
}

void set_init(struct characters *c)
{
    for (int i = 0; i < c->dragon; i++) {
        sfSprite_setTextureRect(c->sprite_dragon_walk[i], c->rect_dragon_walk[i]);
        sfSprite_setPosition(c->sprite_dragon_walk[i], c->position_dragon_walk[i]);
    }
    for (int i = 0; i < c->demon; i++) {
        sfSprite_setTextureRect(c->sprite_demon_walk[i], c->rect_demon_walk[i]);
        sfSprite_setPosition(c->sprite_demon_walk[i], c->position_demon_walk[i]);
    }
    for (int i = 0; i < c->lizard; i++) {
        sfSprite_setTextureRect(c->sprite_lizard_walk[i], c->rect_lizard_walk[i]);
        sfSprite_setPosition(c->sprite_lizard_walk[i], c->position_lizard_walk[i]);
    }
}

void set_attack_init(struct attack *a)
{
    for (int i = 0; i < 10; i++) {
        sfSprite_setTextureRect(a->sprite_fire[i], a->rect_fire[i]);
        sfSprite_setPosition(a->sprite_fire[i], a->position_fire[i]);
        sfSprite_setTextureRect(a->sprite_dragon_attack[i], a->rect_dragon_attack[i]);
        sfSprite_setPosition(a->sprite_dragon_attack[i], a->position_dragon_attack[i]);
    }
    for (int i = 0; i < 10; i++) {
        sfSprite_setTextureRect(a->sprite_demon_attack[i], a->rect_demon_attack[i]);
        sfSprite_setPosition(a->sprite_demon_attack[i], a->position_demon_attack[i]);
    }
    for (int i = 0; i < 10; i++) {
        sfSprite_setTextureRect(a->sprite_lizard_attack[i], a->rect_lizard_attack[i]);
        sfSprite_setPosition(a->sprite_lizard_attack[i], a->position_lizard_attack[i]);
    }
}
