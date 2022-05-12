/*
** EPITECH PROJECT, 2021
** main_rpg.c
** File description:
** main rpg
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "francois_super_code.h"

static void print_usage_h(void)
{
    my_putstr("USAGE\n    ./rpg\n\nDESCRIPTION\n");
    my_putstr("    rpg\n");
}

int main(int ac, char **av)
{
    srand(time(0));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage_h();
        return (0);
    }
    return (menu_rpg(ac, av));
}
