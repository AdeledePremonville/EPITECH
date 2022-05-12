/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** task02
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0') {
        i = i + 1;
    }
    for (int j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    return (dest);
}
