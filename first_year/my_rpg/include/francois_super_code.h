/*
** EPITECH PROJECT, 2022
** francois_super_code.h
** File description:
** francois_super_code
*/

#ifndef FRANCOIS_SUPER_CODE_H_
    #define FRANCOIS_SUPER_CODE_H_

    #include "p.h"
    #include "game.h"

    #define LEN_X 2270
    #define LEN_Y 1915
    #define POS_X -390
    #define POS_Y -765

int francois_super_code(struct menu *menu, struct save *s);

// loop_display
int loop_hover_events(struct mains *m, struct pnj_monster *p_m,
struct menu *menu, struct map_info *m_i);
void display_player_running_animation(struct mains *m);
void display_running_game(struct mains *m);

// loop_events
void manage_arrows_pressed(struct mains *m);
void analyse_events(struct mains *m, struct pnj_monster *p,
struct menu *menu, struct map_info *m_i);

// calc_error
sfVector2f act_pos(sfVector2f pos, sfIntRect rect, sfSprite *sprite);
sfVector2i  get_pos_mouse_map(sfRenderWindow *window, struct mains *m);
void act_pos_b(sfVector2f pos, sfIntRect rect, struct button_s *b);
sfVector2f act_pos_d(sfVector2f pos, sfIntRect rect);

int create_assets(struct mains *m);
void animate_player(struct mains *m);
void center_sprite(sfVector2f window_size, sfSprite *sprite);
void center_sprite_player(struct mains *m);
int create_clock(struct gettimes *gettime);
void move_player(struct mains *m);
void move_rect(struct mains *m);

// create_status
void display_status(struct mains *m, struct menu *menu);
void destroy_stat(struct status *s);

// create_text_nb
void act_text_nb_max(struct text_nb_max *t, int nb_curr, int nb_max);
void act_text_nb(struct text_nb *t, int nb);
struct text_nb *create_text_nb(char *text, int nb, sfFont *font,
sfVector2f pos);
struct text_nb_max *create_text_max_nb(char *text, sfVector2i nb,
sfFont *font, sfVector2f pos);

// destroy_text_nb
void destroy_text_nb(struct text_nb *t);
void destroy_text_nb_max(struct text_nb_max *t);
void draw_text_nb(struct text_nb *t, sfRenderWindow *window);
void draw_text_nb_max(struct text_nb_max *t, sfRenderWindow *window);

// event status
void event_status(struct mains *m, struct menu *menu, struct status *s);
struct save *fill_struct_save(struct mains *m);
void manage_keys_pressed(struct mains *m, struct menu *menu);
void fill_last_main(struct mains *m);

#endif
