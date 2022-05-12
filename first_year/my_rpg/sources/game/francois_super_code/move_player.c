/*
** EPITECH PROJECT, 2022
** move_player.c
** File description:
** move_player
*/

#include "exit.h"
#include "francois_super_code.h"
#include <stdio.h>

const int speed = 10;
const int left = -(speed);
const int up = -(speed);
const int right = speed;
const int down = speed;

static void move_left(struct mains *m)
{
    if (m->event.key.code == sfKeyLeft) {
        m->arrow.left = true;
        if (m->gettime_move.seconds < 0.5)
            return;
        if (m->player_pos.x + left < m->rect3.left) {
            sfView_move(m->view, (sfVector2f){left, 0});
            m->rect3.left = m->rect3.left + left;
        }
        if (m->player_pos.x + left >= m->map_size.left)
            sfSprite_move(m->player.sprite, (sfVector2f){left, 0});
    }
}

static void move_top(struct mains *m)
{
    if (m->event.key.code == sfKeyUp) {
        m->arrow.up = true;
        if (m->player_pos.y + up < m->rect3.top) {
            sfView_move(m->view, (sfVector2f){0, up});
            m->rect3.top = m->rect3.top + up;
        }
        if (m->player_pos.y + up >= m->map_size.top)
            sfSprite_move(m->player.sprite, (sfVector2f){0, up});
    }
}

static void move_right(struct mains *m)
{
    if (m->event.key.code == sfKeyRight) {
        m->arrow.right = true;
        if (m->player_pos.x + right > m->rect3.left + m->rect3.width) {
            sfView_move(m->view, (sfVector2f){right, 0});
            m->rect3.left = m->rect3.left + right;
        }
        if (m->player_pos.x + right < m->map_size.width)
        sfSprite_move(m->player.sprite, (sfVector2f){right, 0});
    }
}

static void move_down(struct mains *m)
{
    if (m->event.key.code == sfKeyDown) {
        m->arrow.down = true;
        if (m->player_pos.y + down > m->rect3.top + m->rect3.height) {
            sfView_move(m->view, (sfVector2f){0, down});
            m->rect3.top = m->rect3.top + down;
        }
        if (m->player_pos.y + down < m->map_size.height)
            sfSprite_move(m->player.sprite, (sfVector2f){0, down});
    }
}

void move_player(struct mains *m)
{
    m->player_pos = sfSprite_getPosition(m->player.sprite);

    move_left(m);
    move_top(m);
    move_right(m);
    move_down(m);
    sfRenderWindow_setView(m->window, m->view);
}
