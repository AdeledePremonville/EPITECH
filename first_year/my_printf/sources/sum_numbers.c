/*
** EPITECH PROJECT, 2021
** sum_numbers
** File description:
** sum_numbers
*/

#include <stdarg.h>

int sum_numbers(int n, ...)
{
    va_list arg;
    int res = 0;

    va_start(arg, n);
    for (int i = 1; i <= n; i++)
        res += va_arg(arg, int);
    va_end(arg);
    return (res);
}
