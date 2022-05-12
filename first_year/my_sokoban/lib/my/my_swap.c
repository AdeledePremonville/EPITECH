/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** swaps the content of two integers
*/

#include <unistd.h>
void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int nbt;

    nbt = *a;
    *a = *b;
    *b = nbt;
}
