/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** Exo x.
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int num = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * neg);
}
