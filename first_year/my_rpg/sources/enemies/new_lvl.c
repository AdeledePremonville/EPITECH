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
#include <time.h>

struct map_info *new_lvl(struct pnj_monster *p, struct menu *menu,
struct map_info *m_i, struct mains *m)
{
    m->ih->can_go_next = false;
    m->ih->stage += 1;
    for (int i = 0; p->pnj[i] != NULL; i++)
        p->pnj[i]->alive = false;
    if (m->ih->stage != 8)
        p->pnj[m->ih->stage]->alive = true;
    else
        p->pnj[0]->alive = true;
    for (int i = 0; p->m_e[i] != NULL; i++)
        p->m_e[i]->alive = true;
    return fill_map_sp(58, 58, m->ih->stage);
}
