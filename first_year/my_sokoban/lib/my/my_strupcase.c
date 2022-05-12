/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** task08
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str)));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 'z' && str[i] >= 'a')
            res[i] = str[i] - ' ';
        else
            res[i] = str[i];
    }
    return (res);
}