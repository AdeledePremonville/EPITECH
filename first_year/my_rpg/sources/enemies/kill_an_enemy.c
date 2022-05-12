/*
** EPITECH PROJECT, 2021
** menu_rpg.c
** File description:
** menu for rpg
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>

static void help_kill_an_enemy(struct mains *m, struct menu *menu, int rand)
{
    if (rand == 3) {
        if (m->ih->nb_sword < 10) {
            m->ih->nb_sword += 1;
            m->ih->attack += NB_ATK_SWORD;
        }
    }
    m->ih->curr_xp += 1;
    if (m->ih->curr_xp >= m->ih->max_xp) {
        m->ih->lvl += 1;
        m->ih->curr_xp = 0;
        m->ih->max_xp += 1;
        m->ih->max_life += HP_LVL_HERO;
        m->ih->life_hero += HP_LVL_HERO;
        m->ih->attack += ATK_LVL_HERO;
        m->ih->start_lvl_up = true;
        m->ih->lvl_up = true;
    }
}

void kill_an_enemy(struct mains *m, struct menu *menu)
{
    int rand = rand_max(3);

    if (rand == 0 || rand != 1) {
        if (m->ih->nb_pot < 3) {
            m->ih->nb_pot += 1;
        }
    }
    if (rand == 1) {
        if (m->ih->nb_big_pot < 3)
            m->ih->nb_big_pot += 1;
    }
    if (rand == 2) {
        if (m->ih->nb_armor < 10) {
            m->ih->nb_armor += 1;
            m->ih->max_life += NB_HP_ARMOR;
        }
    }
    help_kill_an_enemy(m, menu, rand);
}
