/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** returns the first argument raised to the power p
*/

#include <stdio.h>
#include <unistd.h>
void my_putchar(char c);

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}
