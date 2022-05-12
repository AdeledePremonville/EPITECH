/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** Duplication of a string
*/
#include <stdlib.h>
#include "../../includes/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = malloc(my_strlen(src) + 1);

    for (; i != my_strlen(src); i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
