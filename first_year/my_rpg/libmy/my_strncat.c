/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** str n cat
*/

int my_strlen_ncat(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int size_dest = my_strlen_ncat(dest);

    while (src[i] != '\0' && n != 0) {
        dest[size_dest] = src[i];
        n--;
        size_dest++;
        i++;
    }
    return (dest);
}
