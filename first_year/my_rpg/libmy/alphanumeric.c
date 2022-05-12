/*
** EPITECH PROJECT, 2021
** alphanumeric.c
** File description:
** return len alphanum str, delete non alpha num str
*/

#include "../include/my.h"

int count_space_to_cut(char const *str, int i);

int it_is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return (0);
    return (1);
}

int it_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}

int it_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

int count_len_alphanumeric(char const *str)
{
    int i = 0;

    while (it_is_alphanumeric(str[i]) == 0 && str[i] == ' ') {
        i++;
    }
    return (i);
}

char *delete_non_alphanumeric_char(char const *str, char *str_alpha)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        i = count_space_to_cut(str, i);
        if (it_is_alphanumeric(str[i]) == 0 || str[i] == ' ') {
            str_alpha[j] = str[i];
            j++;
        }
        i++;
    }
    str_alpha[j] = '\0';
    return (str_alpha);
}
