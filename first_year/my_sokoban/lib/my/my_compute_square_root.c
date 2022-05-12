/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** returns the square root of the number
*/

#include <stdio.h>
#include <unistd.h>
void my_putchar(char c);

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0) {
        return (0);
    }
    while (result * result != nb) {
        if (result > nb) {
            return (0);
        }
        result = result + 1;
    }
    return (result);
}
