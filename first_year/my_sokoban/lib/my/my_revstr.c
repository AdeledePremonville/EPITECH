/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** task03
*/

#include <string.h>
#include <unistd.h>
#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str)
{
    int mid = (my_strlen(str) / 2);
    char *stock = malloc(sizeof(char) * mid + 1);
    int k = my_strlen(str) - 1;
    char *stock2 = malloc(sizeof(char) * mid + 1);

    for (int i = 0; i < mid; i++) {
        stock[i] = str[i];
    }
    for (int j = 0; j < mid; j++, k--) {
        str[j] = str[k];
        str[k] = stock[j];
    }
    return (str);
}
