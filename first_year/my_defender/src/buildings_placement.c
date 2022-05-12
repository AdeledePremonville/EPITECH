/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** buildings_placement
*/

#include "struct.h"

void wall_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def)
{
    if (event.type == sfEvtMouseButtonPressed && b->step == 1 && \
    event.y > 300 && event.y < 800 && b->money >= 100) {
        b->position_wall[0].x = event.x;
        b->position_wall[0].y = event.y;
        sfSprite_setPosition(b->sprite_wall[0], b->position_wall[0]);
        b->step = 2;
        b->money -= 100;
        def->rect_counter[0].left -= 62;
    }
    if (event.type == sfEvtMouseButtonPressed && b->step == 3 && \
    event.y > 300 && event.y < 800 && b->money >= 100) {
        b->position_wall[1].x = event.x;
        b->position_wall[1].y = event.y;
        sfSprite_setPosition(b->sprite_wall[1], b->position_wall[1]);
        b->step = 0;
        b->money -= 100;
        def->rect_counter[0].left -= 62;
    }
    if (event.type == sfEvtMouseButtonPressed && event.y > 811 && \
    event.x > 560 && event.x < 760) {
        if (b->step == 2)
            b->step = 3;
        else
            b->step = 1;
    }
}

void sniper_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def)
{
    if (event.type == sfEvtMouseButtonPressed && b->step == 4 && \
    event.x > 1470 && event.x < 1580 && ((event.y > 330 && event.y < 420) \
    || (event.y > 700 && event.y < 790)) && b->money >= 300) {
        b->position_sniper[0].x = event.x - 50;
        b->position_sniper[0].y = event.y - 50;
        sfSprite_setPosition(b->sprite_sniper[0], b->position_sniper[0]);
        b->step = 5;
        b->money -= 300;
        def->rect_counter[0].left -= 186;
    }
    if (event.type == sfEvtMouseButtonPressed && b->step == 6 && \
    event.x > 1490 && event.x < 1580 && ((event.y > 330 && event.y < 420) \
    || (event.y > 700 && event.y < 790)) && b->money >= 300) {
        b->position_sniper[1].x = event.x - 50;
        b->position_sniper[1].y = event.y - 50;
        sfSprite_setPosition(b->sprite_sniper[1], b->position_sniper[1]);
        b->step = 0;
        b->money -= 300;
        def->rect_counter[0].left -= 186;
    }
    if (event.type == sfEvtMouseButtonPressed && event.y > 811 && \
    event.x > 760 && event.x < 960) {
        if (b->step == 5)
            b->step = 6;
        else
            b->step = 4;
    }
}

void roblox_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def)
{
    if (event.type == sfEvtMouseButtonPressed && b->step == 7 && \
    event.y > 580 && event.y < 660 && ((event.x > 500 && event.x < 605) \
    || (event.x > 495 && event.x < 605)) && b->money >= 400) {
        b->position_roblox[0].x = event.x - 60;
        b->position_roblox[0].y = event.y - 80;
        sfSprite_setPosition(b->sprite_roblox[0], b->position_roblox[0]);
        b->step = 8;
        b->money -= 400;
        def->rect_counter[0].left -= 248;
    }
    if (event.type == sfEvtMouseButtonPressed && b->step == 9 && \
    event.y > 580 && event.y < 660 && ((event.x > 500 && event.x < 605) \
    || (event.x > 1275 && event.x < 1380)) && b->money >= 400) {
        b->position_roblox[1].x = event.x - 60;
        b->position_roblox[1].y = event.y - 80;
        sfSprite_setPosition(b->sprite_roblox[1], b->position_roblox[1]);
        b->step = 0;
        b->money -= 400;
        def->rect_counter[0].left -= 248;
    }
    if (event.type == sfEvtMouseButtonPressed && event.y > 811 && \
    event.x > 960 && event.x < 1160) {
        if (b->step == 8)
            b->step = 9;
        else
            b->step = 7;
    }
}

void tesla_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def)
{
    if (event.type == sfEvtMouseButtonPressed && b->step == 10 && \
    event.y > 543 && event.y < 598 && ((event.x > 750 && event.x < 820) \
    || (event.x > 1090 && event.x < 1160)) && b->money >= 200) {
        b->position_tesla[0].x = event.x - 40;
        b->position_tesla[0].y = event.y - 100;
        sfSprite_setPosition(b->sprite_tesla[0], b->position_tesla[0]);
        b->step = 11;
        b->money -= 200;
        def->rect_counter[0].left -= 124;
    }
    if (event.type == sfEvtMouseButtonPressed && b->step == 12 && \
    event.y > 543 && event.y < 598 && ((event.x > 750 && event.x < 820) \
    || (event.x > 1090 && event.x < 1160)) && b->money >= 200) {
        b->position_tesla[1].x = event.x - 40;
        b->position_tesla[1].y = event.y - 100;
        sfSprite_setPosition(b->sprite_tesla[1], b->position_tesla[1]);
        b->step = 0;
        b->money -= 150;
        def->rect_counter[0].left -= 124;
    }
    if (event.type == sfEvtMouseButtonPressed && event.y > 811 && \
    event.x > 1160 && event.x < 1360) {
        if (b->step == 11)
            b->step = 12;
        else
            b->step = 10;
    }
}

void click_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def)
{
    wall_drop(event, b, def);
    sniper_drop(event, b, def);
    roblox_drop(event, b, def);
    tesla_drop(event, b, def);
}