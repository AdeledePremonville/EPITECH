/*
** EPITECH PROJECT, 2022
** my_arraylen.c
** File description:
** get length of an array
*/

#include <stdio.h>

int my_arraylen(char **str)
{
    int res = 0;
    while (str[res] != NULL)
        res++;
    return res;
}

int my_intarraylen(int **array)
{
    int res = 0;

    while (array[res] != NULL)
        res++;
    return res;
}