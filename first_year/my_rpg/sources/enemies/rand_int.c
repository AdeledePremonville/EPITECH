/*
** EPITECH PROJECT, 2021
** menu_rpg.c
** File description:
** menu for rpg
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand_max(int max)
{
    int res = 0;

    if (max == 0)
        return 0;
    res = rand();
    res %= max;
    return res;
}

int rand_one_or_two(void)
{
    int res = 0;

    res = rand();
    res %= 2;
    return res;
}

int rand_int(int min, int max)
{
    int res = 0;

    max -= min;
    if (max == 0)
        return 0;
    res = rand();
    res %= max;
    res += min;
    return res;
}
