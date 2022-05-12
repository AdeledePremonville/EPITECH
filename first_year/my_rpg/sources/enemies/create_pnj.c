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

void fill_last_main(struct mains *m)
{
    m->ih->load_new_lvl = false;
    m->ih->with_pnj = false;
    m->ih->can_go_next = false;
    m->ih->end = false;
    m->ih->quest = false;
    m->ih->start_lvl_up = false;
    m->ih->lvl_up = false;
}

void destroy_pnj(struct pnj **p)
{
    for (int i = 0; p[i] != NULL; i++) {
        sfSprite_destroy(p[i]->sprite);
        sfTexture_destroy(p[i]->texture);
        free(p[i]->rect);
        sfClock_destroy(p[i]->clock);
        free(p[i]);
    }
    free(p);
}

static void help_create_one_pnj(struct pnj *p, int i)
{
    p->chara = sfSprite_create();
    p->text_chara = sfTexture_createFromFile("sprite/game/face.png", NULL);
    sfSprite_setTexture(p->chara, p->text_chara, sfFalse);
    if (i <= 3) {
        p->rect_chara = create_int_rect(p->rect_chara, 0 + i * 145, 145);
        p->rect_chara->top = 0;
    } else {
        p->rect_chara = create_int_rect(p->rect_chara,
        0 + (i - 4) * 145, 145);
        p->rect_chara->top = 145;
    }
    sfSprite_setTextureRect(p->chara, p->rect_chara[0]);
    sfSprite_setPosition(p->chara, vect(760, 320));
}

static void create_one_pnj(struct pnj *p, int i)
{
    p->sprite = sfSprite_create();
    p->texture = sfTexture_createFromFile("sprite/game/pnj.png",
    NULL);
    sfSprite_setTexture(p->sprite, p->texture, sfFalse);
    sfSprite_setScale(p->sprite, vect(1, 1));
    p->pos = vect(rand_int(-200, 2000), rand_int(-600, 1900));
    sfSprite_setPosition(p->sprite, p->pos);
    p->rect = create_int_rect(p->rect, 0, 48);
    sfSprite_setTextureRect(p->sprite, p->rect[0]);
    p->clock = sfClock_create();
    p->alive = false;
    p->direction = rand_max(5);
    p->nb_step = 0;
    p->speed = 140000;
    p->max_step = 10;
    p->size_step = 3;
    p->nb_dir = 10;
    help_create_one_pnj(p, i);
}

struct pnj **create_pnj(int stage)
{
    struct pnj **p = malloc(sizeof(struct pnj *) * 9);

    if (p == NULL)
        return put_error_null("error malloc create_pnj\n");
    for (int i = 0; i != 8; i++) {
        p[i] = malloc(sizeof(struct pnj) * 1);
        if (p[i] == NULL)
            return put_error_null("error malloc create_pnj 2\n");
        create_one_pnj(p[i], i);
    }
    p[1]->pos = vect(1600, 1100);
    p[stage]->alive = true;
    p[8] = NULL;
    return p;
}
