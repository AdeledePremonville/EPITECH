/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** task16
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int n = 0;

    if (str == NULL)
        return 1;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 32 && str[i] <= 127)
            n++;
    }
    if (n == my_strlen(str))
        return 1;
    return (0);
}