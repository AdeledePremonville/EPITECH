/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** exo 1.
*/

void my_swap(int *a, int *b)
{
    int s = *a;

    *a = *b;
    *b = s;
}
