/*
** EPITECH PROJECT, 2021
** test my printf
** File description:
** myprintf unit test
*/

#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include "../includes/bsprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(myprintf, simple_string, .init = redirect_all_std)
{
    char *str = "bouabpua";
    int i = 678;

    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(myprintf, str_int, .init = redirect_all_std)
{
    char *str = "bonjour";
    int i = 72792;

    my_printf("hello\n%s %i", str, i);
    cr_assert_stdout_eq_str("hello\nbonjour 72792");
}

Test(myprintf, tonytest, .init = redirect_all_std)
{
    my_printf("Hello %s My favorite number is %d and %i and my name start with %c and I got 69%% at my_printf %c%c", "world !", 42, 7, 'T', '!', '\n');
    cr_assert_stdout_eq_str("Hello world ! My favorite number is 42 and 7 and my name start with T and I got 69% at my_printf !\n");
}

Test(myprintf, test, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 5);

    str[0] = 't';
    str[1] = 6;
    str[2] = 't';
    str[3] = 'o';
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\006to\n");
}

Test(myprintf, tag, .init = redirect_all_std)
{
    my_printf("Hello\n%#oo", 12);
    cr_assert_stdout_eq_str("Hello\n014o");
}
