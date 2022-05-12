/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** returns the smallest prime number
*/

#include <stdio.h>
#include <unistd.h>

int prime(int nb)
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

int my_find_prime_sup(int nb)
{
    int compt = nb + 1;

    if (prime(nb) == 1) {
        return (nb);
    }
    while (prime(compt) != 1) {
        compt += 1;
    }
    return (compt);
}
