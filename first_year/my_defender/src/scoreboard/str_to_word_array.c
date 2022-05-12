/*
** EPITECH PROJECT, 2022
** str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>

int nb_words(char *str, char delim)
{
    int res = 0;
    int j = 0;
    int i = 0;
    char delim2 = '\n';

    while (str[i] != '\0') {
        if (str[i] != delim && str[i] != delim2)
            j = 1;
        if ((str[i] == delim || str[i] == delim2) && j == 1) {
            res++;
            j = 0;
        }
        i++;
    }
    if (j == 1)
        res++;
    return res;
}

void fill_word_array(char **res, char delim, char *str, char delim2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    while (str[i] != '\0') {
        if (str[i] != delim && str[i] != delim2) {
            res[j][k] = str[i];
            l = 1;
            k++;
        }
        if ((str[i] == delim || str[i] == delim2) && l == 1) {
            k = 0;
            j++;
            l = 0;
        }
        i++;
    }
}

char **str_to_word_array(char *str, char delim)
{
    int nb = nb_words(str, delim);
    char **res = malloc(sizeof(char*) * (nb + 1));
    int j = 0;
    int k = 0;
    char delim2 = '\n';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delim && str[i] != delim2)
            k++;
        if ((str[i] == delim || str[i] == delim2) && k != 0) {
            res[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        }
    }
    if (k != 0)
        res[j] = malloc(sizeof(char) * (k + 1));
    fill_word_array(res, delim, str, delim2);
    return res;
}