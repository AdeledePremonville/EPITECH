/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** displays one-by-one the characters of a string
*/

#include "../includes/bsprintf.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
