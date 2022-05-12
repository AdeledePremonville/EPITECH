/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** menu .h
*/

#ifndef _MENU_H
    #define _MENU_H

    #include "p.h"
    #define RED 1
    #define GREEN 2
    #define BLUE 3
    #define YELLOW 4
    #define MAGENTA 5
    #define CYAN 6
    #define BLACK 7

struct info_button {
    sfText *text;
    sfFont *font;
    sfSprite *info;
    sfTexture *t_info;
    sfVector2f pos_info;
};

struct button_s {
    struct info_button *info;
    sfSprite *sign;
    sfSprite *panel;
    sfTexture *t_sign;
    sfTexture *t_panel;
    sfVector2f pos_sign;
    sfVector2f pos_panel;
    sfVector2f size_panel;
    sfVector2f scale_sign;
    sfVector2f scale_panel;
    sfClock *clock;
    sfTime time;
    bool has_text;
    int is_pressed;
};

struct button {
    sfText *text;
    sfFont *font;
    sfRectangleShape *rect;
    sfVector2f pos_t;
    sfVector2f pos;
    sfVector2f size;
    sfClock *clock;
    sfTime time;
    int is_pressed;
};

struct music_vol {
    int vol;
    struct button_s *b_up;
    struct button_s *b_down;
    sfText *title;
    sfFont *font;
    sfRectangleShape **rect;
};

struct frame_rate {
    int frame_rate;
    char *nb_frame_rate;
    struct button_s *b_up;
    struct button_s *b_down;
    sfText *text;
    sfText *title;
    sfFont *font;
};

struct settings {
    struct button_s *b_save1;
    struct button_s *b_save2;
    struct button_s *b_exit;
    struct button_s *b_return;
    struct music_vol *music_vol;
    struct frame_rate *fr;
};

struct music_menu {
    sfSound *button;
    sfSoundBuffer *buff_button;
    sfMusic *menu;
};

struct menu {
    struct music_menu *music;
    struct button_s *b_save1;
    struct button_s *b_save2;
    struct button_s *b_reset1;
    struct button_s *b_reset2;
    struct button_s *b_settings;
    struct button_s *b_leave;
    struct button_s *b_stat;
    struct settings *settings;
    sfText *title;
    sfFont *font;
    sfSprite *background;
    sfTexture *t_back;
    sfSprite *panel;
    sfTexture *t_panel;
    sfRenderWindow *window;
    sfVector2i mouse;
    int nb_menu;
    bool is_game;
};

// menu_rpg
int menu_rpg(int ac, char **av);
int check_music_fr(struct menu *m, sfEvent event, struct music_vol *v);

// menu
void destroy_menu(struct menu *menu);
sfRenderWindow *create_window(sfRenderWindow *window, int framerate);
struct menu *create_menu(void);

// sound_volume
struct music_vol *create_music_volume(void);
void destroy_music_vol(struct music_vol *m);
void draw_music_volume(struct menu *m, struct music_vol *m_vol);
void refresh_vol(struct music_vol *mv, int up, struct music_menu *music);

// frame_rate
struct frame_rate *create_frame_rate(void);
void destroy_frame_rate(struct frame_rate *f_r);
void refresh_frame_rate(int up, struct menu *m, struct music_menu *music);
void draw_frame_rate(struct menu *m, struct frame_rate *fr);
void check_fr(struct menu *m, sfEvent event, struct music_vol *v);

// create_destroy_music
void destroy_music(struct music_menu *music);
struct music_menu *create_music(void);

// button_sprite
struct button_s *create_button_s(char *path_sprite, sfVector2f pos,
sfVector2f scale_sign, sfVector2f scale_panel);
void draw_button_s(struct button_s *b, sfRenderWindow *wind, sfVector2i mouse);
int if_button_s_pressed(struct button_s *b, sfRenderWindow *wind,
sfVector2i mouse, sfEvent event);

// info_button
void destroy_button_s(struct button_s *button);
void destroy_info_button(struct info_button *i);
struct info_button *create_info_button(sfVector2f pos, sfVector2f scale,
char *path_sprite);
void add_text_info(struct button_s *b, char *str, int size, sfVector2f pos);
void destroy_sprite(sfSprite *sprite, sfTexture *texture);

//button
struct button *create_button(sfVector2f size, sfVector2f pos, char *s, int co);
void start_press(struct button *b);
void destroy_button(struct button *button);
void draw_button(struct button *b, sfRenderWindow *wind, sfVector2i mouse);

// settings
struct settings *create_settings(void);
void destroy_settings(struct settings *settings);
void draw_settings(struct menu *m, bool in_game);
int event_settings(struct menu *m, sfEvent event, struct music_vol *v);

// add_text_button_game
void add_text_button_settings(struct settings *s);
void add_text_button_menu(struct menu *menu);

#endif
