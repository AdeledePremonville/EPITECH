/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw- my_defender
*/

#include "struct.h"
#include "menu.h"
#include "pause.h"
#include "building.h"
#include "how_to.h"

void draw_building(build_t *obj, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, obj->square, NULL);
    sfRenderWindow_drawSprite(window, obj->square2, NULL);
    sfRenderWindow_drawSprite(window, obj->square3, NULL);
    sfRenderWindow_drawSprite(window, obj->square4, NULL);
    sfRenderWindow_drawSprite(window, obj->wall, NULL);
    sfRenderWindow_drawSprite(window, obj->roblox, NULL);
    sfRenderWindow_drawText(window, obj->building, NULL);
    sfRenderWindow_drawText(window, obj->price, NULL);
    sfRenderWindow_drawText(window, obj->price2, NULL);
    sfRenderWindow_drawText(window, obj->price3, NULL);
    sfRenderWindow_drawText(window, obj->price4, NULL);
    sfRenderWindow_drawSprite(window, obj->back, NULL);
    sfRenderWindow_drawSprite(window, obj->tesla, NULL);
    sfRenderWindow_drawSprite(window, obj->sniper, NULL);
    sfRenderWindow_drawSprite(window, obj->coin, NULL);
    sfRenderWindow_drawSprite(window, obj->coin2, NULL);
    sfRenderWindow_drawSprite(window, obj->coin3, NULL);
    sfRenderWindow_drawSprite(window, obj->coin4, NULL);
}

void init_buildings(build_t *obj)
{
    sfText_setString(obj->building, "BUILDINGS");
    sfText_setColor(obj->building, sfBlack);
    sfText_setPosition(obj->building, (sfVector2f){500, 100});
    sfText_setScale(obj->building, (sfVector2f){2.5, 2.5});
    sfText_setFont(obj->building, obj->pixel);
    sfSprite_setPosition(obj->back, (sfVector2f){-150, 0});
    sfSprite_setScale(obj->back, (sfVector2f){0.9, 0.9});
    sfSprite_setScale(obj->wall, (sfVector2f){1.3, 1.3});
    sfSprite_setPosition(obj->wall, (sfVector2f){275, 430});
    sfSprite_setPosition(obj->roblox, (sfVector2f){1525, 430});
    sfSprite_setScale(obj->roblox, (sfVector2f){1.8, 1.8});
    sfSprite_setPosition(obj->tesla, (sfVector2f){670, 430});
    sfSprite_setScale(obj->tesla, (sfVector2f){1.8, 1.8});
    sfSprite_setPosition(obj->sniper, (sfVector2f){1100, 450});
    sfSprite_setScale(obj->sniper, (sfVector2f){1.8, 1.8});
    sfSound_setBuffer(obj->sound, obj->buffer);
}

void init_struct_build2(build_t *obj)
{
    obj->wall = create_sprite("images/wall");
    obj->roblox = create_sprite("images/roblox");
    obj->tesla = create_sprite("images/tesla");
    obj->sniper = create_sprite("images/sniper");
    obj->coin = init_coin((sfVector2f){320, 710});
    obj->coin2 = init_coin((sfVector2f){795, 710});
    obj->coin3 = init_coin((sfVector2f){1255, 710});
    obj-> coin4 = init_coin((sfVector2f){1705, 710});
    obj->sound = sfSound_create();
    obj->buffer = sfSoundBuffer_createFromFile("sound/fart.wav");
}

build_t *init_struct_build(sfRenderWindow *window)
{
    build_t *obj = malloc(sizeof(build_t));

    obj->square = init_square((sfVector2f){100, 400});
    obj->square2 = init_square((sfVector2f){550, 400});
    obj->square3 = init_square((sfVector2f){1000, 400});
    obj->square4 = init_square((sfVector2f){1450, 400});
    obj->building = sfText_create();
    obj->pixel = sfFont_createFromFile("images/pixelmania/Pixelmania.ttf");
    obj->price = init_price("70", (sfVector2f){250, 690});
    obj->price2 = init_price("150", (sfVector2f){700, 690});
    obj->price3 = init_price("250", (sfVector2f){1150, 690});
    obj->price4 = init_price("400", (sfVector2f){1600, 690});
    obj->back = create_sprite("images/back_button.png");
    obj->window = window;
    init_struct_build2(obj);
    return obj;
}

void free_building(build_t *obj, struct defender *def)
{
    sfSprite_destroy(obj->wall);
    sfSprite_destroy(obj->roblox);
    sfSprite_destroy(obj->tesla);
    sfSprite_destroy(obj->sniper);
    sfSprite_destroy(obj->coin);
    sfSprite_destroy(obj->coin2);
    sfSprite_destroy(obj->coin3);
    sfSprite_destroy(obj->coin4);
    sfSprite_destroy(obj->square);
    sfSprite_destroy(obj->square2);
    sfSprite_destroy(obj->square3);
    sfSprite_destroy(obj->square4);
    sfFont_destroy(obj->pixel);
    sfSprite_destroy(obj->back);
    free_def(def);
    sfSound_destroy(obj->sound);
    sfSoundBuffer_destroy(obj->buffer);
}