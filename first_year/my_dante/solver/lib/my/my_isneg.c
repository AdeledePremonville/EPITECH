/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** this function displays either N if the integer passed as parameter.
*/

#include "../../includes/my.h"

int my_isneg(int n)
{
    int negative;
    int positive;

    negative = 78;
    positive = 80;
    if (n < 0)
        my_putchar(negative);
    if (n >= 0)
        my_putchar(positive);
    my_putchar('\n');
}
