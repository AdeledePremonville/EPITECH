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

int pos_is_in_sprite(sfVector2f pos, sfVector2f pos_sprite)
{
    if (pos.x > pos_sprite.x && pos.y > pos_sprite.y &&
        pos.x < (pos_sprite.x + 40) &&
        pos.y < (pos_sprite.y + 40))
        return 1;
    return 0;
}

static struct param_fight fill_param_fight(struct mains *main, int i)
{
    struct param_fight p;

    p.nb_pot_100hp = main->ih->nb_pot;
    p.nb_pot_200hp = main->ih->nb_big_pot;
    p.chara_max_hp = main->ih->life_hero;
    p.chara_attack = main->ih->attack;
    p.max_hp = main->ih->max_life;
    p.enemy = i;
    if (i == 0) {
        p.enemy_max_hp = HP_BAT + ((main->ih->stage - 1) * HP_LVL_BAT);
        p.enemy_attack = ATK_BAT + ((main->ih->stage - 1) * ATK_LVL_BAT);
    }
    if (i == 1) {
        p.enemy_max_hp = HP_SLIME + ((main->ih->stage - 1) * HP_LVL_SLIME);
        p.enemy_attack = ATK_SLIME + ((main->ih->stage - 1) * ATK_LVL_SLIME);
    }
    if (i == 2) {
        p.enemy_max_hp = HP_GOB + ((main->ih->stage - 1) * HP_LVL_GOB);
        p.enemy_attack = ATK_GOB + ((main->ih->stage - 1) * ATK_LVL_GOB);
    }
    return p;
}

void lost_fight(struct pnj_monster *p, struct mains *main, int i,
struct menu *m)
{
    sfRenderWindow_setView(m->window,
    sfRenderWindow_getDefaultView(m->window));
    end_game(m->window, 2);
    m->is_game = false;
}

void call_fight(struct pnj_monster *p, struct mains *main, int i,
struct menu *m)
{
    struct param_fight param = fill_param_fight(main, i);
    int res = start_fight(m->window, &param, &main->ih->life_hero);

    if (res == WIN) {
        p->m_e[i]->alive = false;
        main->ih->can_go_next = true;
        main->ih->quest = false;
        main->ih->nb_pot = param.nb_pot_100hp;
        main->ih->nb_big_pot = param.nb_pot_200hp;
        kill_an_enemy(main, m);
        return;
    }
    if (res == LOSE)
        return lost_fight(p, main, i, m);
    main->ih->nb_pot = param.nb_pot_100hp;
    main->ih->nb_big_pot = param.nb_pot_200hp;
    p->m_e[i]->pos = vect(p->m_e[i]->pos.x + 100, p->m_e[i]->pos.y + 100);
    sfSprite_setPosition(p->m_e[i]->sprite, p->m_e[i]->pos);
}

void if_hit_enemies(struct pnj_monster *p, sfVector2f pos, struct menu *m,
struct mains *main)
{
    for (int i = 0; p->m_e[i] != NULL; i++) {
        if ((pos_is_in_sprite(pos, p->m_e[i]->pos) == 1 ||
        pos_is_in_sprite(vect(pos.x + 40, pos.y + 40), p->m_e[i]->pos) == 1
        || pos_is_in_sprite(vect(pos.x + 40, pos.y), p->m_e[i]->pos) == 1 ||
        pos_is_in_sprite(vect(pos.x, pos.y + 40), p->m_e[i]->pos) == 1) &&
        p->m_e[i]->alive == true) {
            sfRenderWindow_setView(m->window,
            sfRenderWindow_getDefaultView(m->window));
            sfMusic_stop(m->music->menu);
            call_fight(p, main, i, m);
            sfMusic_play(m->music->menu);
        }
    }
}
