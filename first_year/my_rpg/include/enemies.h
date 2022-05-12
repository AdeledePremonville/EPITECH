/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** menu .h
*/

#ifndef _ENEMIES_H
    #define _ENEMIES_H

    #include "p.h"

// enemies.c
struct enemy_map **create_enemy_map(void);
void destroy_enemy_map(struct enemy_map **e);
int rand_int(int min, int max);
int rand_max(int max);

// draw_enemies.c
void draw_enemy_map(sfRenderWindow *window, struct enemy_map **e);
void anim_monster(struct enemy_map **e);

// colli_enemies.c
void if_hit_enemies(struct pnj_monster *p, sfVector2f pos, struct menu *m,
struct mains *main);
int pos_is_in_sprite(sfVector2f pos, sfVector2f pos_sprite);

// pnj.c
struct pnj **create_pnj(int stage);
void destroy_pnj(struct pnj **p);

// draw_pnj.c
void anim_pnj(struct pnj **e);
void draw_pnj(sfRenderWindow *window, struct pnj **e);

// mov_pnj.c
void move_pnj(sfIntRect *rect, struct pnj **e, int i);
void display_dial_pnj(struct pnj **p, struct menu *menu, struct map_info *m_i,
struct mains *main);

// new_lvl.c
struct map_info *new_lvl(struct pnj_monster *p, struct menu *menu,
struct map_info *m_i, struct mains *m);
void kill_an_enemy(struct mains *m, struct menu *menu);

#endif
