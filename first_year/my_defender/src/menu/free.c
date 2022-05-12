/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** free - my_defender
*/

#include "../../include/struct.h"
#include "../../include/menu.h"

int check_malloc(obj_t *obj, scale_t *s, component_t *co, struct defender *def)
{
    if (def == NULL)
        return 1;
    if (obj == NULL)
        return 1;
    if (s == NULL)
        return 1;
    if (co == NULL)
        return 1;
    return 0;
}

void free_menu(component_t *comp, struct defender *def, obj_t *obj)
{
    sfText_destroy(comp->start->text);
    sfText_destroy(comp->exit->text);
    sfText_destroy(comp->menu->text);
    free(comp->start);
    free(comp->exit);
    free(comp->menu);
    sfFont_destroy(comp->pixel);
    free(comp);
    sfSprite_destroy(obj->button_start);
    sfSprite_destroy(obj->button_exit);
}

void free_def(struct defender *def)
{
    sfSprite_destroy(def->sprite_map);
    sfTexture_destroy(def->text_map);
    sfSprite_destroy(def->sprite_counter);
    sfTexture_destroy(def->text_counter);
    sfSprite_destroy(def->sprite_coin);
    sfTexture_destroy(def->text_coin);
    sfClock_destroy(def->clock_counter);
    sfSprite_destroy(def->sprite_square);
    sfTexture_destroy(def->text_square);
    free(def);
}

void check_close(obj_t *obj, component_t *comp, struct defender *def)
{
    if (obj->event.type == sfEvtClosed) {
        free_menu(comp, def, obj);
        sfRenderWindow_close(obj->window);
    }
    if (obj->event.type == sfEvtMouseButtonPressed)
        click(obj);
}
