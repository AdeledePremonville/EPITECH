/*
** EPITECH PROJECT, 2021
** my_strlowcas
** File description:
** task09
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str)));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            res[i] = str[i] + ' ';
        else
            res[i] = str[i];
    }
    return (res);
}