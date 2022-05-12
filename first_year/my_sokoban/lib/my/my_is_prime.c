/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** returns 1 if the number is prime and 0 if not
*/

#include <unistd.h>
#include <stdio.h>
void my_putchar(char c);

int my_is_prime(int nb)
{
    int comp = 1;
    int compt2 = 0;

    if ((nb == 1) || (nb == 0) || (nb < 1)) {
        return (0);
    }
    while (comp <= nb) {
        if (nb % comp == 0) {
            compt2 = compt2 + 1;
        }
        comp = comp + 1;
    }
    if (compt2 == 2) {
        return (1);
    } else if (compt2 > 2) {
        return (0);
    }
    return (0);
}
