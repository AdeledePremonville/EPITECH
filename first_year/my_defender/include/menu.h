/*
** EPITECH PROJECT, 2022
** menu.h
** File description:
** menu page h - mydefender
    sfClock *clock = sfClock_create();
    sfTime wait = sfClock_getElapsedTime(clock);
*/

#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <stdlib.h>

#ifndef MENU_H
    #define MENU_H

typedef struct obj_t
{
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *button_start;
    sfSprite *button_exit;
    sfSprite *button_how;
    sfSprite *button_buildings;
    sfSprite *button_score;
    sfIntRect button_rect;
    sfIntRect button_click_rect;
    sfIntRect hover_rect;
    int state;
    sfSound *sound;
} obj_t;

typedef struct text_t
{
    sfText *text;
    sfFont *font;
    sfColor color;
    sfVector2f scale;
    char *string;
    sfVector2f position;
} text_t;

typedef struct scale_t
{
    sfVector2f scale;
    sfVector2f scale_menu;
    sfVector2f pos_start;
    sfVector2f pos_menu;
    sfVector2f pos_exit;
    sfVector2f pos_how;
    sfVector2f pos_score;
    sfVector2f pos_building;
} scale_t;

typedef struct component_t
{
    text_t *start;
    text_t *exit;
    text_t *menu;
    text_t *rules;
    text_t *building;
    text_t *score;
    sfFont *pixel;
} component_t;

void menu(sfRenderWindow *window, int loop);
sfSprite *create_sprite(char const *filepath);
void analyse_events_menu(obj_t *obj, component_t *comp, struct defender *def);
text_t *init_text(char *str, sfFont *font, sfVector2f scale, sfVector2f pos);
void set_text(text_t *text);
scale_t *init_scale(void);
obj_t *init_obj(sfRenderWindow *window);
void init_sprite(obj_t *obj, struct defender *def);
void click(obj_t *obj);
int hover(obj_t *obj);
void draw_sprite(obj_t *obj, struct defender *def, component_t *comp);
component_t *init_component(scale_t *s);
void main_game();
void free_menu(component_t *comp, struct defender *def, obj_t *obj);
int check_malloc(obj_t *obj, scale_t *s, component_t *co, struct defender *def);
void check_close(obj_t *obj, component_t *comp, struct defender *def);
void free_def(struct defender *def);
void init_obj_menu(obj_t *res);

#endif /* !MENU_H */
