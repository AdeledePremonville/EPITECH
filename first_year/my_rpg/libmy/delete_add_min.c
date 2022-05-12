/*
** EPITECH PROJECT, 2021
** delete_add_min.c
** File description:
** delete or add a min to a str non const
*/

#include "../include/my.h"

char *delete_min_str(char *str)
{
    my_revstr(str);
    str[my_strlen(str) - 1] = '\0';
    my_revstr(str);
    return (str);
}

char *add_minus_str(char *str)
{
    int len = my_strlen(str);

    str = my_revstr(str);
    str[len] = '-';
    str[len + 1] = '\0';
    str = my_revstr(str);
    return (str);
}
