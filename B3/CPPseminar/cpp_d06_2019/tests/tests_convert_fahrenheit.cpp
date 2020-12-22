/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include <criterion/criterion.h>
#include "unittest.hpp"

Test(convert_fahrenheit, test00)
{
    cr_assert_eq(convert_fahrenheit(32), 0);
}

Test(convert_fahrenheit, test01)
{
    cr_assert_eq(convert_fahrenheit(104), 40);
}

Test(convert_fahrenheit, test02)
{
    cr_assert_eq(convert_fahrenheit(50), 10);
}

Test(convert_fahrenheit, test03)
{
    cr_assert_eq(convert_fahrenheit(-31), -35);
}