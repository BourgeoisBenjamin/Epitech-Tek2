/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include <criterion/criterion.h>
#include "unittest.hpp"

Test(convert_celsius, test00)
{
    cr_assert_eq(convert_celsius(-10), 14);
}

Test(convert_celsius, test01)
{
    cr_assert_eq(convert_celsius(10), 50);
}

Test(convert_celsius, test02)
{
    cr_assert_eq(convert_celsius(0), 32);
}

Test(convert_celsius, test03)
{
    cr_assert_eq(convert_celsius(78.9), 174.02);
}