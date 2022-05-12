/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** task05
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

int same_str(char *str, char const *to_find, int i)
{
    int len = my_strlen(to_find);
    int n = 0;
    int j = i;

    for (int f = 0; (to_find[f] != '\0') && (str[j] != '\0'); f++, j++) {
        if (str[j] == to_find[f])
            n++;
    }
    if (n == len)
        return 1;
    return 0;
}

void fill_res(char *res, int i, char *str)
{
    int j = 0;

    while (str[i] != '\0') {
        res[j] = str[i];
        i++;
        j++;
    }
}

char *my_strstr(char *str, char const *to_find)
{
    char *res;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (same_str(str, to_find, i) == 1 && j == 0) {
            j++;
            res = malloc(sizeof(char) * (my_strlen(str) - i));
            fill_res(res, i, str);
        }
    }
    return (res);
}