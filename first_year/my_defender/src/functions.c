/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** functions
*/

#include "struct.h"

void money_counter_rect(struct defender *def)
{
    for (int i = 0; i < 3; i++) {
        def->rect_counter[i].top = 0;
        def->rect_counter[i].height = 80;
        def->rect_counter[i].left = 0;
        def->rect_counter[i].width = 62;
    }
    def->position_counter[0].x = 100;
    def->position_counter[0].y = 0;
    def->position_counter[1].x = 170;
    def->position_counter[1].y = 0;
    def->position_counter[2].x = 240;
    def->position_counter[2].y = 0;
    def->position_coin.x = 25;
    def->position_coin.y = 10;
}

void timer(struct defender *def)
{
    def->rect_counter[3].top = 0;
    def->rect_counter[3].height = 80;
    def->rect_counter[3].left = 558;
    def->rect_counter[3].width = 62;
    def->rect_counter[4].top = 0;
    def->rect_counter[4].height = 80;
    def->rect_counter[4].left = 310;
    def->rect_counter[4].width = 62;
    def->position_counter[4].x = 970;
    def->position_counter[4].y = 0;
    def->position_counter[3].x = 1040;
    def->position_counter[3].y = 0;
}

void sprite_init(struct defender *def)
{
    def->sprite_map = sfSprite_create();
    def->sprite_coin = sfSprite_create();
    def->text_map = sfTexture_createFromFile("images/DefenseMap", NULL);
    def->text_counter = sfTexture_createFromFile("images/counter", NULL);
    def->text_coin = sfTexture_createFromFile("images/coin", NULL);
    sfSprite_setTexture(def->sprite_map, def->text_map, sfTrue);
    sfSprite_setTexture(def->sprite_coin, def->text_coin, sfTrue);
    for (int i = 0; i < 5; i++) {
        def->sprite_counter[i] = sfSprite_create();
        sfSprite_setTexture(def->sprite_counter[i], def->text_counter, sfTrue);
    }
}

void draw_init(sfRenderWindow *window, struct defender *def, \
struct square *s, struct buildings *b)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, def->sprite_map, NULL);
    sfRenderWindow_drawSprite(window, def->sprite_coin, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(window, s->sprite_square[i], NULL);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(window, b->sprite_sniper[i], NULL);
        sfRenderWindow_drawSprite(window, b->sprite_roblox[i], NULL);
        sfRenderWindow_drawSprite(window, b->sprite_tesla[i], NULL);
        sfRenderWindow_drawSprite(window, b->sprite_wall[i], NULL);
    }
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(window, def->sprite_counter[i], NULL);
    if (b->step == 4 || b->step == 6 || b->step == 7 || b->step == 9 || \
    b->step == 10 || b->step == 12) {
        for (int i = 0; i < 2; i++) {
            sfSprite_setPosition(b->sprite_shadow[i], b->position_shadow[i]);
            sfRenderWindow_drawSprite(window, b->sprite_shadow[i], NULL);
        }
    }
}

void all_init(struct defender *def, struct characters *c, \
struct attack *a, struct buildings *b, struct square *s)
{
    sprite_init(def);
    money_counter_rect(def);
    timer(def);
    dragon_walk_rect(c);
    dragon_attack_rect(a, c);
    demon_walk_rect(c);
    demon_attack_rect(a);
    lizard_walk_rect(c);
    lizard_attack_rect(a);
    fire_rect(a);
    square_init(s);
    square_pos(s);
    buildings_square_init(b);
    buildings_square_pos(b);
}
