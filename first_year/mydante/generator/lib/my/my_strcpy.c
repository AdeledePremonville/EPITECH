/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** Exo 1.
*/

char *my_strcpy(char *dest, char const *src)
{
    int l = 0;

    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    for (int i = 0; src[i] != '\0'; i++)
        l++;
    dest[l] = '\0';
    return (dest);
}
