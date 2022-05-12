/*
** EPITECH PROJECT, 2021
** disp stdarg test
** File description:
** tests unit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

void disp_stdarg(char *s, ...);

void my_putchar(char c);

Test(disp_stdarg, basic, .init = cr_redirect_stdout)
{
    disp_stdarg("iiicccs", 2, 3, 4, 'e', 'i', 'a', "hello");
    cr_assert_stdout_eq_str("234eiahello");
}
