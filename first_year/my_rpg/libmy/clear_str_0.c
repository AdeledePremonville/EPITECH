/*
** EPITECH PROJECT, 2021
** clear_str_0.c
** File description:
** fill str of 0 or clear the first 0 of str
*/

#include "../include/my.h"
#include <stdlib.h>

int add_end_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            str[i] = '\0';
            return 0;
        }
    }
    return 84;
}

static int can_clear_space(char *res, int i_res, char *str, int i_str)
{
    if (i_res == 0)
        return 0;
    if ((res[i_res - 1] == ' ' || res[i_res - 1] == '\t') &&
        (str[i_str] == ' ' || str[i_str] == '\t'))
        return 1;
    return 0;
}

void change_chara(char *str, char old, char new)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old)
            str[i] = new;
    }
}

void delete_if_last_space(char *str)
{
    int len = my_strlen(str);

    if (len != 0) {
        if (str[len - 1] == ' ')
            str[len - 1] = '\0';
    }
}

char *clear_space(char *str)
{
    int i_str = 0;
    int i_res = 0;
    char *res;

    res = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (res == NULL)
        return NULL;
    while (str[i_str] == '\t' || str[i_str] == ' ')
        i_str++;
    while (str[i_str] != '\0') {
        if (can_clear_space(res, i_res, str, i_str) == 0) {
            res[i_res] = str[i_str];
            i_res++;
        }
        i_str++;
    }
    res[i_res] = '\0';
    change_chara(res, '\t', ' ');
    delete_if_last_space(res);
    return res;
}
