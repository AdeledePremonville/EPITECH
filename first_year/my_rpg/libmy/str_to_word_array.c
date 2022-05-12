/*
** EPITECH PROJECT, 2021
** str_to_word_array.c
** File description:
** str to word array
*/

#include "../include/my.h"
#include "../include/p.h"
#include <stdlib.h>
#include <unistd.h>

int count_nb_space(char *str, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ')
            res++;
    }
    return res;
}

int fill_line_array(char **array, char *buff, int j, int i)
{
    int nb_char = 0;
    int k = 0;

    for (int l = j; buff[l] != ' ' && buff[l] != '\0'; l++)
        nb_char++;
    array[i] = malloc(sizeof(char) * (nb_char + 3));
    if (array[i] == NULL)
        return -1;
    for (; buff[j] != ' ' && buff[j] != '\0'; j++, k++) {
        array[i][k] = buff[j];
    }
    if (buff[j] == ' ') {
        array[i][k] = ' ';
        array[i][k + 1] = '\0';
    } else
        array[i][k] = '\0';
    return j + 1;
}

char **str_to_word_array(char **array, char *buff, int size)
{
    int i = 0;
    int j = 0;

    array = malloc(sizeof(char*) * (count_nb_space(buff, size) + 2));
    while (j < size) {
        j = fill_line_array(array, buff, j, i);
        if (j == -1)
            return NULL;
        i++;
    }
    array[i] = NULL;
    return array;
}
