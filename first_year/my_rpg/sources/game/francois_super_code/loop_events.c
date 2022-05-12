/*
** EPITECH PROJECT, 2022
** loop_hover_events.c
** File description:
** loop_hover_events
*/

#include "exit.h"
#include "p.h"
#include <stdio.h>

void if_itis_menu_nb_two(struct mains *m, struct pnj_monster *p,
struct menu *menu, struct map_info *m_i)
{
    int res = check_music_fr(menu, m->event, menu->settings->music_vol);

    if (res == 1) {
        sfRenderWindow_setView(m->window, m->view);
        return;
    }
    if (res == 2) {
        sfRenderWindow_setView(menu->window,
        sfRenderWindow_getDefaultView(menu->window));
        return;
    }
    if (m->event.type == sfEvtClosed) {
        sfRenderWindow_close(menu->window);
        menu->nb_menu = 1;
        menu->is_game = false;
    }
}

void help_help_analyse_events(struct mains *m, struct pnj_monster *p,
struct menu *menu, struct map_info *m_i)
{
    if (menu->nb_menu == 2)
        if_itis_menu_nb_two(m, p, menu, m_i);
    if (m->ih->can_go_next == true && m->ih->with_pnj == true
        && m->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyY))
            m->ih->load_new_lvl = true;
    }
}

void help_analyse_events(struct mains *m, struct pnj_monster *p,
struct menu *menu, struct map_info *m_i)
{
    if (menu->is_game == true && menu->nb_menu == 2) {
        if (if_button_s_pressed(menu->settings->b_save1, menu->window,
            menu->mouse, m->event) == 1) {
            save_data(1, fill_struct_save(m));
            sfSound_play(menu->music->button);
        }
        if (if_button_s_pressed(menu->settings->b_save2, m->window,
            menu->mouse, m->event) == 1) {
            save_data(2, fill_struct_save(m));
            sfSound_play(menu->music->button);
        }
        if (if_button_s_pressed(menu->settings->b_exit, m->window,
            menu->mouse, m->event) == 1) {
            sfSound_play(menu->music->button);
            menu->is_game = false;
            menu->nb_menu = 1;
        }
    }
    help_help_analyse_events(m, p, menu, m_i);
}

void analyse_events(struct mains *m, struct pnj_monster *p,
struct menu *menu, struct map_info *m_i)
{
    while (sfRenderWindow_pollEvent(m->window, &m->event)) {
        manage_keys_pressed(m, menu);
        if (if_button_s_pressed(menu->b_settings, menu->window,
            menu->mouse, m->event) == 1 && menu->nb_menu == 1) {
            sfSound_play(menu->music->button);
            sfRenderWindow_setView(m->window,
            sfRenderWindow_getDefaultView(m->window));
            menu->nb_menu = 2;
        }
        if (if_button_s_pressed(menu->b_stat, menu->window,
            menu->mouse, m->event) == 1 && menu->nb_menu == 1)
            menu->nb_menu = 3;
        if (if_button_s_pressed(menu->b_leave, menu->window,
        menu->mouse, m->event) == 1 && menu->nb_menu == 1)
            sfRenderWindow_close(menu->window);
        help_analyse_events(m, p, menu, m_i);
    }
}
