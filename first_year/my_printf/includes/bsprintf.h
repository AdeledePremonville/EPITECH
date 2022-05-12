/*
** EPITECH PROJECT, 2021
** bsprintf.h
** File description:
** h file
*/

#ifndef BSPRINTF
    #define BSPRINTF
int sum_numbers(int n, ...);
int sum_strings_length(int n, ...);
void disp_stdarg(char *s, ...);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
int my_putnbr(int nb);
int my_printf(const char *format, ...);
char *change_base(int nb, char *base);
char *my_revstr(char *str);

#endif //BSPRINTF
