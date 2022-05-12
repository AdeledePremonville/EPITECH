/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu management
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>

void destroy_menu(struct menu *menu)
{
    destroy_music(menu->music);
    destroy_button_s(menu->b_save1);
    destroy_button_s(menu->b_save2);
    destroy_button_s(menu->b_reset1);
    destroy_button_s(menu->b_reset2);
    destroy_button_s(menu->b_settings);
    destroy_button_s(menu->b_leave);
    destroy_settings(menu->settings);
    sfFont_destroy(menu->font);
    sfText_destroy(menu->title);
    sfSprite_destroy(menu->background);
    sfTexture_destroy(menu->t_back);
    sfSprite_destroy(menu->panel);
    sfTexture_destroy(menu->t_panel);
    sfRenderWindow_destroy(menu->window);
    free(menu);
}

sfRenderWindow *create_window(sfRenderWindow *window, int framerate)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfUint32 flag = sfDefaultStyle | sfResize;

    window = sfRenderWindow_create(video_mode, "Window", flag, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return (window);
}

void help_create_menu(struct menu *m)
{
    m->font = sfFont_createFromFile("sprite/menu/police.TTF");
    m->title = create_text(m->font, vect(580, 10), "My_RPG", 220);
    m->background = sfSprite_create();
    m->t_back = sfTexture_createFromFile("sprite/menu/back.png", NULL);
    sfSprite_setTexture(m->background, m->t_back, sfFalse);
    sfSprite_setPosition(m->background, vect(-350, -140));
    m->panel = sfSprite_create();
    m->t_panel = sfTexture_createFromFile("sprite/menu/big_pannel.png", NULL);
    sfSprite_setTexture(m->panel, m->t_panel, sfFalse);
    sfSprite_setPosition(m->panel, vect(120, 250));
    sfSprite_setScale(m->panel, vect(0.88, 0.62));
    m->window = create_window(m->window, 60);
    m->nb_menu = 1;
}

static void create_button_menu(struct menu *m)
{
    m->b_save1 = create_button_s("sprite/menu/disk_blue.png", vect(500, 450),
    vect(0.4, 0.4), vect(0.4, 0.4));
    m->b_save1->has_text = true;
    m->b_save2 = create_button_s("sprite/menu/disk_red.png", vect(1020, 450),
    vect(0.4, 0.4), vect(0.4, 0.4));
    m->b_save2->has_text = true;
    m->b_reset1 = create_button_s("sprite/menu/trash.png", vect(850, 695),
    vect(0.1, 0.1), vect(0.1, 0.1));
    m->b_reset1->has_text = true;
    m->b_reset2 = create_button_s("sprite/menu/trash.png", vect(1370, 695),
    vect(0.1, 0.1), vect(0.1, 0.1));
    m->b_reset2->has_text = true;
    m->b_settings = create_button_s("sprite/menu/settings.png",
    vect(1700, 50), vect(0.1, 0.1), vect(0.1, 0.1));
    m->b_settings->has_text = true;
    m->b_leave = create_button_s("sprite/menu/leave.png",
    vect(1800, 50), vect(0.1, 0.1), vect(0.1, 0.1));
    m->b_leave->has_text = true;
}

struct menu *create_menu(void)
{
    struct menu *m = malloc(sizeof(struct menu) * 1);

    if (m == NULL)
        return NULL;
    m->is_game = false;
    m->music = create_music();
    m->settings = create_settings();
    create_button_menu(m);
    m->b_stat = create_button_s("sprite/game/stat.png",
    vect(1600, 50), vect(0.1, 0.1), vect(0.1, 0.1));
    m->b_stat->has_text = true;
    add_text_button_menu(m);
    if (m->b_save1 == NULL || m->b_save2 == NULL || m->b_reset1 == NULL ||
        m->b_reset2 == NULL || m->b_settings == NULL)
        return NULL;
    help_create_menu(m);
    return m;
}
