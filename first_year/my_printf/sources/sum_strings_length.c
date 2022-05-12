/*
** EPITECH PROJECT, 2021
** sum strings length
** File description:
** sum strings length 
*/

#include "../includes/bsprintf.h"
#include <stdarg.h>
#include <unistd.h>

int sum_strings_length(int n, ...)
{
    va_list arg;
    int res = 0;

    va_start(arg, n);
    for (int i = 1; i <= n; i++)
        res += my_strlen(va_arg(arg, char*));
    va_end(arg);
    return (res);
}
