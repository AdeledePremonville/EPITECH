/*
** EPITECH PROJECT, 2022
** loop_hover_events.c
** File description:
** loop_hover_events
*/

#include "p.h"
#include <stdio.h>

sfVector2f act_pos_d(sfVector2f pos, sfIntRect rect)
{
    sfVector2f res = {pos.x + (rect.left - 860), pos.y + (rect.top - 440)};

    return res;
}

sfVector2f act_pos(sfVector2f pos, sfIntRect rect, sfSprite *sprite)
{
    sfVector2f res = {pos.x + (rect.left - 860), pos.y + (rect.top - 440)};

    sfSprite_setPosition(sprite, res);
    return res;
}

void act_pos_b(sfVector2f pos, sfIntRect rect, struct button_s *b)
{
    sfVector2f res = {rect.left - 860 + 30, rect.top - 440 + 30};

    b->pos_sign = act_pos(vect(pos.x + 16, pos.y + 16), rect, b->sign);
    b->pos_panel = act_pos(pos, rect, b->panel);
    b->info->pos_info = act_pos(vect(0, 0), rect, b->info->info);
    sfText_setPosition(b->info->text, res);
}

sfVector2i get_pos_mouse_map(sfRenderWindow *window, struct mains *m)
{
    sfVector2i res = sfMouse_getPositionRenderWindow(window);

    res = (sfVector2i){res.x + m->rect3.left - 860,
    (res.y + m->rect3.top - 440)};
    return res;
}
