/*
** EPITECH PROJECT, 2022
** francois_super_code.c
** File description:
** francois_super_code
*/

#include "p.h"
#include "game.h"
#include <stdlib.h>

void destroy_stat(struct status *s)
{
    destroy_button_s(s->b_return);
    sfFont_destroy(s->font);
    sfText_destroy(s->title);
    sfText_destroy(s->inventory);
    destroy_text_nb(s->stage);
    destroy_text_nb(s->lvl);
    destroy_text_nb(s->ad);
    destroy_text_nb_max(s->hp);
    destroy_text_nb_max(s->xp);
    sfSprite_destroy(s->chara);
    sfTexture_destroy(s->text_chara);
    free(s->rect);
    free(s);
}

void draw_stat(struct menu *m, sfRenderWindow *w, struct status *s)
{
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_drawSprite(w, m->background, NULL);
    draw_button_s(s->b_return, w, m->mouse);
    sfRenderWindow_drawSprite(w, s->chara, NULL);
    sfRenderWindow_drawText(w, s->title, NULL);
    sfRenderWindow_drawText(w, s->inventory, NULL);
    draw_text_nb(s->stage, w);
    draw_text_nb(s->lvl, w);
    draw_text_nb(s->ad, w);
    draw_text_nb_max(s->hp, w);
    draw_text_nb_max(s->xp, w);
    draw_button_s(s->b_pot, w, m->mouse);
    draw_button_s(s->b_big_pot, w, m->mouse);
    draw_button_s(s->b_armor, w, m->mouse);
    draw_button_s(s->b_sword, w, m->mouse);
    sfRenderWindow_display(w);
    sfRenderWindow_clear(w, sfBlack);
}

void help_create_status(struct mains *m, struct menu *menu, struct status *s)
{
    s->xp = create_text_max_nb("number experience :",
    vecti(m->ih->curr_xp, m->ih->max_xp), s->font, vect(100, 700));
    s->chara = sfSprite_create();
    s->text_chara = sfTexture_createFromFile("sprite/game/face.png", NULL);
    sfSprite_setTexture(s->chara, s->text_chara, sfFalse);
    s->rect = create_int_rect(s->rect, 0, 140);
    sfSprite_setTextureRect(s->chara, s->rect[0]);
    sfSprite_setPosition(s->chara, vect(760, 320));
    s->b_pot = create_button_s("sprite/game/potion.png", vect(1000, 300),
    vect(0.2, 0.2), vect(0.2, 0.2));
    s->b_pot->has_text = true;
    s->b_big_pot = create_button_s("sprite/game/big_pot.png", vect(1200, 300),
    vect(0.2, 0.2), vect(0.2, 0.2));
    s->b_big_pot->has_text = true;
    s->b_armor = create_button_s("sprite/game/shield.png", vect(1400, 300),
    vect(0.2, 0.2), vect(0.2, 0.2));
    s->b_armor->has_text = true;
    s->b_sword = create_button_s("sprite/game/sword.png", vect(1600, 300),
    vect(0.2, 0.2), vect(0.2, 0.2));
    s->b_sword->has_text = true;
}

struct status *create_status(struct mains *m, struct menu *menu)
{
    struct status *status = malloc(sizeof(struct status));

    status->b_return = create_button_s("sprite/menu/return.png",
    vect(1800, 50), vect(0.1, 0.1), vect(0.1, 0.1));
    status->b_return->has_text = false;
    status->font = sfFont_createFromFile("sprite/menu/police.TTF");
    status->title = create_text(status->font, vect(200, 10), "STATUS", 180);
    status->inventory = create_text(status->font, vect(1000, 10),
    "Inventory", 180);
    status->stage = create_text_nb("         number room :",
    m->ih->stage, status->font, vect(100, 300));
    status->lvl = create_text_nb("         number level :", m->ih->lvl,
    status->font, vect(100, 400));
    status->ad = create_text_nb("       number attack :", m->ih->attack,
    status->font, vect(100, 500));
    status->hp = create_text_max_nb("            number life :",
    vecti(m->ih->life_hero, m->ih->max_life), status->font, vect(100, 600));
    help_create_status(m, menu, status);
    add_text_button_status(status, m);
    return status;
}

void display_status(struct mains *m, struct menu *menu)
{
    struct status *s = create_status(m, menu);

    sfSound_play(menu->music->button);
    sfRenderWindow_setView(m->window,
    sfRenderWindow_getDefaultView(m->window));
    while (menu->nb_menu == 3) {
        draw_stat(menu, menu->window, s);
        while (sfRenderWindow_pollEvent(m->window, &m->event))
            event_status(m, menu, s);
    }
    sfRenderWindow_setView(m->window, m->view);
}
