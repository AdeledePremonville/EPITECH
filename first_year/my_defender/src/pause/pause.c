/*
** EPITECH PROJECT, 2022
** pause.c
** File description:
** pause - my_defender
*/

#include "../../include/struct.h"
#include "../../include/menu.h"
#include "../../include/pause.h"

int hover_pause(obj_pause_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_start = sfSprite_getPosition(obj->button_start);

    if (pos.x >= co_start.x && pos.x <= co_start.x + (34 * 12) &&
        pos.y >= co_start.y && pos.y <= co_start.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_start, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    if (hover_state(obj) == 0)
        return 0;
    obj->state = 0;
    return 0;
}

void click_pause(obj_pause_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_start = sfSprite_getPosition(obj->button_start);
    sfVector2f co_exit = sfSprite_getPosition(obj->button_exit);
    sfVector2f co_resume = sfSprite_getPosition(obj->button_resume);

    if (pos.x >= co_start.x && pos.x <= co_start.x + (34 * 12) &&
        pos.y >= co_start.y && pos.y <= co_start.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_start, obj->button_click_rect);
        obj->state = 2;
    }
    if (pos.x >= co_exit.x && pos.x <= co_exit.x + (34 * 12) &&
        pos.y >= co_exit.y && pos.y <= co_exit.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_exit, obj->button_click_rect);
    }
    if (pos.x >= co_resume.x && pos.x <= co_resume.x + (34 * 12) &&
        pos.y >= co_resume.y && pos.y <= co_resume.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_resume, obj->button_click_rect);
    }
}

void events_pause(obj_pause_t *obj, struct defender *def, pause_comp_t *comp)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_start = sfSprite_getPosition(obj->button_start);
    sfVector2f co_resume = sfSprite_getPosition(obj->button_resume);

    hover_pause(obj);
    close_pause(obj, comp, def);
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_start.x && pos.x <= co_start.x + (34 * 12) &&
        pos.y >= co_start.y && pos.y <= co_start.y + ((50 / 4) * 12))) {
        free_pause(comp, def, obj);
        menu(obj->window, 1);
    }
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_resume.x && pos.x <= co_resume.x + (34 * 12) &&
        pos.y >= co_resume.y && pos.y <= co_resume.y + ((50 / 4) * 12))) {
        free_pause(comp, def, obj);
        main_game(obj->window);
    }
}

void init_sprite_pause(obj_pause_t *obj)
{
    sfSprite_setPosition(obj->button_exit, (sfVector2f){760, 780});
    sfSprite_setPosition(obj->button_start, (sfVector2f){760 , 580});
    sfSprite_setPosition(obj->button_resume, (sfVector2f){760, 380});
    sfSprite_setTextureRect(obj->button_exit, obj->button_rect);
    sfSprite_setTextureRect(obj->button_start, obj->button_rect);
    sfSprite_setTextureRect(obj->button_resume, obj->button_rect);
    sfSprite_setScale(obj->button_exit, (sfVector2f){12, 12});
    sfSprite_setScale(obj->button_start, (sfVector2f){12, 12});
    sfSprite_setScale(obj->button_resume, (sfVector2f){12, 12});
}

void pause_menu(sfRenderWindow *window)
{
    obj_pause_t *obj = init_obj_pause(window);
    scale_pause_t *scale = init_scale_pause();
    pause_comp_t *comp = init_comp_pause(scale);
    struct defender *def = malloc(sizeof(struct defender));

    free(scale);
    sprite_init(def);
    init_sprite_pause(obj);
    set_text(comp->start);
    set_text(comp->exit);
    set_text(comp->resume);
    set_text(comp->pause);
    while (sfRenderWindow_isOpen(obj->window)) {
        draw_pause(obj, def, comp);
    }
}