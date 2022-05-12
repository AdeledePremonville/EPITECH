/*
** EPITECH PROJECT, 2021
** create_text_rect_vect.c
** File description:
** create rect vect text check if pos is in rect
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

sfText *create_text(sfFont *font, sfVector2f pos, char *str, int size)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    return text;
}

sfVector2f vect(float x, float y)
{
    sfVector2f pos = {x, y};

    return (pos);
}

sfVector2i vecti(int x, int y)
{
    sfVector2i pos = {x, y};

    return (pos);
}

sfRectangleShape *create_rect(sfVector2f size, sfVector2f pos, int color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    if (color == 1)
        sfRectangleShape_setFillColor(rect, sfRed);
    if (color == 2)
        sfRectangleShape_setFillColor(rect, sfGreen);
    if (color == 3)
        sfRectangleShape_setFillColor(rect, sfBlue);
    if (color == 4)
        sfRectangleShape_setFillColor(rect, sfTransparent);
    if (color == 5)
        sfRectangleShape_setFillColor(rect, sfMagenta);
    if (color == 6)
        sfRectangleShape_setFillColor(rect, sfCyan);
    if (color == 7)
        sfRectangleShape_setFillColor(rect, sfBlack);
    return (rect);
}

sfIntRect *create_int_rect(sfIntRect *rect, int x, int y)
{
    rect = malloc(sizeof(sfIntRect*) * 2);
    rect->top = x;
    rect->left = x;
    rect->width = y;
    rect->height = y;
    return (rect);
}
