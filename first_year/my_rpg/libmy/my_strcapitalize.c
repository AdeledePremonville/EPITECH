/*
** EPITECH PROJECT, 2021
** my_strcapitalizecase.c
** File description:
** puts first letter of every word in it in capitalize
*/

#include "../include/my.h"

char *capitalize_case_char(char *str, int i)
{
    if (str[i] < 'a' || str[i] > 'z')
        return (str);
    if (it_is_alpha(str[i - 1]) == 1)
        str[i] = str[i] - ' ';
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = my_strlowcase(str);
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - ' ';
    i++;
    while (str[i] != '\0') {
        str = capitalize_case_char(str, i);
        i++;
    }
    return (str);
}
