/*
** EPITECH PROJECT, 2022
** building.c
** File description:
** building menu - my_defender
*/

#include "struct.h"
#include "how_to.h"
#include "menu.h"
#include "pause.h"
#include "building.h"

sfSprite *init_square(sfVector2f pos)
{
    sfSprite *square = create_sprite("images/square-button.png");

    sfSprite_setPosition(square, pos);
    sfSprite_setScale(square, (sfVector2f){1.4, 1.4});
    return square;
}

sfText *init_price(char *price, sfVector2f pos)
{
    sfFont *font = sfFont_createFromFile("images/text/text.ttf");
    sfText *text = sfText_create();

    sfText_setString(text, price);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setScale(text, (sfVector2f){2.2, 2.2});
    sfText_setPosition(text, pos);
    return text;
}

sfSprite *init_coin(sfVector2f pos)
{
    sfSprite *coin = create_sprite("images/coin");

    sfSprite_setScale(coin, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(coin, pos);
    return coin;
}

void events_building(struct defender *def, sfEvent event, build_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_back = sfSprite_getPosition(obj->back);

    if (event.type == sfEvtClosed) {
        free_building(obj, def);
        sfRenderWindow_close(obj->window);
    }
    if (event.type == sfEvtMouseButtonPressed && pos.y >= co_back.y &&
        pos.y <= co_back.y + 200 && pos.x >= co_back.x &&
        pos.x <= co_back.x + 400) {
            sfSound_play(obj->sound);
            menu(obj->window, 1);
            free_building(obj, def);
    }
}

void building_menu(sfRenderWindow *window)
{
    struct defender *def = malloc(sizeof(struct defender));
    build_t *obj = init_struct_build(window);
    sfEvent event;

    init_buildings(obj);
    sprite_init(def);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, def->sprite_map, NULL);
        draw_building(obj, window);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            events_building(def, event, obj);
    }
}