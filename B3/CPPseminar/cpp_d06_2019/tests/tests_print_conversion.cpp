/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(print_conversion, test00, .init = redirect_all_std)
{
    print_conversion(8.000, "Degree");
    fflush(stdout);
    cr_assert_stdout_eq_str("           8.000          Degree\n");
}

Test(print_conversion, test01, .init = redirect_all_std)
{
    print_conversion(8.000, "Fahrenheit");
    fflush(stdout);
    cr_assert_stdout_eq_str("           8.000      Fahrenheit\n");
}

Test(print_conversion, test02, .init = redirect_all_std)
{
    print_conversion(-1.000, "Degree");
    fflush(stdout);
    cr_assert_stdout_eq_str("          -1.000          Degree\n");
}