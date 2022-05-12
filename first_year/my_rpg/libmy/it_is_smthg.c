/*
** EPITECH PROJECT, 2021
** it_is_smthg.c
** File description:
** return 0 if sign, prio sign
*/

int it_is_prio_sign(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return (0);
    return (1);
}

int it_is_a_sign(char c)
{
    if (c == '*' || c == '/' || c == '%' || c == '+' || c == '-')
        return (0);
    return (1);
}
