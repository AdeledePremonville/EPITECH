/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** puts every letter of every word in it in uppercase
*/

char *up_case_char(char *str, int i)
{
    char save;

    if (str[i] >= 'a' && str[i] <= 'z') {
        save = str[i];
        str[i] = save - ' ';
    }
    return (str);
}

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        str = up_case_char(str, i);
        i++;
    }
    return (str);
}
