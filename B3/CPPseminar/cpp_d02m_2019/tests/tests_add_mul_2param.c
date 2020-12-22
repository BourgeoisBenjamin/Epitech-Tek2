/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"

Test(add_mul_2param, test_add)
{
    int first = 9;
    int second = 10;
    add_mul_2param(&first, &second);
    cr_assert_eq(first, 19);
}

Test(add_mul_2param, test_mul)
{
    int first = 9;
    int second = 10;
    add_mul_2param(&first, &second);
    cr_assert_eq(second, 90);
}