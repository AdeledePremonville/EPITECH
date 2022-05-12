/*
** EPITECH PROJECT, 2022
** how_to.h - my_defender
** File description:
** how to menu_h
*/

#include "struct.h"
#include "menu.h"
#include "pause.h"

#ifndef HOW_H
    #define HOW_H

typedef struct how_t
{
    sfEvent event;
    sfFont *font;
    sfFont *pixel;
    text_t *rules;
    text_t *how;
    sfSprite *back;
    sfIntRect rect;
    sfSound *sound;
    sfSoundBuffer *buffer;
} how_t;

void events_how(struct defender *def, how_t *obj, sfRenderWindow *window);

void how_to_menu(sfRenderWindow *window);

how_t *init_obj_how(void);

void init_components(how_t *obj);

void init_how(how_t *res);

#endif /* !HOW_H */
