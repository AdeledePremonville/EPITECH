/*
** EPITECH PROJECT, 2021
** idk
** File description:
** idk
*/

#include <unistd.h>

char *my_strncpy(char *dest, char *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    for (int var = n; src[var] != '\0'; var++) {
    }
}
