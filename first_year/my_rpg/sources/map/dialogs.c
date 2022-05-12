/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** dialogs.c
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>

void create_dial_bub(struct map_info *mi, sfRenderWindow *win,
struct mains *m)
{
    sfVector2f pos = act_pos_d(vect(200, 760), m->rect3);
    sfVector2f size = {1520, 300};
    sfColor color = sfColor_fromRGBA(163, 163, 163, 255);
    sfRectangleShape *b_rec = sfRectangleShape_create();

    sfRectangleShape_setFillColor(b_rec, sfWhite);
    sfRectangleShape_setOutlineThickness(b_rec, 10);
    sfRectangleShape_setOutlineColor(b_rec, color);
    sfRectangleShape_setSize(b_rec, size);
    sfRectangleShape_setPosition(b_rec, pos);
    mi->diag_rec = b_rec;
    sfRenderWindow_drawRectangleShape(win, mi->diag_rec, NULL);
    sfRectangleShape_destroy(b_rec);
}

void create_dial_text(struct map_info *mi, sfRenderWindow *win, char *str,
struct mains *m)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("sprite/menu/police.TTF");
    sfVector2f pos = act_pos_d(vect(220, 780), m->rect3);

    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    mi->diag_text = text;
    sfText_setString(mi->diag_text, str);
    sfRenderWindow_drawText(win, mi->diag_text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}
