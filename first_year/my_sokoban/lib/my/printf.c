/*
** EPITECH PROJECT, 2021
** printf
** File description:
** printf
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <unistd.h>

void switch_case2(char const *format, va_list arg, int i);
void my_printf2(const char *format, va_list arg, int i);

void s_flags(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putstr(change_base(str[i], "01234567"));
        } else
            my_putchar(str[i]);
    }
}

void switchcase_tag(const char *format, int arg, int i)
{
    switch (format[i + 1]) {
    case 'o':
        if (change_base(arg, "01234567")[0] != '0')
            my_putchar('0');
        my_putstr(change_base(arg, "01234567"));
        break;
    case 'x':
        if (change_base(arg, "0123456789abcdef")[0] != '0')
            my_putstr("0x");
        my_putstr(change_base(arg, "0123456789abcdef"));
        break;
    case 'X':
        if (change_base(arg, "0123456789ABCDEF")[0] != '0')
            my_putstr("0X");
        my_putstr(change_base(arg, "0123456789ABCDEF"));
        break;
    }
}

void switchcase_modulo(const char *format, va_list arg, int i)
{
    switch (format[i + 1]) {
    case 's':
        my_putstr(va_arg(arg, char *));
        break;
    case 'c':
        my_putchar(va_arg(arg, int));
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(arg, int));
        break;
    case 'b':
        my_putstr(change_base(va_arg(arg, int), "01"));
        break;
    case 'S':
        s_flags(va_arg(arg, char*));
        break;
    default:
        switch_case2(format, arg, i);
    }
}

void switch_case2(char const *format, va_list arg, int i)
{
    switch (format[i + 1]) {
    case 'o':
        my_putstr(change_base(va_arg(arg, int), "01234567"));
        break;
    case 'u':
        my_putstr(change_base(va_arg(arg, int), "0123456789"));
        break;
    case 'x':
        my_putstr(change_base(va_arg(arg, int), "0123456789abcdef"));
        break;
    case 'X':
        my_putstr(change_base(va_arg(arg, int), "0123456789ABCDEF"));
        break;
    case '%':
        my_putchar('%');
        break;
    case '#':
        switchcase_tag(format, va_arg(arg, int), i + 1);
        break;
    }
}

int my_printf(const char *format, ...)
{
    va_list arg;
    int i = 0;
    int len = my_strlen(format);

    va_start(arg, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            switchcase_modulo(format, arg, i);
            i += 1 + (format[i + 1] == '#');
        } else
            my_putchar(format[i]);
        i++;
    }
    va_end(arg);
    return (0);
}
