/*
** EPITECH PROJECT, 2021
** change base test
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include "../includes/bsprintf.h"

Test(change_base, test01)
{
    cr_assert_str_eq(change_base(11, "01234567"), "013");
}

Test(changebase, test02)
{
    cr_assert_str_eq(change_base(100, "0123456789ABCDEF"), "064");
}

Test(changebase, test03)
{
    cr_assert_str_eq(change_base(972, "0123456789ABCD"), "04D6");
}

Test(changebase, test04)
{
    cr_assert_str_eq(change_base(12, "0123456789ABCDEF"), "00C");
}

Test(changebase, test05)
{
    cr_assert_str_eq(change_base(12, "01234567"), "014");
}
