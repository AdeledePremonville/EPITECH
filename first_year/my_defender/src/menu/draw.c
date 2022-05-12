/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** my_defender - draw.c
*/

#include "../../include/struct.h"
#include "../../include/menu.h"

component_t *init_component(scale_t *s)
{
    component_t *res = malloc(sizeof(component_t));

    res->pixel = sfFont_createFromFile("images/pixelmania/Pixelmania.ttf");
    res->start = init_text("START", res->pixel, s->scale, s->pos_start);
    res->exit = init_text("EXIT", res->pixel, s->scale, s->pos_exit);
    res->rules = init_text("RULES", res->pixel, s->scale, s->pos_how);
    res->menu = init_text("MENU", res->pixel, s->scale_menu, s->pos_menu);
    res->building = init_text("BUILDING", res->pixel, s->scale, s->pos_building);
    res->score = init_text("SCORE", res->pixel, s->scale, s->pos_score);
    return res;
}

void draw_obj(obj_t *obj, component_t *comp)
{
    sfRenderWindow_drawSprite(obj->window, obj->button_how, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_score, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_buildings, NULL);
    sfRenderWindow_drawText(obj->window, comp->rules->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->start->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->score->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->building->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->menu->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->exit->text, NULL);
}

void draw_sprite(obj_t *obj, struct defender *def, component_t *comp)
{
    if (obj->state == 0) {
        sfSprite_setTextureRect(obj->button_start, obj->button_rect);
        sfSprite_setTextureRect(obj->button_exit, obj->button_rect);
        sfSprite_setTextureRect(obj->button_how, obj->button_rect);
        sfSprite_setTextureRect(obj->button_score, obj->button_rect);
        sfSprite_setTextureRect(obj->button_buildings, obj->button_rect);
    }
    sfRenderWindow_drawSprite(obj->window, def->sprite_map, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_exit, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_start, NULL);
    draw_obj(obj, comp);
    sfRenderWindow_display(obj->window);
    while (sfRenderWindow_pollEvent(obj->window, &obj->event))
        analyse_events_menu(obj, comp, def);
}

void init_obj_menu(obj_t *res)
{
    res->button_click_rect.height = 50/4;
    res->button_click_rect.left = 0;
    res->hover_rect.left = 0;
    res->hover_rect.top = 50/2 + 2;
    res->hover_rect.width = 34;
    res->hover_rect.height = 50/4;
    res->state = 0;
}