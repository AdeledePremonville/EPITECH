/*
** EPITECH PROJECT, 2021
** settings.c
** File description:
** settings management
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>

int help_event_settings(struct menu *m, sfEvent event, struct music_vol *v)
{
    if (if_button_s_pressed(m->settings->b_return, m->window,
        m->mouse, event) == 1) {
        sfSound_play(m->music->button);
        m->nb_menu = 1;
        return 1;
    }
    return 0;
}

int event_settings(struct menu *m, sfEvent event, struct music_vol *v)
{
    return help_event_settings(m, event, v);
}

void draw_settings(struct menu *m, bool in_game)
{
    if (in_game == true) {
        draw_button_s(m->settings->b_save1, m->window, m->mouse);
        draw_button_s(m->settings->b_save2, m->window, m->mouse);
        draw_button_s(m->settings->b_exit, m->window, m->mouse);
    }
    draw_button_s(m->settings->b_return, m->window, m->mouse);
}

void destroy_settings(struct settings *settings)
{
    destroy_button_s(settings->b_save1);
    destroy_button_s(settings->b_save2);
    destroy_button_s(settings->b_exit);
    destroy_button_s(settings->b_return);
    destroy_music_vol(settings->music_vol);
    destroy_frame_rate(settings->fr);
    free(settings);
}

struct settings *create_settings(void)
{
    struct settings *m = malloc(sizeof(struct settings) * 1);

    if (m == NULL)
        return NULL;
    m->b_save1 = create_button_s("sprite/menu/disk_blue.png", vect(900, 330),
    vect(0.2, 0.2), vect(0.2, 0.2));
    m->b_save1->has_text = true;
    m->b_save2 = create_button_s("sprite/menu/disk_red.png", vect(1120, 330),
    vect(0.2, 0.2), vect(0.2, 0.2));
    m->b_save2->has_text = true;
    m->b_exit = create_button_s("sprite/menu/exit.png", vect(1570, 330),
    vect(0.13, 0.13), vect(0.13, 0.13));
    m->b_exit->has_text = true;
    m->b_return = create_button_s("sprite/menu/return.png", vect(260, 330),
    vect(0.13, 0.13), vect(0.13, 0.13));
    m->b_return->has_text = true;
    m->music_vol = create_music_volume();
    m->fr = create_frame_rate();
    add_text_button_settings(m);
    return m;
}
