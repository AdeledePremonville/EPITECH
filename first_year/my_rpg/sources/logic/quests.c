/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-nicolas.poupon
** File description:
** quests.c
*/

#include "my.h"
#include "p.h"

int level_up(sfRenderWindow *win, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("sprite/menu/police.TTF");

    sfText_setFont(text, font);
    sfText_setColor(text, sfGreen);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, pos);
    sfText_setString(text, "Level Up !");
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
}

static sfText *create_quest_text(sfVector2f pos, char *str, sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("sprite/menu/police.TTF");

    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    return text;
}

void create_quest(sfRenderWindow *win, sfVector2f pos, char *str, int display)
{
    sfVector2f size = {300, 200};
    sfColor color = sfColor_fromRGBA(163, 163, 163, 255);
    sfRectangleShape *rec = sfRectangleShape_create();
    sfText *text = create_quest_text(pos, str, sfBlack);

    sfRectangleShape_setFillColor(rec, sfWhite);
    sfRectangleShape_setOutlineThickness(rec, 10);
    sfRectangleShape_setOutlineColor(rec, color);
    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setPosition(rec, pos);
    if (display) {
        sfRenderWindow_drawRectangleShape(win, rec, NULL);
        sfRenderWindow_drawText(win, text, NULL);
    }
    sfText_destroy(text);
    sfRectangleShape_destroy(rec);
}

static sfText *end_game_s(sfRenderWindow *win, int end)
{
    sfText *text;

    if (end == 1) {
        text = create_quest_text((sfVector2f){1450, 890},
        "Congratulation you found your twin !\n\nPress any key to continue...",
        sfWhite);
    }
    if (end == 0) {
        text = create_quest_text((sfVector2f){1550, 890},
        "Next stage...\n\nPress any to continue...", sfWhite);
    }
    if (end == 2) {
        text = create_quest_text((sfVector2f){1550, 890},
        "You lost...\n\nPress any to continue...", sfWhite);
    }
    return text;
}

int end_game(sfRenderWindow *win, int ending)
{
    sfRectangleShape *rec = sfRectangleShape_create();
    sfText *text = end_game_s(win, ending);
    sfEvent event;

    sfRectangleShape_setFillColor(rec, sfBlack);
    sfRectangleShape_setSize(rec, (sfVector2f){1920, 1080});
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_drawRectangleShape(win, rec, NULL);
        sfRenderWindow_drawText(win, text, NULL);
        sfRenderWindow_pollEvent(win, &event);
        sfRenderWindow_display(win);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed) {
            sfText_destroy(text);
            sfRectangleShape_destroy(rec);
            return 0;
        }
        sfRenderWindow_clear(win, sfBlack);
    }
}
