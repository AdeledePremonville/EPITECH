/*
** EPITECH PROJECT, 2021
** print_free_array.c
** File description:
** print or free an array
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

char **free_array_char(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    return (array);
}

int **free_array_int(int **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    return (array);
}

int print_array_char(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
    return (0);
}

int print_array_int(int **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != -1; j++)
            my_put_nbr(array[i][j]);
        my_putchar('\n');
    }
    return (0);
}

int print_array_char_fast(char **array, int size)
{
    for (int i = 0; array[i] != NULL; i++) {
        write(1, array[i], size);
    }
    return (0);
}
