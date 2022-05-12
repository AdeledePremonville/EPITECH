/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** allocates memory to a string and copies
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup_jumpline(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 2));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    dest[my_strlen(dest) + 1] = '\0';
    dest[my_strlen(dest)] = '\n';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}

char *my_strdup_char(char const *src, char end)
{
    char *dest;
    int size = 0;
    int i = 0;

    while (src[size] != '\0' && src[size] != end)
        size++;
    dest = malloc(sizeof(char) * (size + 1));
    if (dest == NULL)
        return NULL;
    for (; src[i] != '\0' && src[i] != end; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strdup_three_char(char const *src, char sa, char sb, char sc)
{
    char *dest;
    int s = 0;
    int i = 0;

    while (src[s] != '\0' && src[s] != sa && src[s] != sb && src[s] != sc)
        s++;
    dest = malloc(sizeof(char) * (s + 1));
    if (dest == NULL)
        return NULL;
    while (src[i] != '\0' && src[i] != sa && src[i] != sb && src[i] != sc) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strndup(char const *src, int start, int end)
{
    char *dest;
    int len = end - start;
    int i = 0;

    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    while (start != end) {
        dest[i] = src[start];
        i++;
        start++;
    }
    dest[i] = '\0';
    return (dest);
}
