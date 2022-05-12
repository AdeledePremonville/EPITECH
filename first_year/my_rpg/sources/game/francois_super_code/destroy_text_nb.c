/*
** EPITECH PROJECT, 2022
** francois_super_code.c
** File description:
** francois_super_code
*/

#include "p.h"
#include "game.h"
#include <stdlib.h>

void draw_text_nb(struct text_nb *t, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, t->text, NULL);
    sfRenderWindow_drawText(window, t->nb, NULL);
}

void draw_text_nb_max(struct text_nb_max *t, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, t->text, NULL);
    sfRenderWindow_drawText(window, t->curr, NULL);
    sfRenderWindow_drawText(window, t->slash, NULL);
    sfRenderWindow_drawText(window, t->max, NULL);
}

void destroy_text_nb(struct text_nb *t)
{
    sfText_destroy(t->text);
    sfText_destroy(t->nb);
    free(t);
}

void destroy_text_nb_max(struct text_nb_max *t)
{
    sfText_destroy(t->text);
    sfText_destroy(t->curr);
    sfText_destroy(t->max);
    sfText_destroy(t->slash);
    free(t);
}
