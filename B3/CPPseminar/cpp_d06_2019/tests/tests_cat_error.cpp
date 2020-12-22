/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(cat_error, test00)
{
    cr_assert_eq(cat_error(1), 0);
}

Test(cat_error, test01)
{
    cr_assert_eq(cat_error(2), 1);
}

Test(cat_error, test02)
{
    cr_assert_eq(cat_error(-1), 0);
}

Test(cat_error, test03)
{
    cr_assert_eq(cat_error(0), 0);
}