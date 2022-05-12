/*
** EPITECH PROJECT, 2021
** menu_rpg.c
** File description:
** menu for rpg
*/

#include "my.h"
#include "p.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

int check_music_fr(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (if_button_s_pressed(m->settings->music_vol->b_up, m->window,
        m->mouse, event) == 1) {
        refresh_vol(v, 0, m->music);
    }
    if (if_button_s_pressed(m->settings->music_vol->b_down, m->window,
        m->mouse, event) == 1) {
        refresh_vol(v, 1, m->music);
    }
    check_fr(m, event, v);
    return event_settings(m, event, v);
}

void event_menu2(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (if_button_s_pressed(m->b_reset2, m->window,
        m->mouse, event) == 1 && m->nb_menu == 1) {
        clear_save(2);
        sfSound_play(m->music->button);
    }
    if (if_button_s_pressed(m->b_settings, m->window,
        m->mouse, event) == 1 && m->nb_menu == 1) {
        sfSound_play(m->music->button);
        m->nb_menu = 2;
    }
    if (if_button_s_pressed(m->b_leave, m->window,
        m->mouse, event) == 1 && m->nb_menu == 1)
        sfRenderWindow_close(m->window);
    if (event.type == sfEvtClosed ||
    (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
        sfRenderWindow_close(m->window);
    if (m->nb_menu == 2)
        check_music_fr(m, event, v);
}

void event_menu(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (if_button_s_pressed(m->b_save1, m->window,
        m->mouse, event) == 1 && m->nb_menu == 1) {
        sfSound_play(m->music->button);
        start_load(m, event, v, 1);
    }
    if (if_button_s_pressed(m->b_save2, m->window,
        m->mouse, event) == 1 && m->nb_menu == 1) {
        sfSound_play(m->music->button);
        start_load(m, event, v, 2);
    }
    if (if_button_s_pressed(m->b_reset1, m->window,
        m->mouse, event) == 1 && m->nb_menu == 1) {
        clear_save(1);
        sfSound_play(m->music->button);
    }
    event_menu2(m, event, v);
}

void display_menu(struct menu *m, sfEvent event)
{
    sfRenderWindow_drawSprite(m->window, m->background, NULL);
    sfRenderWindow_drawSprite(m->window, m->panel, NULL);
    if (m->nb_menu == 1) {
        sfRenderWindow_drawText(m->window, m->title, NULL);
        draw_button_s(m->b_save1, m->window, m->mouse);
        draw_button_s(m->b_save2, m->window, m->mouse);
        draw_button_s(m->b_reset1, m->window, m->mouse);
        draw_button_s(m->b_reset2, m->window, m->mouse);
        draw_button_s(m->b_settings, m->window, m->mouse);
        draw_button_s(m->b_leave, m->window, m->mouse);
    }
    if (m->nb_menu == 2) {
        draw_music_volume(m, m->settings->music_vol);
        draw_frame_rate(m, m->settings->fr);
        draw_settings(m, false);
    }
    sfRenderWindow_display(m->window);
    while (sfRenderWindow_pollEvent(m->window, &event))
        event_menu(m, event, m->settings->music_vol);
    sfRenderWindow_clear(m->window, sfBlack);
}

int menu_rpg(int ac, char **av)
{
    struct menu *menu = create_menu();
    sfEvent event;

    menu->is_game = false;
    if (menu == NULL)
        return 84;
    sfMusic_play(menu->music->menu);
    sfMusic_setLoop(menu->music->menu, sfTrue);
    while (sfRenderWindow_isOpen(menu->window)) {
        menu->mouse = sfMouse_getPositionRenderWindow(menu->window);
        display_menu(menu, event);
    }
    sfMusic_stop(menu->music->menu);
    destroy_menu(menu);
    return (0);
}
