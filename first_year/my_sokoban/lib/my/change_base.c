/*
** EPITECH PROJECT, 2021
** change_base.c
** File description:
** change base function
*/

#include <stdlib.h>
#include "../../include/my.h"

char *change_base(int nb, char *base)
{
    char *res;
    int basee = my_strlen(base);
    int i, j;
    int n = nb;
    int n1 = nb;

    for (j = 1; (n / basee) >= basee; ++j, n /= basee);
    res = malloc(sizeof(char) * j + 1);
    for (i = 0; i <= j;) {
        res[i] = base[n1 % basee];
        if ((n1 / basee) < basee) {
            i++;
            res[i] = base[n1 / basee];
        } else
            i++;
        n1 /= basee;
    }
    res = my_revstr(res);
    res[i + 1] = '\0';
    return (res);
}
