/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** free - my_defender
*/


#include "../../include/struct.h"
#include "../../include/menu.h"
#include "../../include/pause.h"

void free_obj(obj_pause_t *obj)
{
    sfSprite_destroy(obj->button_start);
    sfSprite_destroy(obj->button_exit);
    sfSprite_destroy(obj->button_resume);
}

void free_comp(pause_comp_t *comp)
{
    sfText_destroy(comp->start->text);
    sfText_destroy(comp->exit->text);
    sfText_destroy(comp->resume->text);
    sfText_destroy(comp->pause->text);
    free(comp->start);
    free(comp->exit);
    free(comp->resume);
    free(comp->pause);
    sfFont_destroy(comp->pixel);
    free(comp);
}

void free_pause(pause_comp_t *comp, struct defender *def, obj_pause_t *obj)
{
    free_obj(obj);
    free_comp(comp);
}

int hover_state(obj_pause_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_exit = sfSprite_getPosition(obj->button_exit);
    sfVector2f co_resume = sfSprite_getPosition(obj->button_resume);

    if (pos.x >= co_exit.x && pos.x <= co_exit.x + (34 * 12) &&
        pos.y >= co_exit.y && pos.y <= co_exit.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_exit, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    if (pos.x >= co_resume.x && pos.x <= co_resume.x + (34 * 12) &&
        pos.y >= co_resume.y && pos.y <= co_resume.y + ((50 / 4) * 12)) {
        sfSprite_setTextureRect(obj->button_resume, obj->hover_rect);
        obj->state = 1;
        return 0;
    }
    return 1;
}