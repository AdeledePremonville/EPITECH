/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-tetris-nicolas.poupon
** File description:
** get_arr_sizes.c
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>
#include <stdio.h>

int get_col(char **arr)
{
    int size = 0;

    for (int i = 0; arr[i] != NULL; ++i)
        size = i;
    return size;
}

int get_line(char **arr)
{
    int size = 0;

    for (int i = 0; arr[0][i] != '\0'; ++i)
        size = i;
    return size;
}

int *get_bounds(char **arr)
{
    int size[2] = {0, 0};

    for (int i = 0; arr[i] != NULL; ++i)
        size[0] = i;
    for (int i = 0; arr[0][i] != '\0'; ++i)
        size[1] = i;
}
