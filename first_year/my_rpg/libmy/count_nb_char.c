/*
** EPITECH PROJECT, 2021
** count_nb_char.c
** File description:
** count nb char in str
*/

int count_nb_char(char *str, char c)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            res++;
    }
    return res;
}
