/*
** EPITECH PROJECT, 2021
** test sum strings length
** File description:
** unit tests
*/

#include <criterion/criterion.h>

int sum_strings_length(int n, ...);

Test(sum_strings_length, test01)
{
    cr_assert_eq(sum_strings_length(3, "hello", "world", "hi"), 12);
}
