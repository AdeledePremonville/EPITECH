/*
** EPITECH PROJECT, 2022
** francois_super_code.c
** File description:
** francois_super_code
*/

#include "p.h"
#include "game.h"
#include <stdlib.h>
#include "my.h"

void act_text_nb_max(struct text_nb_max *t, int nb_curr, int nb_max)
{
    char *str_nb_curr;
    char *str_nb_max;

    str_nb_curr = int_to_str(nb_curr);
    sfText_setString(t->curr, str_nb_curr);
    free(str_nb_curr);
    if (nb_max >= 0) {
        str_nb_max = int_to_str(nb_max);
        sfText_setString(t->max, str_nb_max);
        free(str_nb_max);
    }
}

void act_text_nb(struct text_nb *t, int nb)
{
    char *str = int_to_str(nb);

    sfText_setString(t->nb, str);
    free(str);
}

struct text_nb *create_text_nb(char *text, int nb, sfFont *font,
sfVector2f pos)
{
    struct text_nb *res = malloc(sizeof(struct text_nb));
    char *str = int_to_str(nb);

    res->nb_max = nb;
    res->text = create_text(font, pos, text, 50);
    res->nb = create_text(font, vect(pos.x + 500, pos.y), str, 50);
    free(str);
    return res;
}

struct text_nb_max *create_text_max_nb(char *text, sfVector2i nb,
sfFont *font, sfVector2f pos)
{
    struct text_nb_max *res = malloc(sizeof(struct text_nb_max));
    char *nb_curr = int_to_str(nb.x);
    char *nb_max = int_to_str(nb.y);

    res->nb_curr = nb.x;
    res->nb_max = nb.y;
    res->text = create_text(font, pos, text, 50);
    res->curr = create_text(font, vect(pos.x + 500, pos.y), nb_curr, 50);
    free(nb_curr);
    res->max = create_text(font, vect(pos.x + 700, pos.y), nb_max, 50);
    free(nb_max);
    res->slash = create_text(font, vect(pos.x + 600, pos.y), "/", 50);
    return res;
}
