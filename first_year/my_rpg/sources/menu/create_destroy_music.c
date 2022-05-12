/*
** EPITECH PROJECT, 2021
** create_destroy_music.c
** File description:
** create or destroy music
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>

void destroy_music(struct music_menu *music)
{
    sfMusic_destroy(music->menu);
    sfSound_destroy(music->button);
    sfSoundBuffer_destroy(music->buff_button);
    free(music);
}

struct music_menu *create_music(void)
{
    struct music_menu *m = malloc(sizeof(struct music_menu) * 1);

    if (m == NULL)
        return NULL;
    m->menu = sfMusic_createFromFile("sprite/menu/music_menu.ogg");
    m->button = sfSound_create();
    m->buff_button = sfSoundBuffer_createFromFile("sprite/menu/s_button.ogg");
    sfSound_setBuffer(m->button, m->buff_button);
    return m;
}
