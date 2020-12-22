/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(sort_convert, test00, .init = redirect_all_std)
{
    sort_convert("Celsius", -10.000);
    fflush(stdout);
    cr_assert_stdout_eq_str("          14.000      Fahrenheit\n");
}

Test(sort_convert, test01, .init = redirect_all_std)
{
sort_convert("Fahrenheit", 46.400);
fflush(stdout);
cr_assert_stdout_eq_str("           8.000         Celsius\n");
}