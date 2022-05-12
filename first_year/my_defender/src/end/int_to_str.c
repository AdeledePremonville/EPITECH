/*
** EPITECH PROJECT, 2022
** int_to_str
** File description:
** int_to_str - my_defender
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"

int my_intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}

int ten_mult(int nb)
{
    int res = 1;
    int len = my_intlen(nb);

    for (int i = 0; i < len - 1; i++) {
        res *= 10;
    }
    return res;
}

char *int_to_str(int nb)
{
    int len = my_intlen(nb);
    char *res = malloc(sizeof(char) * (len + 1));
    int ten = ten_mult(nb);
    int stock = 0;

    for (int i = 0; i <= len - 1; i++) {
        res[i] = ((nb / ten) - (stock )) + '0';
        stock = (stock + (res[i] - '0')) * 10;
        ten /= 10;
    }
    res[len] = '\0';
    return res;
}
