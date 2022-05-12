/*
** EPITECH PROJECT, 2021
** p.h
** File description:
** project .h
*/

#ifndef _P_H
    #define _P_H

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

    #include "game.h"
    #include "fight.h"
    #include "menu.h"
    #include "map.h"
    #include "enemies.h"
    #include "francois_super_code.h"

// save
int clear_save(int nb_save);
int save_data(int nb_save, struct save *save);
struct save *load_save(int nb_save);
int read_file(int fd, char **buffer, int size);
int get_file_data(char const *filepath, char **buffer);
void start_load(struct menu *m, sfEvent event, struct music_vol *v, int save);

// rpg
int rpg(int ac, char **av);
void add_text_button_status(struct status *s, struct mains *m);

// file_in_str
char *file_in_str(char *pathname);
char **file_in_array(char *pathname);

// check_colli
int pos_is_inrect(sfVector2i pos, sfVector2f size_rec, sfVector2f pos_rec);

// create_text_rect_vect
sfText *create_text(sfFont *font, sfVector2f pos, char *str, int size);
sfVector2f vect(float x, float y);
sfVector2i vecti(int x, int y);
sfRectangleShape *create_rect(sfVector2f size, sfVector2f pos, int color);
sfIntRect *create_int_rect(sfIntRect *rect, int x, int y);
void set_pos_button_s(struct button_s *b, sfVector2f pos);
int rand_one_or_two(void);

//logic
int level_up(sfRenderWindow *win, sfVector2f pos);
void create_quest(sfRenderWindow *win, sfVector2f pos, char *str, int display);
int end_game(sfRenderWindow *win, int ending);

#endif
