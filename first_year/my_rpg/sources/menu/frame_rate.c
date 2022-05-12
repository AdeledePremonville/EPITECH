/*
** EPITECH PROJECT, 2021
** frame_rate.c
** File description:
** fct frame_rate management
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>

void check_fr(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (if_button_s_pressed(m->settings->fr->b_down, m->window,
        m->mouse, event) == 1) {
        refresh_frame_rate(-5, m, m->music);
    }
    if (if_button_s_pressed(m->settings->fr->b_up, m->window,
        m->mouse, event) == 1) {
        refresh_frame_rate(5, m, m->music);
    }
}

void draw_frame_rate(struct menu *m, struct frame_rate *fr)
{
    draw_button_s(fr->b_up, m->window, m->mouse);
    draw_button_s(fr->b_down, m->window, m->mouse);
    sfRenderWindow_drawText(m->window, fr->text, NULL);
    sfRenderWindow_drawText(m->window, fr->title, NULL);
}

void destroy_frame_rate(struct frame_rate *fr)
{
    free(fr->nb_frame_rate);
    destroy_button_s(fr->b_up);
    destroy_button_s(fr->b_down);
    sfFont_destroy(fr->font);
    sfText_destroy(fr->title);
    sfText_destroy(fr->text);
    free(fr);
}

void refresh_frame_rate(int up, struct menu *m, struct music_menu *music)
{
    sfSound_play(music->button);
    m->settings->fr->frame_rate += up;
    if (m->settings->fr->frame_rate < 5)
        m->settings->fr->frame_rate = 5;
    if (m->settings->fr->frame_rate > 200)
        m->settings->fr->frame_rate = 200;
    free(m->settings->fr->nb_frame_rate);
    m->settings->fr->nb_frame_rate = int_to_str(m->settings->fr->frame_rate);
    sfText_setString(m->settings->fr->text, m->settings->fr->nb_frame_rate);
    sfRenderWindow_setFramerateLimit(m->window, m->settings->fr->frame_rate);
}

struct frame_rate *create_frame_rate(void)
{
    struct frame_rate *fr = malloc(sizeof(struct frame_rate) * 1);
    int up = 0;
    int x = 0;

    if (fr == NULL)
        return NULL;
    fr->b_down = create_button_s("sprite/menu/minus.png", vect(900, 700),
    vect(0.1, 0.1), vect(0.1, 0.1));
    fr->b_down->has_text = false;
    fr->b_up = create_button_s("sprite/menu/plus.png", vect(1280, 700),
    vect(0.1, 0.1), vect(0.1, 0.1));
    fr->b_up->has_text = false;
    if (fr->b_down == NULL || fr->b_up == NULL)
        return NULL;
    fr->frame_rate = 60;
    fr->nb_frame_rate = int_to_str(fr->frame_rate);
    fr->font = sfFont_createFromFile("sprite/menu/police.TTF");
    fr->text = create_text(fr->font, vect(1060, 670), "60", 120);
    fr->title = create_text(fr->font, vect(368, 690), "Frame rate :", 70);
    return fr;
}
