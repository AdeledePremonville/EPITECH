/*
** EPITECH PROJECT, 2022
** end.c
** File description:
** end page - my_defender
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"
#include "end.h"

void events_end(struct defender *def, sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtMouseButtonReleased)
        menu(window, 1);
}

end_t *init_end_struct(void)
{
    end_t *res = malloc(sizeof(end_t));

    res->text = sfText_create();
    res->font = sfFont_createFromFile("images/text/text.ttf");
    res->pixel = sfFont_createFromFile("images/pixelmania/Pixelmania.ttf");
    res->click = sfText_create();
    res->score = sfText_create();
    res->yours = sfText_create();
    res->square = create_sprite("images/black_square.png");
    return res;
}

void set_end_struct2(end_t *res, int sc)
{
    sfText_setFont(res->score, res->font);
    sfText_setString(res->score, int_to_str(sc));
    sfText_setPosition(res->score, (sfVector2f){850, 450});
    sfText_setScale(res->score, (sfVector2f){6, 6});
    sfText_setColor(res->score, sfWhite);
    sfText_setFont(res->click, res->font);
    sfText_setFont(res->text, res->pixel);
    sfText_setColor(res->text, sfBlack);
    sfText_setColor(res->click, sfBlack);
    sfText_setString(res->click, "click to retry\n");
    sfText_setPosition(res->click, (sfVector2f){780, 220});
    sfText_setScale(res->click, (sfVector2f){2, 2});
    sfText_setScale(res->text, (sfVector2f){2.3, 2.3});
    sfSprite_setScale(res->square, (sfVector2f){1.3, 0.7});
    sfSprite_setPosition(res->square, (sfVector2f){450, 250});
}

void set_end_struct(end_t *res, int end)
{
    if (end == 0) {
        sfText_setString(res->text, "YOU WON");
        sfText_setPosition(res->text, (sfVector2f){600, 100});
    }
    if (end == 1) {
        sfText_setString(res->text, "GAME OVER");
        sfText_setPosition(res->text, (sfVector2f){500, 100});
    }
    sfText_setFont(res->yours, res->font);
    sfText_setString(res->yours, "Your Score");
    sfText_setColor(res->yours, sfWhite);
    sfText_setPosition(res->yours, (sfVector2f){720, 325});
    sfText_setScale(res->yours, (sfVector2f){4, 4});
}

void end_menu(sfRenderWindow *window, int end, int sc)
{
    struct defender *def = malloc(sizeof(struct defender));
    sfEvent event;
    end_t *obj = init_end_struct();

    check_score(sc);
    set_end_struct(obj, end);
    set_end_struct2(obj, sc);
    sprite_init(def);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, def->sprite_map, NULL);
        sfRenderWindow_drawSprite(window, obj->square, NULL);
        sfRenderWindow_drawText(window, obj->text, NULL);
        sfRenderWindow_drawText(window, obj->click, NULL);
        sfRenderWindow_drawText(window, obj->score, NULL);
        sfRenderWindow_drawText(window, obj->yours, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            events_end(def, event, window);
    }
}