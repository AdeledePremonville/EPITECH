/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** This function will reverse a string.
*/

char *my_revstr(char *str)
{
    int j = 0;
    char *start = str;
    char *end = str;

    for (int i = 0; str[i] != '\0'; i++)
        j++;
    for (int i = 0; i < j - 1; i++)
        end++;
    for (int i = 0; i < j / 2; i++) {
        char temp = *end;

        *end = *start;
        *start = temp;
        start++;
        end--;
    }
    return str;
}
