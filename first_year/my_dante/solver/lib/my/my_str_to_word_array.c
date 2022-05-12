/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** My str to word array.
*/

#include <stdlib.h>
#include <stddef.h>

int count_words(char *str, char obs)
{
    int res = 0;
    int j = 0;
    char limit = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != obs && str[i] != limit)
            j = 1;
        if ((str[i] == obs || str[i] == limit) && j == 1) {
            res++;
            j = 0;
        }
    }
    if (j == 1)
        res++;
    return res;
}

void fill_word_array(char **tab, char obs, char *str, char limit)
{
    int j = 0;
    int k = 0;
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != obs && str[i] != limit) {
            tab[j][k] = str[i];
            l = 1;
            k++;
        }
        if ((str[i] == obs || str[i] == limit) && l == 1) {
            k = 0;
            j++;
            l = 0;
        }
    }
}

char **my_str_to_word_array(char *str, char obs)
{
    int nb = count_words(str, obs);
    char **tab = malloc(sizeof(char*) * (nb + 1));
    int j = 0;
    int k = 0;
    char limit = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != obs && str[i] != limit)
            k++;
        if ((str[i] == obs || str[i] == limit) && k != 0) {
            tab[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        }
    }
    if (k != 0)
        tab[j] = malloc(sizeof(char) * (k + 1));
    fill_word_array(tab, obs, str, limit);
    return tab;
}
