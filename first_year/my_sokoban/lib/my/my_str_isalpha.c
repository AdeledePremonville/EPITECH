/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** task12
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int n = 0;

    if (str == NULL)
        return 1;
    for (int i = 0; i < my_strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' &&
            str[i] <= 'z'))
            n++;
    }
    if (n == my_strlen(str))
        return 1;
    return (0);
}