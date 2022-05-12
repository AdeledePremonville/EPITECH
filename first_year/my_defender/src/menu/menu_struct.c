/*
** EPITECH PROJECT, 2022
** menu_struct.c
** File description:
** my_defender - menu
*/

#include "../../include/menu.h"
#include "../../include/struct.h"

text_t *init_text(char *str, sfFont *font, sfVector2f scale, sfVector2f pos)
{
    text_t *res = malloc(sizeof(text_t));

    res->text = sfText_create();
    res->font = font;
    res->color = sfBlack;
    res->scale = scale;
    res->string = str;
    res->position = pos;
    return res;
}

scale_t *init_scale(void)
{
    scale_t *res = malloc(sizeof(scale_t));

    res->pos_exit = (sfVector2f){875, 580};
    res->pos_menu = (sfVector2f){680, 100};
    res->pos_start = (sfVector2f){850, 380};
    res->pos_how = (sfVector2f){290, 580};
    res->pos_building = (sfVector2f){1340, 580};
    res->pos_score = (sfVector2f){850, 780};
    res->scale = (sfVector2f){1, 1};
    res->scale_menu = (sfVector2f){3, 3};
    return res;
}

void set_text(text_t *text)
{
    sfText_setFont(text->text, text->font);
    sfText_setColor(text->text, text->color);
    sfText_setString(text->text, text->string);
    sfText_setPosition(text->text, text->position);
    sfText_setScale(text->text, text->scale);
}

obj_t *init_obj(sfRenderWindow *window)
{
    obj_t *res = malloc(sizeof(obj_t));

    res->window = window;
    res->button_start = create_sprite("images/Buttons/Button (6).png");
    res->button_exit = create_sprite("images/Buttons/Button (6).png");
    res->button_how = create_sprite("images/Buttons/Button (6).png");
    res->button_buildings = create_sprite("images/Buttons/Button (6).png");
    res->button_score = create_sprite("images/Buttons/Button (6).png");
    res->button_rect.width = 34;
    res->button_rect.height = 50/4;
    res->button_rect.left = 0;
    res->button_rect.top = 0;
    res->button_click_rect.width = 34;
    res->button_click_rect.top = 50/4 + 2;
    init_obj_menu(res);
    res->sound = sfSound_create();
    return res;
}

void init_sprite(obj_t *obj, struct defender *def)
{
    sfSoundBuffer *buf = sfSoundBuffer_createFromFile("sound/button_click.wav");

    sfSprite_setPosition(obj->button_exit, (sfVector2f){760, 540});
    sfSprite_setScale(obj->button_exit, (sfVector2f){12, 12});
    sfSprite_setPosition(obj->button_start, (sfVector2f){760 , 340});
    sfSprite_setScale(obj->button_start, (sfVector2f){12, 12});
    sfSprite_setTextureRect(obj->button_exit, obj->button_rect);
    sfSprite_setTextureRect(obj->button_start, obj->button_rect);
    sfSprite_setPosition(obj->button_how, (sfVector2f){200, 540});
    sfSprite_setScale(obj->button_how, (sfVector2f){12, 12});
    sfSprite_setTextureRect(obj->button_how, obj->button_rect);
    sfSprite_setPosition(obj->button_score, (sfVector2f){760, 740});
    sfSprite_setScale(obj->button_score, (sfVector2f){12, 12});
    sfSprite_setTextureRect(obj->button_score, obj->button_rect);
    sfSprite_setPosition(obj->button_buildings, (sfVector2f){1300, 540});
    sfSprite_setScale(obj->button_buildings, (sfVector2f){12, 12});
    sfSprite_setTextureRect(obj->button_buildings, obj->button_rect);
    sfSound_setBuffer(obj->sound, buf);
}
