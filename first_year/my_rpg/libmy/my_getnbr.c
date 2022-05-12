/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** get nbr from a string
*/

int my_strlen(char const *str);

int if_neg(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            j++;
        i++;
    }
    if (j % 2 == 1)
        return (1);
    return (0);
}

int where_start_nbr(char const *str)
{
    int i = 0;

    while (str[i] == '-' || str[i] == '+' || str[i] == '0')
        i++;
    if (str[i] < '0' || str[i] > '9')
        return (-1);
    return (i);
}

long what_is_my_nbr(char const *str, int start, long result)
{
    int s_nb = start;
    int mult10 = 1;
    int count = 0;
    int len = my_strlen(str);
    int calc = 0;

    while ((str[s_nb] >= '0' && str[s_nb] <= '9') && str[s_nb] != '\0')
        s_nb++;
    count = s_nb - start;
    if (count > 10)
        return (0);
    for (; count != 1; count--)
        mult10 = mult10 * 10;
    while (start < s_nb) {
        calc = (str[start] - '0') * mult10;
        result = result + calc;
        mult10 = mult10 / 10;
        start++;
    }
    return (result);
}

int check_if_there_isnb(char const *str)
{
    int i = 0;

    if ((str[0] != '+' && str[0] != '-') && (str[0] < '0' || str[0] > '9'))
        return (1);
    if (str[0] >= '0' && str[0] <= '9')
        return (0);
    while ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
        i++;
    if (i == my_strlen(str))
        return (1);
    if (str[i] >= '0' && str[i] <= '9')
        return (0);
    return (1);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long result = 0;
    int start = where_start_nbr(str);

    if (check_if_there_isnb(str) == 1)
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i = if_neg(str);
    if (start == -1)
        return (0);
    result = what_is_my_nbr(str, start, result);
    if (i == 1)
        result = result * -1;
    if (result > 2147483647 || result < -2147483648)
        return (0);
    return (result);
}
