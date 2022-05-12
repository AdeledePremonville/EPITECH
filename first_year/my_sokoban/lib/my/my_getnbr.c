/*
** EPITECH PROJECT, 2021
** my get nbr
** File description:
** mygetnbr function
*/

#include <stdio.h>
#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res = res * 10;
        res = res + (str[i] - '0');
    }
    return (res);
}