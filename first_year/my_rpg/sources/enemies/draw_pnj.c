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

static void help_display_text_pnj(struct pnj *p, struct menu *menu,
struct map_info *m_i, struct mains *m)
{
    sfRenderWindow_setView(m->window,
    sfRenderWindow_getDefaultView(m->window));
    end_game(m->window, 1);
    menu->is_game = false;
}

static void display_text_pnj(struct pnj *p, struct menu *menu,
struct map_info *m_i, struct mains *m)
{
    char a[] = "Your brother is at one of the stage of this dungeon";
    char s[] = "\nKill one enemy of this stage and talk to me to change level";
    char t[] = "\nPress y if you want to go on next stage";
    char e[] = "You find me brother !\n";

    create_dial_bub(m_i, menu->window, m);
    if (m->ih->stage == 8) {
        create_dial_text(m_i, menu->window, e, m);
        m->ih->end = true;
        help_display_text_pnj(p, menu, m_i, m);
        return;
    }
    if (m->ih->can_go_next == false) {
        create_dial_text(m_i, menu->window, a, m);
        create_dial_text(m_i, menu->window, s, m);
        m->ih->quest = true;
        return;
    }
    create_dial_text(m_i, menu->window, t, m);
}

void display_dial_pnj(struct pnj **p, struct menu *menu, struct map_info *m_i,
struct mains *m)
{
    for (int i = 0; p[i] != NULL; i++) {
        if ((pos_is_in_sprite(m->player_pos, p[i]->pos) == 1 ||
        pos_is_in_sprite(vect(m->player_pos.x + 40, m->player_pos.y + 40),
        p[i]->pos) == 1 || pos_is_in_sprite(vect(m->player_pos.x + 40,
        m->player_pos.y), p[i]->pos) == 1 ||
        pos_is_in_sprite(vect(m->player_pos.x, m->player_pos.y + 40),
        p[i]->pos) == 1) && p[i]->alive == true) {
            display_text_pnj(p[i], menu, m_i, m);
            sfSprite_setPosition(p[i]->chara, act_pos_d(vect(1570, 910),
            m->rect3));
            sfRenderWindow_drawSprite(menu->window, p[i]->chara, NULL);
            m->ih->with_pnj = true;
            return;
        }
    }
    m->ih->with_pnj = false;
}

void anim_pnj(struct pnj **e)
{
    for (int i = 0; e[i] != NULL; i++) {
        e[i]->time = sfClock_getElapsedTime(e[i]->clock);
        if (e[i]->time.microseconds > e[i]->speed) {
            sfClock_restart(e[i]->clock);
            move_pnj(e[i]->rect, e, i);
            e[i]->time.microseconds -= e[i]->speed;
            sfSprite_setTextureRect(e[i]->sprite, e[i]->rect[0]);
            e[i]->nb_step++;
        }
        if (e[i]->nb_step >= e[i]->max_step) {
            e[i]->direction = rand_max(e[i]->nb_dir);
            e[i]->nb_step = 0;
        }
    }
}

void draw_pnj(sfRenderWindow *window, struct pnj **e)
{
    for (int i = 0; e[i] != NULL; i++) {
        if (e[i]->alive == true && e[i]->pos.x <= LEN_X &&
        e[i]->pos.y <= LEN_Y && e[i]->pos.x > POS_X && e[i]->pos.y > POS_Y)
            sfRenderWindow_drawSprite(window, e[i]->sprite, NULL);
    }
}
