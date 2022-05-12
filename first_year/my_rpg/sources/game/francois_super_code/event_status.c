/*
** EPITECH PROJECT, 2022
** francois_super_code.c
** File description:
** francois_super_code
*/

#include "p.h"
#include "game.h"
#include <stdlib.h>

void help_event_status(struct mains *m, struct menu *menu, struct status *s)
{
    if (m->event.type == sfEvtClosed) {
        sfRenderWindow_close(menu->window);
        menu->nb_menu = 1;
    }
}

void event_status(struct mains *m, struct menu *menu, struct status *s)
{
    if (if_button_s_pressed(s->b_return, menu->window,
        menu->mouse, m->event) == 1)
        menu->nb_menu = 1;
    if (if_button_s_pressed(s->b_pot, menu->window,
        menu->mouse, m->event) == 1 && m->ih->nb_pot > 0) {
        m->ih->nb_pot -= 1;
        m->ih->life_hero += HEAL_POT;
        if (m->ih->max_life < m->ih->life_hero)
            m->ih->life_hero = m->ih->max_life;
        menu->nb_menu = 1;
    }
    if (if_button_s_pressed(s->b_big_pot, menu->window,
        menu->mouse, m->event) == 1 && m->ih->nb_big_pot > 0) {
        m->ih->nb_big_pot -= 1;
        m->ih->life_hero += HEAL_BIG_POT;
        if (m->ih->max_life < m->ih->life_hero)
            m->ih->life_hero = m->ih->max_life;
        menu->nb_menu = 1;
    }
    help_event_status(m, menu, s);
}
