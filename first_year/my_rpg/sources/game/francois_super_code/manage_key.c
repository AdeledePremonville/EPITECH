/*
** EPITECH PROJECT, 2022
** loop_hover_events.c
** File description:
** loop_hover_events
*/

#include "exit.h"
#include "p.h"
#include <stdio.h>

void manage_arrows_pressed(struct mains *m)
{
    if (m->event.key.code) {
        m->arrow.left = false;
        m->arrow.up = false;
        m->arrow.right = false;
        m->arrow.down = false;
        display_player_running_animation(m);
        move_player(m);
    }
}

void manage_keys_pressed(struct mains *m, struct menu *menu)
{
    if ((m->event).type == sfEvtKeyPressed) {
        if (m->event.key.code == sfKeyEscape && menu->nb_menu == 1)
            sfRenderWindow_close(menu->window);
        if (m->event.key.code == sfKeyEscape && menu->nb_menu == 2)
            menu->nb_menu = 2;
        if (menu->nb_menu == 1)
            manage_arrows_pressed(m);
    } else
        m->rect2.left = 0;
    if ((m->event).type == sfEvtClosed && menu->nb_menu == 1)
        sfRenderWindow_close(menu->window);
}
