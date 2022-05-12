/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** main
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"
#include "end.h"
#include <stdlib.h>
#include <stddef.h>

sfRenderWindow *createWindow(int width, int heigth)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, heigth, 60};

    window = sfRenderWindow_create(video_mode, "My Window"
                                   , sfDefaultStyle, NULL);
    return (window);
}

void analyse_events(sfRenderWindow *window, sfEvent event, struct defender \
*def, struct characters *c, struct buildings *b, struct attack *a, \
struct square *s)
{
    if (event.type == sfEvtClosed) {
        free_main(def, c, a, b, s);
        sfRenderWindow_close(window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        free_main(def, c, a, b, s);
        pause_menu(window);
    }
    if (event.type == sfEvtMouseButtonPressed)
        click_drop(event.mouseButton, b, def);
}

int money_counter(struct defender *def, sfRenderWindow *window, struct \
characters *c, struct attack *a, struct buildings *b, struct square *s)
{
    sfTime time = sfClock_getElapsedTime(def->clock_counter);
    float seconds = sfTime_asSeconds(time);
    sfTime time2 = sfClock_getElapsedTime(def->clock_counter2);
    float seconds2 = sfTime_asSeconds(time2);
    draw_init(window, def, s, b);
    for (int i = 0; i < c->dragon; i++)
        if (c->life_dragon[i] > 0)
            draw_dragon_init(window, c, a, b, i);
    for (int i = 0; i < c->demon; i++)
        if (c->life_demon[i] > 0)
            draw_demon_init(window, c, a, b, i);
    for (int i = 0; i < c->lizard; i++)
        if (c->life_lizard[i] > 0)
            draw_lizard_init(window, c, a, b, i);
    for (int i = 0; i < 5; i++) {
        sfSprite_setTextureRect(def->sprite_counter[i], def->rect_counter[i]);
        sfSprite_setPosition(def->sprite_counter[i], def->position_counter[i]);
    }
    sfSprite_setPosition(def->sprite_coin, def->position_coin);

    if (seconds > 1) {
        b->money += 10;
        def->rect_counter[1].left += 62;
        if (def->rect_counter[1].left >= 620)
            def->rect_counter[1].left = 0;
        sfClock_restart(def->clock_counter);
    }
    if (seconds2 > 10 && def->rect_counter[1].left == 0) {
        def->rect_counter[0].left += 62;
        if (def->rect_counter[0].left >= 620)
            def->rect_counter[0].left = 0;
        sfClock_restart(def->clock_counter2);
    }
    return (0);
}

void clock_init(struct defender *def, struct characters *c, \
struct attack *a, struct buildings *b)
{
    def->clock_counter = sfClock_create();
    def->clock_counter2 = sfClock_create();
    b->clock_timer = sfClock_create();
    b->clock_timer2 = sfClock_create();
    c->clock_dragon_walk = sfClock_create();
    c->clock_demon_walk = sfClock_create();
    c->clock_lizard_walk = sfClock_create();
    c->clock_spawn = sfClock_create();
    b->clock_end = sfClock_create();
    a->clock_dragon_attack = sfClock_create();
    a->clock_demon_attack = sfClock_create();
    a->clock_demon_attack2 = sfClock_create();
    a->clock_lizard_attack = sfClock_create();
    b->clock_tesla = sfClock_create();
    b->clock_sniper = sfClock_create();
    b->clock_roblox = sfClock_create();
}

void other_init(struct attack *a, struct buildings *b, struct characters *c)
{
    c->spawn = 0;
    b->step = 0;
    c->dragon = 0;
    a->dragon_attack = 0;
    c->demon = 0;
    b->life_base = 1000;
    c->lizard = 0;
    b->end = 0;
    b->money = 0;
    for (int i = 0; i < 10; i++) {
        c->step_dragon[i] = 0;
        b->walk_dragon[i] = 0;
        c->step_demon[i] = 0;
        b->walk_demon[i] = 0;
        c->step_lizard[i] = 0;
        b->walk_lizard[i] = 0;
        c->life_dragon[i] = 200;
        c->life_demon[i] = 500;
        c->life_lizard[i] = 150;
    }
}

void main_game(sfRenderWindow *window)
{
    sfEvent event;
    struct defender *def = malloc(sizeof(struct defender));
    struct characters *c = malloc(sizeof(struct characters));
    struct attack *a = malloc(sizeof(struct attack));
    struct buildings *b = malloc(sizeof(struct buildings));
    struct square *s = malloc(sizeof(struct square));
    clock_init(def, c, a, b);
    other_init(a, b, c);
    all_init(def, c, a, b, s);

    while (sfRenderWindow_isOpen(window) && b->life_base > 0 && b->end != 1) {
        sfRenderWindow_display(window);
        end_game(b, def, window);
        shadow(window, b);
        roblox_shoot(c, b);
        sniper_shoot(c, b);
        tesla_shoot(c, b);
        ennemies_spawn(a, b, c);
        dragon_spawn(window, c, a, b);
        demon_spawn(c, a, b);
        lizard_spawn(c, a, b);
        money_counter(def, window, c, a, b, s);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, def, c, b, a, s);
        }
    }
}

int main(void)
{
    sfRenderWindow *window = createWindow(1920, 1080);
    menu(window, 0);
    //end_menu(window, 1, 100);
    //check_score(802);
    return 0;
}
