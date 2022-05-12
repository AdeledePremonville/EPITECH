/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** displays either N or P
*/

#include <unistd.h>
void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return (0);
}
