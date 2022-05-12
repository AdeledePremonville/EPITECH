/*
** EPITECH PROJECT, 2021
** menu_rpg.c
** File description:
** menu for rpg
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void destroy_enemy_map(struct enemy_map **e)
{
    for (int i = 0; e[i] != NULL; i++) {
        sfSprite_destroy(e[i]->sprite);
        sfTexture_destroy(e[i]->texture);
        free(e[i]->rect);
        sfClock_destroy(e[i]->clock);
        free(e[i]);
    }
    free(e);
}

static void change_speed_monster(struct enemy_map *e, int i)
{
    if (i == 0) {
        e->speed = 80000;
        e->max_step = 8;
        e->size_step = 10;
        e->nb_dir = 4;
    }
    if (i == 1) {
        e->speed = 140000;
        e->max_step = 10;
        e->size_step = 2;
        e->nb_dir = 4;
    }
    if (i == 2) {
        e->speed = 150000;
        e->max_step = 18;
        e->size_step = 6;
        e->nb_dir = 8;
    }
}

static void create_one_enemy_map(struct enemy_map *e, int i)
{
    e->sprite = sfSprite_create();
    e->texture = sfTexture_createFromFile("sprite/game/Monster.png",
    NULL);
    sfSprite_setTexture(e->sprite, e->texture, sfFalse);
    sfSprite_setScale(e->sprite, vect(1, 1));
    e->pos = vect(rand_int(-200, 2000), rand_int(-600, 1900));
    e->rect = create_int_rect(e->rect, 0 + i * 144, 48);
    sfSprite_setTextureRect(e->sprite, e->rect[0]);
    e->clock = sfClock_create();
    e->alive = true;
    e->direction = rand_max(4);
    e->nb_step = 0;
    change_speed_monster(e, i);
}

struct enemy_map **create_enemy_map(void)
{
    struct enemy_map **e = malloc(sizeof(struct enemy_map*) * 4);

    srand(time(NULL));
    if (e == NULL)
        return put_error_null("error malloc create_enemy_map\n");
    for (int i = 0; i != 3; i++) {
        e[i] = malloc(sizeof(struct enemy_map) * 1);
        if (e[i] == NULL)
            return put_error_null("error malloc create_enemy_map 2\n");
        create_one_enemy_map(e[i], i);
    }
    e[3] = NULL;
    return e;
}
