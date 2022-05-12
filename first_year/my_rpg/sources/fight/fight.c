/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** fight
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>

int return_res(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy)
{
    int res = 0;

    if (is_end(event, fight, chara, enemy) != -1)
        res = is_end(event, fight, chara, enemy);
    else
        res = display_fight(fight, event, chara, enemy);
    return res;
}

int end_fight(struct fight *fight, int res,
struct character *chara, struct enemy *enemy)
{
    destroy_fight(fight, chara, enemy);
    return res;
}

struct fight *create_fight(sfRenderWindow *window)
{
    struct fight *fight = malloc(sizeof(struct fight) * 1);

    if (fight == NULL)
        return NULL;
    fight->sprite_bg = sfSprite_create();
    fight->text_bg = sfTexture_createFromFile("sprite/fight/bg.png", NULL);
    sfSprite_setTexture(fight->sprite_bg, fight->text_bg, sfFalse);
    sfSprite_setScale(fight->sprite_bg, (sfVector2f){1.8, 1.7});
    fight->buttons_fight = create_buttons_fight();
    fight->music_fight = sfMusic_createFromFile("sprite/fight/bg_music.ogg");
    if (fight->buttons_fight == NULL)
        return NULL;
    fight->state = 0;
    sfMusic_play(fight->music_fight);
    sfMusic_setLoop(fight->music_fight, true);
    fight->window = window;
    set_fight_struct(fight);
    return fight;
}

void move_rect_fight(sfIntRect *rect, int max, int add)
{
    if (rect->left >= max) {
        rect->left = 0;
    } else
        rect->left += add;
}

int start_fight(sfRenderWindow *window, struct param_fight *p, int *life_hero)
{
    int res = 0;
    struct character *chara = create_character_fight(p);
    struct fight *fight = create_fight(window);
    sfEvent event;
    struct enemy *enemy = create_enemy(p);

    if (fight == NULL)
        return 84;
    chara->health->dmg = chara->health->life - *life_hero;
    while (sfRenderWindow_isOpen(window))
        if (is_end(event, fight, chara, enemy) != -1 ||
        display_fight(fight, event, chara, enemy) != 0) {
            res = return_res(fight, event, chara, enemy);
            p->nb_pot_100hp = chara->items->potion_100hp->potion;
            p->nb_pot_200hp = chara->items->potion_200hp->potion;
            *life_hero = chara->health->life - chara->health->dmg;
            return end_fight(fight, res, chara, enemy);
        }
    destroy_fight(fight, chara, enemy);
}
