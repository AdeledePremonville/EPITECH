/*
** EPITECH PROJECT, 2022
** loop_hover_events.c
** File description:
** loop_hover_events
*/

#include "exit.h"
#include "p.h"
#include <stdio.h>

void display_running_game(struct mains *m)
{
    animate_player(m);
    sfRenderWindow_drawSprite(m->window, m->player.sprite, NULL);
}

void display_player_running_animation(struct mains *m)
{
    if (m->gettime.seconds > 0.3) {
        move_rect(m);
        sfClock_restart(m->gettime.clock);
    }
}

void display_settings(struct mains *m, struct pnj_monster *m_e,
struct menu *menu, struct map_info *m_i)
{
    if (menu->nb_menu == 1) {
        act_pos_b(vect(1700, 50), m->rect3, menu->b_settings);
        act_pos_b(vect(1800, 50), m->rect3, menu->b_leave);
        act_pos_b(vect(1600, 50), m->rect3, menu->b_stat);
        draw_button_s(menu->b_settings, m->window, menu->mouse);
        draw_button_s(menu->b_leave, menu->window, menu->mouse);
        draw_button_s(menu->b_stat, m->window, menu->mouse);
    }
    while (menu->nb_menu == 2) {
        sfRenderWindow_drawSprite(m->window, menu->background, NULL);
        sfRenderWindow_drawSprite(m->window, menu->panel, NULL);
        menu->mouse = sfMouse_getPositionRenderWindow(menu->window);
        analyse_events(m, m_e, menu, m_i);
        draw_music_volume(menu, menu->settings->music_vol);
        draw_frame_rate(menu, menu->settings->fr);
        draw_settings(menu, true);
        sfRenderWindow_display(m->window);
        sfRenderWindow_clear(m->window, sfBlack);
    }
}

void display_loop_hover(struct mains *m, struct pnj_monster *p_e,
struct menu *menu, struct map_info *m_i)
{
    menu->mouse = get_pos_mouse_map(menu->window, m);
    display_map(m_i, menu->window);
    draw_pnj(m->window, p_e->pnj);
    draw_enemy_map(m->window, p_e->m_e);
    anim_monster(p_e->m_e);
    anim_pnj(p_e->pnj);
    display_settings(m, p_e, menu, m_i);
    display_dial_pnj(p_e->pnj, menu, m_i, m);
    display_running_game(m);
    create_quest(m->window, act_pos_d(vect(15, 930), m->rect3),
    "\n\tQuest :\n\n\tKill an enemy", m->ih->quest);
    sfRenderWindow_display(m->window);
    sfRenderWindow_clear(m->window, sfBlack);
    analyse_events(m, p_e, menu, m_i);
    if_hit_enemies(p_e, m->player_pos, menu, m);
    if (menu->nb_menu == 1)
        sfRenderWindow_setView(m->window, m->view);
    if (menu->nb_menu == 3)
        display_status(m, menu);
}

int loop_hover_events(struct mains *m, struct pnj_monster *p_e,
struct menu *menu, struct map_info *m_i)
{
    menu->is_game = true;
    fill_last_main(m);
    while (sfRenderWindow_isOpen(menu->window)) {
        display_loop_hover(m, p_e, menu, m_i);
        if (m->ih->load_new_lvl == true) {
            m_i = new_lvl(p_e, menu, m_i, m);
            sfRenderWindow_setView(m->window,
            sfRenderWindow_getDefaultView(m->window));
            end_game(m->window, 0);
            m->ih->load_new_lvl = false;
            sfRenderWindow_setView(m->window, m->view);
        }
        if (menu->is_game == false)
            return (EXIT_SUCCESS);
    }
    return (EXIT_SUCCESS);
}
