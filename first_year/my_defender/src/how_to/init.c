/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init - my_defender
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"

void init_how(how_t *res)
{
    sfIntRect rect = {0, 0, 540, 220};

    res->how = init_text("HOW TO PLAY", res->pixel, \
    (sfVector2f){2.3, 2.3}, (sfVector2f){430, 80});
    res->back = create_sprite("images/back_button.png");
    res->rect = rect;
    res->sound = sfSound_create();
    res->buffer = sfSoundBuffer_createFromFile("sound/fart.wav");
}
