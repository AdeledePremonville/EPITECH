/*
** EPITECH PROJECT, 2022
** francois_super_code.c
** File description:
** francois_super_code
*/

#include "exit.h"
#include "p.h"
#include <stdlib.h>

void center_sprite(sfVector2f window_size, sfSprite *sprite)
{
    sfFloatRect sprite_size = sfSprite_getLocalBounds(sprite);
    sfVector2f center;

    center.x = window_size.x / 2 - (sprite_size.width / 2);
    center.y = window_size.y / 2 - (sprite_size.height / 2);
    sfSprite_setPosition(sprite, center);
}

void center_sprite_player(struct mains *m)
{
    sfFloatRect sprite_size = sfSprite_getLocalBounds(m->player.sprite);
    sfVector2f center;

    center.x = m->window_size.x / 2;
    center.y = m->window_size.y / 2;
    sfSprite_setPosition(m->player.sprite, center);
}

void initialize_structures(struct mains *m, sfRenderWindow *window,
struct save *s)
{
    m->window = window;
    m->map_size = (sfFloatRect){POS_X, POS_Y, LEN_X, LEN_Y};
    m->window_size = (sfVector2f){1920, 1080};
    m->arrow.left = false;
    m->arrow.up = false;
    m->arrow.right = false;
    m->arrow.down = true;
    m->zoom = 1;
    m->ih = malloc(sizeof(struct info_hero));
    m->ih->life_hero = s->nb_curr_life;
    m->ih->max_life = s->nb_max_life;
    m->ih->attack = s->nb_attack;
    m->ih->lvl = s->nb_lvl;
    m->ih->stage = s->nb_stage;
    m->ih->curr_xp = s->nb_exp;
    m->ih->max_xp = s->nb_max_xp;
    m->ih->nb_pot = s->nb_pot;
    m->ih->nb_big_pot = s->nb_big_pot;
    m->ih->nb_armor = s->nb_armor;
    m->ih->nb_sword = s->nb_sword;
}

void destroy(struct mains *m)
{
    sfView_destroy(m->view);
    sfClock_destroy(m->gettime.clock);
    sfTexture_destroy(m->player.texture);
    sfSprite_destroy(m->player.sprite);
    sfTexture_destroy(m->background.texture);
    sfSprite_destroy(m->background.sprite);
    free(m->ih);
}

int francois_super_code(struct menu *menu, struct save *s)
{
    struct mains m;
    struct pnj_monster pnj_monster;
    struct map_info *m_i = fill_map_sp(58, 58, s->nb_stage);

    if (m_i == NULL)
        return EXIT_ERROR;
    pnj_monster.m_e = create_enemy_map();
    pnj_monster.pnj = create_pnj(s->nb_stage);
    initialize_structures(&m, menu->window, s);
    if (create_assets(&m) == EXIT_ERROR)
        return EXIT_ERROR;
    menu->nb_menu = 1;
    m.player_pos = vect(960, 540);
    if (loop_hover_events(&m, &pnj_monster, menu, m_i) == EXIT_ERROR)
        return EXIT_ERROR;
    destroy(&m);
    destroy_enemy_map(pnj_monster.m_e);
    destroy_pnj(pnj_monster.pnj);
    return 0;
}
