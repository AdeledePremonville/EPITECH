/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;

    while (dest[i] != '\0') {
        i = i + 1;
    }
    for (int j = 0; src[j] != src[nb]; j++) {
        dest[i + j] = src[j];
    }
    return (dest);
}
