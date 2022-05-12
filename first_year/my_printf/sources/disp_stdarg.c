/*
** EPITECH PROJECT, 2021
** disp stdarg
** File description:
** sources my printf
*/

#include "../includes/bsprintf.h"
#include <stdarg.h>

void disp_stdarg(char *s, ...)
{
    va_list arg;
    va_start(arg, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'c')
            my_putchar(va_arg(arg, int));
        if (s[i] == 's')
            my_putstr(va_arg(arg, char*));
        if (s[i] == 'i')
            my_putnbr(va_arg(arg, int));
    }
    va_end(arg);
}

/*
int main(void)
{
    char *s = "siiiccc";

    disp_stdarg(s, "hello", 2, 3, 4, 'c', 'e', 'a');
    return (0);
}
*/
