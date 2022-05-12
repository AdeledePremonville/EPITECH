/*
** EPITECH PROJECT, 2022
** create_assets.c
** File description:
** create_assets
*/

#include "exit.h"
#include "francois_super_code.h"
#include <stdio.h>

void create_rect_player_sprites(struct mains *m)
{
    sfFloatRect sprite_size = sfSprite_getLocalBounds(m->player.sprite);

    m->sprites_nb.x = 3;
    m->sprites_nb.y = 4;
    m->rect2.top = 0;
    m->rect2.left = 0;
    m->rect2.width = sprite_size.width / 12;
    m->rect2.height = sprite_size.height / 8;
    m->rect1.top = 0;
    m->rect1.left = 0;
    m->rect1.width = m->rect2.width * m->sprites_nb.x;
    m->rect1.height = m->rect2.height * m->sprites_nb.y;
}

int create_player(struct mains *m)
{
    char *img = "sprite/perso_principal/player.png";

    m->player.sprite = sfSprite_create();
    m->player.texture = sfTexture_createFromFile(img, NULL);
    if (!m->player.texture)
        return EXIT_ERROR;
    sfSprite_setTexture(m->player.sprite, m->player.texture, sfFalse);
    create_rect_player_sprites(m);
    sfSprite_setTextureRect(m->player.sprite, m->rect1);
    center_sprite_player(m);
    return EXIT_SUCCESS;
}

int create_background(struct mains *m)
{
    char *img = "sprite/perso_principal/bg_tmp.jpg";

    m->background.sprite = sfSprite_create();
    m->background.texture = sfTexture_createFromFile(img, NULL);
    if (!m->background.texture)
        return EXIT_ERROR;
    sfSprite_setTexture(m->background.sprite, m->background.texture, sfFalse);
    return EXIT_SUCCESS;
}

int create_view(struct mains *m)
{
    sfFloatRect view_rect = {0, 0, m->window_size.x, m->window_size.y};
    sfVector2f center = {view_rect.width / 2, view_rect.height / 2};

    m->view = sfView_createFromRect(view_rect);
    sfView_setCenter(m->view, center);
    sfView_zoom(m->view, 1 / m->zoom);
    sfRenderWindow_setView(m->window, m->view);
    m->rect3.left = center.x - 100 * 1 / m->zoom;
    m->rect3.top = center.y - 100 * 1 / m->zoom;
    m->rect3.width = 200 * 1 / m->zoom;
    m->rect3.height = 200 * 1 / m->zoom;
    return EXIT_SUCCESS;
}

int create_assets(struct mains *m)
{
    if (create_view(m) == EXIT_ERROR)
        return (EXIT_ERROR);
    if (create_clock(&m->gettime) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_clock(&m->gettime_move) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_background(m) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_player(m) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
