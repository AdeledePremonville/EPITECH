/*
** EPITECH PROJECT, 2021
** count_len_int.c
** File description:
** return len of int
*/

int count_len_int(int nb)
{
    int i = 0;

    while (nb != 0) {
        nb = nb / 10;
        i++;
    }
    return (i);
}
