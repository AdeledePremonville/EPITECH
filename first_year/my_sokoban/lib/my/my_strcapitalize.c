/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** task10
*/

#include <stdlib.h>

int my_strlen(char const *str);

int str_cap(int j, int i, char *str, char *res)
{
    if (j == 0) {
        j = 1;
        if (str[i] <= 'z' && str[i] >= 'a')
            res[i] = str[i] - ' ';
    }
    return j;
}

char *my_strcapitalize(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str)));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res[i] = str[i];
        if ((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= '9' &&
            str[i] >= '0') || (str[i] >= 'A' && str[i] <= 'Z')) {
            j = str_cap(j, i, str, res);
        } else
            j = 0;
        if (j == 1 && (str[i] >= 'Z' && str[i] <= 'A'))
            res[i] = str[i] + ' ';
    }
    return (res);
}