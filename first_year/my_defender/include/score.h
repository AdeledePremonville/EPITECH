/*
** EPITECH PROJECT, 2022
** score.h
** File description:
** score_h - my_defender
*/

#include "menu.h"

#ifndef SCORE_H
    #define SCORE_H

typedef struct score_t
{
    char **scores;
    sfText *title;
    sfFont *pixel;
    sfFont *font;
    sfText *best;
    sfText *score2;
    sfText *score3;
    sfText *score4;
    sfText *score5;
    sfText *first;
    sfText *second;
    sfText *third;
    sfText *fourth;
    sfText *fifth;
    sfSprite *back;
    sfSprite *square;
    sfSound *sound;
    sfSoundBuffer *buffer;
} score_t;

typedef struct buf_t
{
    char *new_score;
    char *buffer;
    char **scores;
    int len;
    int zeros;
    int k;
    int i;
    int j;
} buf_t;

void score_menu(sfRenderWindow *window);

char *fs_open_file(char *filepath);

score_t *init_score_struct();

void events_score(sfRenderWindow *window, sfEvent event, score_t *obj);

int nb_words(char *str, char delim);

void fill_word_array(char **res, char delim, char *str, char delim2);

void init_score_t(score_t *obj);

void draw_score_t(score_t *obj, sfRenderWindow *window);

char **str_to_word_array(char *str, char delim);

sfText *init_score_text(sfVector2f pos, char *str);

void free_score(score_t *obj);

int my_getnbr(char const *str);

int check_score(int nb);

void fill_score(buf_t *buf);

int check_score(int nb);

#endif /* !SCORE_H */
