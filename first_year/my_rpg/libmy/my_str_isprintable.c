/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** return 1 if str only contains char printable
*/

#include "../include/my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == '\0')
        return (1);
    for (; str[j] != '\0'; j++) {
        if (str[i] >= 32 && str[i] <= 127)
            i++;
    }
    if (i == j)
        return (1);
    return (0);
}
