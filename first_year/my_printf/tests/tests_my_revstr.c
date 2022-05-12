/*
** EPITECH PROJECT, 2021
** tests my revstr
** File description:
** unit tests
*/

#include "../includes/bsprintf.h"
#include <criterion/criterion.h>
#include <string.h>

Test(myrevstr, test01)
{
    cr_assert_str_eq(my_revstr(strdup("hello")), "olleh");
}
