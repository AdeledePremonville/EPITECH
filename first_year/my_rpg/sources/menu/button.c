/*
** EPITECH PROJECT, 2021
** button.c
** File description:
** fct button mangament
*/

#include "../include/my.h"
#include "../include/p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void start_press(struct button *b)
{
    if (b->is_pressed == 0) {
        b->is_pressed = 1;
        sfClock_restart(b->clock);
    }
}

void draw_button(struct button *b, sfRenderWindow *wind, sfVector2i mouse)
{
    sfVector2f pos = vect(b->pos_t.x + 10, b->pos_t.y + 10);

    if (pos_is_inrect(mouse, b->size, b->pos) == 1)
        sfText_setColor(b->text, sfYellow);
    else
        sfText_setColor(b->text, sfWhite);
    if (b->is_pressed == 1) {
        sfText_setCharacterSize(b->text, 80);
        sfText_setPosition(b->text, pos);
        b->time = sfClock_getElapsedTime(b->clock);
        if (b->time.microseconds > 100000) {
            sfText_setCharacterSize(b->text, 100);
            sfText_setPosition(b->text, b->pos_t);
            b->is_pressed = 0;
        }
    }
    sfRenderWindow_drawRectangleShape(wind, b->rect, NULL);
    sfRenderWindow_drawText(wind, b->text, NULL);
}

void destroy_button(struct button *button)
{
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
    sfRectangleShape_destroy(button->rect);
    sfClock_destroy(button->clock);
    free(button);
}

struct button *create_button(sfVector2f size, sfVector2f pos, char *s, int co)
{
    struct button *b = malloc(sizeof(struct button) * 2);
    sfVector2f pos_text = vect(pos.x + size.x / 100 + 5,
    pos.y + size.y / 100 - 25);

    if (b == NULL)
        return NULL;
    b->pos_t = pos_text;
    b->font = sfFont_createFromFile("sprite/fight/font_fight/font_fight.ttf");
    b->text = create_text(b->font, pos_text, s, 100);
    b->rect = create_rect(size, pos, co);
    b->size = size;
    b->pos = pos;
    b->is_pressed = 0;
    b->clock = sfClock_create();
    return b;
}
