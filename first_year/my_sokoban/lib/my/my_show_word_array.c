/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** task03
*/

#include <stddef.h>
void my_putchar(char c);
int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
