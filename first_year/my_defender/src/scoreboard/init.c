/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init.c score - my_defender
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"

score_t *init_score_struct(void)
{
    score_t *obj = malloc(sizeof(score_t));

    obj->scores = str_to_word_array(fs_open_file("score.txt"), '\n');
    obj->title = sfText_create();
    obj->pixel = sfFont_createFromFile("images/pixelmania/Pixelmania.ttf");
    obj->font = sfFont_createFromFile("images/text/text.ttf");
    obj->best = init_score_text((sfVector2f){1000, 300}, obj->scores[0]);
    obj->score2 = init_score_text((sfVector2f){1000, 425}, obj->scores[1]);
    obj->score3 = init_score_text((sfVector2f){1000, 550}, obj->scores[2]);
    obj->score4 = init_score_text((sfVector2f){1000, 675}, obj->scores[3]);
    obj->score5 = init_score_text((sfVector2f){1000, 800}, obj->scores[4]);
    obj->first = init_score_text((sfVector2f){600, 300}, "1ST");
    obj->second = init_score_text((sfVector2f){600, 425}, "2ND");
    obj->third = init_score_text((sfVector2f){600, 550}, "3RD");
    obj->fourth = init_score_text((sfVector2f){600, 675}, "4TH");
    obj->fifth = init_score_text((sfVector2f){600, 800}, "5TH");
    obj->back = create_sprite("images/back_button.png");
    obj->square = create_sprite("images/black_square.png");
    obj->sound = sfSound_create();
    obj->buffer = sfSoundBuffer_createFromFile("sound/fart.wav");
    return obj;
}

void init_score_t(score_t *obj)
{
    sfText_setFont(obj->title, obj->pixel);
    sfText_setString(obj->title, "SCORES");
    sfText_setScale(obj->title, (sfVector2f){2.8, 2.8});
    sfText_setPosition(obj->title, (sfVector2f){550, 100});
    sfText_setColor(obj->title, sfWhite);
    sfSprite_setPosition(obj->back, (sfVector2f){-150, 0});
    sfSprite_setScale(obj->back, (sfVector2f){0.9, 0.9});
    sfSprite_setPosition(obj->square, (sfVector2f){250, -170});
    sfSprite_setScale(obj->square, (sfVector2f){1.7, 1.7});
    sfSound_setBuffer(obj->sound, obj->buffer);
}

void draw_score_t(score_t *obj, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, obj->square, NULL);
    sfRenderWindow_drawText(window, obj->best, NULL);
    sfRenderWindow_drawText(window, obj->score2, NULL);
    sfRenderWindow_drawText(window, obj->score3, NULL);
    sfRenderWindow_drawText(window, obj->score4, NULL);
    sfRenderWindow_drawText(window, obj->score5, NULL);
    sfRenderWindow_drawText(window, obj->title, NULL);
    sfRenderWindow_drawSprite(window, obj->back, NULL);
    sfRenderWindow_drawText(window, obj->first, NULL);
    sfRenderWindow_drawText(window, obj->second, NULL);
    sfRenderWindow_drawText(window, obj->third, NULL);
    sfRenderWindow_drawText(window, obj->fourth, NULL);
    sfRenderWindow_drawText(window, obj->fifth, NULL);
}

void free_score(score_t *obj)
{
    sfText_destroy(obj->title);
    sfFont_destroy(obj->pixel);
    sfFont_destroy(obj->font);
    sfText_destroy(obj->best);
    sfText_destroy(obj->score2);
    sfText_destroy(obj->score3);
    sfText_destroy(obj->score4);
    sfText_destroy(obj->score5);
    sfText_destroy(obj->first);
    sfText_destroy(obj->second);
    sfText_destroy(obj->third);
    sfText_destroy(obj->fourth);
    sfText_destroy(obj->fifth);
    sfSprite_destroy(obj->back);
    sfSprite_destroy(obj->square);
    sfSound_destroy(obj->sound);
    sfSoundBuffer_destroy(obj->buffer);
}