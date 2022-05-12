/*
** EPITECH PROJECT, 2022
** how_to.c - my_defender
** File description:
** how to menu
*/

#include "../../include/struct.h"
#include "../../include/menu.h"
#include "how_to.h"

void free_how(struct defender *def, how_t *obj)
{
    sfFont_destroy(obj->font);
    sfFont_destroy(obj->pixel);
    sfSprite_destroy(obj->back);
    sfText_destroy(obj->rules->text);
    sfText_destroy(obj->how->text);
    free(obj->rules);
    free(obj->how);
    sfSound_destroy(obj->sound);
    sfSoundBuffer_destroy(obj->buffer);
    free(obj);
}

how_t *init_obj_how(void)
{
    how_t *res = malloc(sizeof(how_t));
    sfEvent event;

    res->event = event;
    res->font = sfFont_createFromFile("images/text/text.ttf");
    res->pixel = sfFont_createFromFile("images/pixelmania/Pixelmania.ttf");
    res->rules = init_text("\tMy_defender is a tower defense game.\n\
    In this game, different ennemies will come from the left\n\
    of the screen and your goal is to prevent them from\n\
    attacking the tower at the right by placing buildings\n\
    who can be offensive (towers attacking)\n\
    or defensive (basic walls).\n\
    If the tower you protect reaches 0 hit points, you lose.\n", \
    res->font, (sfVector2f){2.5, 2.5}, (sfVector2f){70, 280});
    init_how(res);
    return res;
}

void events_how(struct defender *def, how_t *obj, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f co_back = sfSprite_getPosition(obj->back);

    if (obj->event.type == sfEvtClosed) {
        free_how(def, obj);
        sfRenderWindow_close(window);
    }
    if (obj->event.type == sfEvtMouseButtonPressed && pos.y >= co_back.y &&
        pos.y <= co_back.y + 200 && pos.x >= co_back.x &&
        pos.x <= co_back.x + 400) {
            sfSound_play(obj->sound);
            menu(window, 1);
            free_how(def, obj);
    }
}

void init_components(how_t *obj)
{
    sfText_setColor(obj->rules->text, sfBlack);
    sfText_setColor(obj->how->text, sfBlack);
    sfText_setFont(obj->rules->text, obj->font);
    sfText_setFont(obj->how->text, obj->pixel);
    sfText_setScale(obj->rules->text, obj->rules->scale);
    sfText_setScale(obj->how->text, obj->how->scale);
    sfText_setPosition(obj->how->text, obj->how->position);
    sfText_setPosition(obj->rules->text, obj->rules->position);
    sfText_setString(obj->how->text, obj->how->string);
    sfText_setString(obj->rules->text, obj->rules->string);
    sfSprite_setScale(obj->back, (sfVector2f){0.9, 0.9});
    sfSprite_setTextureRect(obj->back, obj->rect);
    sfSprite_setPosition(obj->back, (sfVector2f){-150, 0});
    sfSound_setBuffer(obj->sound, obj->buffer);
}

void how_to_menu(sfRenderWindow *window)
{
    struct defender *def = malloc(sizeof(struct defender));
    how_t *obj = init_obj_how();

    init_components(obj);
    sprite_init(def);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, def->sprite_map, NULL);
        sfRenderWindow_drawSprite(window, obj->back, NULL);
        sfRenderWindow_drawText(window, obj->how->text, NULL);
        sfRenderWindow_drawText(window, obj->rules->text, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &obj->event))
            events_how(def, obj, window);
    }
}