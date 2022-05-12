/*
** EPITECH PROJECT, 2022
** building.h
** File description:
** building_h - my_defender
*/

#ifndef BUILDING_H
    #define BUILDING_H

typedef struct build_t
{
    sfRenderWindow *window;
    sfSprite *wall;
    sfSprite *roblox;
    sfSprite *tesla;
    sfSprite *sniper;
    sfSprite *coin;
    sfSprite *coin2;
    sfSprite *coin3;
    sfSprite *coin4;
    sfSprite *square;
    sfSprite *square2;
    sfSprite *square3;
    sfSprite *square4;
    sfText *building;
    sfFont *pixel;
    sfText *price;
    sfText *price2;
    sfText *price3;
    sfText *price4;
    sfSprite *back;
    sfSound *sound;
    sfSoundBuffer *buffer;
} build_t;

void events_building(struct defender *def, sfEvent event, build_t *obj);

void building_menu(sfRenderWindow *window);

sfText *init_price(char *price, sfVector2f pos);

sfSprite *init_square(sfVector2f pos);

void draw_building(build_t *obj, sfRenderWindow *window);

void init_buildings(build_t *obj);

void init_struct_build2(build_t *obj);

build_t *init_struct_build(sfRenderWindow *window);

void free_building(build_t *obj, struct defender *def);

sfSprite *init_coin(sfVector2f pos);

#endif /* !BUILDING_H */
