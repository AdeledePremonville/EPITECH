/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** return 1 if str only contains lower alpha char
*/

#include "../include/my.h"

int my_str_islower(char const *str)
{
    int i = 0;
    int j = 0;

    if (str[0] == '\0')
        return (1);
    for (; str[j] != '\0'; j++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
    }
    if (i == j)
        return (1);
    return (0);
}
