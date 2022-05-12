/*
** EPITECH PROJECT, 2022
** my_intlen.c
** File description:
** my int len
*/

int my_intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}