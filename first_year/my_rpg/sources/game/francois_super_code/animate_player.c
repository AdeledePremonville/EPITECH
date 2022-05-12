/*
** EPITECH PROJECT, 2022
** animate_player.c
** File description:
** animate_player
*/

#include "exit.h"
#include "francois_super_code.h"
#include <stdbool.h>
#include <stdio.h>

void move_rect(struct mains *m)
{
    m->rect2.left += m->rect2.width;
    if (m->rect2.left >= (m->rect2.width * m->sprites_nb.x))
        m->rect2.left = 0;
}

int create_clock(struct gettimes *gettime)
{
    gettime->clock = sfClock_create();
    if (!gettime->clock)
        return EXIT_MALLOC;
    return EXIT_SUCCESS;
}

void is_key_pressed(struct mains *m)
{
    if (m->arrow.down)
        m->rect2.top = m->rect2.width * 0;
    if (m->arrow.left)
        m->rect2.top = m->rect2.width * 1;
    if (m->arrow.right)
        m->rect2.top = m->rect2.width * 2;
    if (m->arrow.up)
        m->rect2.top = m->rect2.width * 3;
}

void animate_player(struct mains *m)
{
    m->gettime.time = sfClock_getElapsedTime(m->gettime.clock);
    m->gettime.seconds = m->gettime.time.microseconds / 1000000.0;

    m->gettime_move.time = sfClock_getElapsedTime(m->gettime_move.clock);
    m->gettime_move.seconds = m->gettime_move.time.microseconds / 1000000.0;

    is_key_pressed(m);
    sfSprite_setTextureRect(m->player.sprite, m->rect2);
}
