/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** menu page - mydefender
*/

#include "../../include/struct.h"
#include "../../include/menu.h"
#include "building.h"
#include "how_to.h"
#include "score.h"
#include <stdlib.h>
#include <stddef.h>

sfSprite *create_sprite(char const *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

int hover(obj_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_start = sfSprite_getPosition(obj->button_start);
    sfVector2f co_exit = sfSprite_getPosition(obj->button_exit);
    sfVector2f co_how = sfSprite_getPosition(obj->button_how);
    sfVector2f co_score = sfSprite_getPosition(obj->button_score);
    sfVector2f co_building = sfSprite_getPosition(obj->button_buildings);

    if (pos.x >= co_start.x && pos.x <= co_start.x + (34 * 12) &&
        pos.y >= co_start.y && pos.y <= co_start.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_start, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    if (pos.x >= co_exit.x && pos.x <= co_exit.x + (34 * 12) &&
        pos.y >= co_exit.y && pos.y <= co_exit.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_exit, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    if (pos.x >= co_how.x && pos.x <= co_how.x + (34 * 12) &&
        pos.y >= co_how.y && pos.y <= co_how.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_how, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    if (pos.x >= co_score.x && pos.x <= co_score.x + (34 * 12) &&
        pos.y >= co_score.y && pos.y <= co_score.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_score, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    if (pos.x >= co_building.x && pos.x <= co_building.x + (34 * 12) &&
        pos.y >= co_building.y && pos.y <= co_building.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_buildings, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    obj->state = 0;
    return 0;
}

void click(obj_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_start = sfSprite_getPosition(obj->button_start);
    sfVector2f co_exit = sfSprite_getPosition(obj->button_exit);
    sfVector2f co_how = sfSprite_getPosition(obj->button_how);
    sfVector2f co_score = sfSprite_getPosition(obj->button_score);
    sfVector2f co_building = sfSprite_getPosition(obj->button_buildings);

    if (pos.x >= co_start.x && pos.x <= co_start.x + (34 * 12) &&
        pos.y >= co_start.y && pos.y <= co_start.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_start, obj->button_click_rect);
        sfSound_play(obj->sound);
        obj->state = 2;
    }
    if (pos.x >= co_exit.x && pos.x <= co_exit.x + (34 * 12) &&
        pos.y >= co_exit.y && pos.y <= co_exit.y + ((50 / 4) * 12)) {
        sfSound_play(obj->sound);
        sfSprite_setTextureRect(obj->button_exit, obj->button_click_rect);
    }
    if (pos.x >= co_how.x && pos.x <= co_how.x + (34 * 12) &&
        pos.y >= co_how.y && pos.y <= co_how.y + ((50 / 4) * 12)) {
        sfSound_play(obj->sound);
        sfSprite_setTextureRect(obj->button_how, obj->button_click_rect);
    }
    if (pos.x >= co_score.x && pos.x <= co_score.x + (34 * 12) &&
        pos.y >= co_score.y && pos.y <= co_score.y + ((50 / 4) * 12)) {
        sfSound_play(obj->sound);
        sfSprite_setTextureRect(obj->button_score, obj->button_click_rect);
    }
    if (pos.x >= co_building.x && pos.x <= co_building.x + (34 * 12) &&
        pos.y >= co_building.y && pos.y <= co_building.y + ((50 / 4) * 12)) {
        sfSound_play(obj->sound);
        sfSprite_setTextureRect(obj->button_buildings, obj->button_click_rect);
    }
}

void analyse_events_menu(obj_t *obj, component_t *comp, struct defender *def)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_start = sfSprite_getPosition(obj->button_start);
    sfVector2f co_exit = sfSprite_getPosition(obj->button_exit);
    sfVector2f co_how = sfSprite_getPosition(obj->button_how);
    sfVector2f co_score = sfSprite_getPosition(obj->button_score);
    sfVector2f co_building = sfSprite_getPosition(obj->button_buildings);

    hover(obj);
    check_close(obj, comp, def);
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_exit.x && pos.x <= co_exit.x + (34 * 12) &&
        pos.y >= co_exit.y && pos.y <= co_exit.y + ((50 / 4) * 12))) {
        free_menu(comp, def, obj);
        sfRenderWindow_close(obj->window);
    }
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_start.x && pos.x <= co_start.x + (34 * 12) &&
        pos.y >= co_start.y && pos.y <= co_start.y + ((50 / 4) * 12))) {
        free_menu(comp, def, obj);
        main_game(obj->window);
    }
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_how.x && pos.x <= co_how.x + (34 * 12) &&
        pos.y >= co_how.y && pos.y <= co_how.y + ((50 / 4) * 12))) {
        free_menu(comp, def, obj);
        how_to_menu(obj->window);
    }
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_score.x && pos.x <= co_score.x + (34 * 12) &&
        pos.y >= co_score.y && pos.y <= co_score.y + ((50 / 4) * 12))) {
        free_menu(comp, def, obj);
        score_menu(obj->window);
    }
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_building.x && pos.x <= co_building.x + (34 * 12) &&
        pos.y >= co_building.y && pos.y <= co_building.y + ((50 / 4) * 12))) {
        free_menu(comp, def, obj);
        building_menu(obj->window);
    }
}

void menu(sfRenderWindow *window, int loop)
{
    obj_t *obj = init_obj(window);
    scale_t *scale = init_scale();
    component_t *component = init_component(scale);
    struct defender *def = malloc(sizeof(struct defender));
    sfMusic *music = sfMusic_createFromFile("sound/Neverland.wav");

    if (check_malloc(obj, scale, component, def) == 1)
        return;
    if (loop == 0) {
        sfMusic_setLoop(music, sfTrue);
        sfMusic_play(music);
    }
    set_text(component->start);
    set_text(component->exit);
    set_text(component->menu);
    set_text(component->rules);
    set_text(component->building);
    set_text(component->score);
    sprite_init(def);
    init_sprite(obj, def);
    while (sfRenderWindow_isOpen(obj->window))
        draw_sprite(obj, def, component);
}