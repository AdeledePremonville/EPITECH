/*
** EPITECH PROJECT, 2022
** score.c
** File description:
** score - my_defender
*/

#include "struct.h"
#include "menu.h"
#include "pause.h"
#include "how_to.h"
#include "building.h"
#include "score.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

sfText *init_score_text(sfVector2f pos, char *str)
{
    sfFont *font = sfFont_createFromFile("images/text/text.ttf");
    sfText *res = sfText_create();

    sfText_setString(res, str);
    sfText_setFont(res, font);
    sfText_setColor(res, sfWhite);
    sfText_setScale(res, (sfVector2f){2.5, 2.5});
    sfText_setPosition(res, pos);
    return res;
}

char *fs_open_file(char *filepath)
{
    int fd = open(filepath, O_RDWR);
    char *buffer = malloc(sizeof(char) * (25 + 5));

    if (fd == -1)
        return NULL;
    if (buffer == NULL)
        return NULL;
    read(fd, buffer, 30);
    close(fd);
    return buffer;
}

void events_score(sfRenderWindow *window, sfEvent event, score_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f co_back = sfSprite_getPosition(obj->back);

    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtMouseButtonPressed && pos.y >= co_back.y &&
        pos.y <= co_back.y + 200 && pos.x >= co_back.x &&
        pos.x <= co_back.x + 400) {
            sfSound_play(obj->sound);
            menu(window, 1);
            free_score(obj);
    }
}

void score_menu(sfRenderWindow *window)
{
    struct defender *def = malloc(sizeof(struct defender));
    sfEvent event;
    score_t *obj = init_score_struct();

    sprite_init(def);
    init_score_t(obj);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, def->sprite_map, NULL);
        draw_score_t(obj, window);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            events_score(window, event, obj);
    }
}
