/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** count num of char in a string
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_arraylen(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}
