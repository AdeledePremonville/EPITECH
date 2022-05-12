/*
** EPITECH PROJECT, 2021
** check_colli.c
** File description:
** check collision
*/

#include "my.h"
#include "p.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

int pos_is_inrect(sfVector2i pos, sfVector2f size_rec, sfVector2f pos_rec)
{
    if (pos.x > pos_rec.x && pos.y > pos_rec.y &&
        pos.x < (pos_rec.x + size_rec.x) &&
        pos.y < (pos_rec.y + size_rec.y))
        return 1;
    return 0;
}

void set_pos_button_s(struct button_s *b, sfVector2f pos)
{
    b->pos_panel = pos;
    b->pos_sign = vect(pos.x + 16, pos.y + 16);
    sfSprite_setPosition(b->panel, b->pos_panel);
    sfSprite_setPosition(b->sign, b->pos_sign);
    if (b->has_text == true) {
        b->info->pos_info = vect(0, 0);
        sfSprite_setPosition(b->info->info, b->info->pos_info);
        sfText_setPosition(b->info->text, vect(30, 30));
    }
}
