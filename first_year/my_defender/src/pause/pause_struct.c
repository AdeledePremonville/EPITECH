/*
** EPITECH PROJECT, 2022
** pause_struct.c
** File description:
** pause_struct - my_defender
*/

#include "../../include/struct.h"
#include "../../include/menu.h"
#include "../../include/pause.h"

obj_pause_t *init_obj_pause(sfRenderWindow *window)
{
    obj_pause_t *res = malloc(sizeof(obj_pause_t));

    res->window = window;
    res->button_start = create_sprite("images/Buttons/Button (6).png");
    res->button_exit = create_sprite("images/Buttons/Button (6).png");
    res->button_resume = create_sprite("images/Buttons/Button (6).png");
    res->button_rect.width = 34;
    res->button_rect.left = 0;
    res->button_rect.top = 0;
    res->button_rect.height = 50/4;
    res->button_click_rect.width = 34;
    res->button_click_rect.top = 50/4 + 2;
    res->button_click_rect.height = 50/4;
    res->hover_rect.top = 50/2 + 2;
    res->hover_rect.width = 34;
    res->hover_rect.height = 50/4;
    res->hover_rect.left = 0;
    res->state = 0;
    return res;
}

scale_pause_t *init_scale_pause()
{
    scale_pause_t *res = malloc(sizeof(scale_pause_t));

    res->scale = (sfVector2f){1, 1};
    res->scale_pause = (sfVector2f){3, 3};
    res->pos_start = (sfVector2f){850, 620};
    res->pos_resume = (sfVector2f){830, 420};
    res->pos_pause = (sfVector2f){680, 150};
    res->pos_exit = (sfVector2f){875, 820};
    return res;
}

pause_comp_t *init_comp_pause(scale_pause_t *s)
{
    pause_comp_t *res = malloc(sizeof(pause_comp_t));

    res->pixel = sfFont_createFromFile("images/pixelmania/Pixelmania.ttf");
    res->start = init_text("MENU", res->pixel, s->scale, s->pos_start);
    res->exit = init_text("EXIT", res->pixel, s->scale, s->pos_exit);
    res->resume = init_text("RESUME", res->pixel, s->scale, s->pos_resume);
    res->pause = init_text("PAUSE", res->pixel, s->scale_pause, s->pos_pause);
    return res;
}

void draw_pause(obj_pause_t *obj, struct defender *def, pause_comp_t *comp)
{
    if (obj->state == 0) {
        sfSprite_setTextureRect(obj->button_start, obj->button_rect);
        sfSprite_setTextureRect(obj->button_exit, obj->button_rect);
        sfSprite_setTextureRect(obj->button_resume, obj->button_rect);
    }
    sfRenderWindow_drawSprite(obj->window, def->sprite_map, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_exit, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_start, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->button_resume, NULL);
    sfRenderWindow_drawText(obj->window, comp->start->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->resume->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->pause->text, NULL);
    sfRenderWindow_drawText(obj->window, comp->exit->text, NULL);
    sfRenderWindow_display(obj->window);
    while (sfRenderWindow_pollEvent(obj->window, &obj->event))
        events_pause(obj, def, comp);
}

void close_pause(obj_pause_t *obj, pause_comp_t *comp, struct defender *def)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f co_exit = sfSprite_getPosition(obj->button_exit);

    if (obj->event.type == sfEvtMouseButtonPressed)
        click_pause(obj);
    if (obj->event.type == sfEvtMouseButtonReleased &&
        (pos.x >= co_exit.x && pos.x <= co_exit.x + (34 * 12) &&
        pos.y >= co_exit.y && pos.y <= co_exit.y + ((50 / 4) * 12))) {
        free_pause(comp, def, obj);
        sfRenderWindow_close(obj->window);
    }
    if (obj->event.type == sfEvtClosed) {
        free_pause(comp, def, obj);
        sfRenderWindow_close(obj->window);
    }
}
