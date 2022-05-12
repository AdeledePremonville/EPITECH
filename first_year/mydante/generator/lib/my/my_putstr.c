/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** This function will display a string.
*/

#include "../../includes/my.h"

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
