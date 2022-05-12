/*
** EPITECH PROJECT, 2021
** info_button.c
** File description:
** fct info button
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>

void destroy_sprite(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void destroy_info_button(struct info_button *i)
{
    destroy_sprite(i->info, i->t_info);
    sfText_destroy(i->text);
    sfFont_destroy(i->font);
    free(i);
}

void destroy_button_s(struct button_s *button)
{
    destroy_sprite(button->sign, button->t_sign);
    destroy_sprite(button->panel, button->t_panel);
    if (button->has_text == true)
        destroy_info_button(button->info);
    sfClock_destroy(button->clock);
    free(button);
}

void add_text_info(struct button_s *b, char *str, int size, sfVector2f pos)
{
    sfVector2f pos_text = vect(pos.x + 30, pos.y + 30);

    b->info->font = sfFont_createFromFile("sprite/menu/police.TTF");
    b->info->text = create_text(b->info->font, pos_text, str, size);
    sfText_setColor(b->info->text, sfBlack);
    b->info->pos_info = pos;
}

struct info_button *create_info_button(sfVector2f pos, sfVector2f scale,
char *path_sprite)
{
    struct info_button *i = malloc(sizeof(struct info_button) * 2);

    if (i == NULL)
        return NULL;
    i->info = sfSprite_create();
    i->t_info = sfTexture_createFromFile(path_sprite, NULL);
    sfSprite_setTexture(i->info, i->t_info, sfFalse);
    sfSprite_setPosition(i->info, pos);
    sfSprite_setScale(i->info, scale);
    return i;
}
