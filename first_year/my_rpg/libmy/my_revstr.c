/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char stock;

    while (j < i) {
        stock = str[j];
        str[j] = str[i];
        str[i] = stock;
        j++;
        i--;
    }
    return (str);
}
