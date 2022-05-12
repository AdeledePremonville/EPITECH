/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** puts every letter of every word in it in lowercase
*/

char *low_case_char(char *str, int i)
{
    char save;

    if (str[i] >= 'A' && str[i] <= 'Z') {
        save = str[i];
        str[i] = save + ' ';
    }
    return (str);
}

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        str = low_case_char(str, i);
        i++;
    }
    return (str);
}
