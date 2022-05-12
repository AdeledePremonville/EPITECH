/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Best function ever.
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../includes/my.h"

int my_put_nbr_2(int nb)
{
    int res = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
    } else {
        if (nb < 0) {
            nb = nb * (-1);
            my_put_nbr(nb);
        }else if (nb >= 10) {
            res = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(res + 48);
        } else {
            my_putchar(nb + 48);
        }
    }
    return 0;
}

void primary_flags(char flag, va_list arg)
{
    int i = 0;

    if (flag == 'c')
        my_putchar(va_arg(arg, int));
    if (flag == 's')
        my_putstr(va_arg(arg, char*));
    if (flag == 'i' || flag == 'd')
        my_put_nbr(va_arg(arg, int));
    if (flag == 'u')
        my_put_nbr_2(va_arg(arg, int));
    i++;
}

void secondary_flags(char flag, va_list arg)
{
    int i = 0;

    if (flag == 'f')
        my_put_nbr(va_arg(arg, double));
    if (flag == '%')
        my_putchar('%');
    i++;
}

int my_printf(const char *s, ...)
{
    va_list arg;

    va_start(arg, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '%')
            my_putchar(s[i]);
        if (s[i] == '%') {
            i++;
            primary_flags(s[i], arg);
            secondary_flags(s[i], arg);
        }
    }
    va_end(arg);
    return 0;
}
