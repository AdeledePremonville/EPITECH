/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** myputnbr
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_put_nbr(int nb)
{
    char *str;
    int n = 10;
    int n2 = 10;
    int n3 = nb;
    int k = 0;

    for (;(nb / n2) >= 10; k++)
        n2 = n2 * 10;
    str = malloc(sizeof(char) * k + 1);
    if (nb >= 0 && nb <= 9)
        str[0] = (nb + '0');
    for (int i = 0; (n2 != 0) && (nb / n2) >= 1; i++) {
        str[i] = (n3 / n2) + '0';
        n3 = n3 - ((str[i] - '0') * n2);
        n2 = n2 / 10;
    }
    for (int j = 0; str[j] != '\0'; j++)
        my_putchar(str[j]);
    return 0;
}
