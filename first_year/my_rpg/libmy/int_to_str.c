/*
** EPITECH PROJECT, 2021
** int_to_str.c
** File description:
** return str of int
*/

#include "../include/my.h"
#include <stdlib.h>

char *int_to_str(int nb)
{
    int len_nb = count_len_int(nb);
    char *str;
    int i = 0;
    int m10 = 1;

    if (nb == 0)
        return my_strdup("0");
    str = malloc(sizeof(char) * (len_nb + 1));
    if (str == NULL)
        return NULL;
    for (int j = 0; j != len_nb - 1; j++)
        m10 *= 10;
    while (i != len_nb) {
        str[i] = (nb / m10) + '0';
        nb = nb % m10;
        m10 = m10 / 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}
