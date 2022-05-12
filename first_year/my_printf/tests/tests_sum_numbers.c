/*
** EPITECH PROJECT, 2021
** test sum numbers
** File description:
** unit test
*/

#include <criterion/criterion.h>

int sum_numbers(int n, ...);

Test(sum_numbers, test01)
{
    cr_assert_eq(sum_numbers(3, 4, 5, 1), 10);
    cr_assert_eq(sum_numbers(0), 0);
}
