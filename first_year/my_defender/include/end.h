/*
** EPITECH PROJECT, 2022
** end.h
** File description:
** end_h - my_defender
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"

#ifndef END_H
    #define END_H

typedef struct end_t
{
    sfText *text;
    sfFont *font;
    sfFont *pixel;
    sfText *click;
    sfText *score;
    sfText *yours;
    sfSprite *square;
} end_t;

void end_menu(sfRenderWindow *window, int end, int sc);

void events_end(struct defender *def, sfEvent event, sfRenderWindow *window);

char *int_to_str(int nb);

int ten_mult(int nb);

int my_intlen(int nb);

void set_end_struct2(end_t *res, int sc);

void set_end_struct(end_t *res, int end);

#endif /* !END_H */
