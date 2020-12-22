/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(PowerFist, creation, .init=redirect_all_std)
{
    if (1)
        PowerFist test;
}

Test(PowerFist, getType, .init=redirect_all_std)
{
    if (1) {
        PowerFist test;
        cr_assert_eq(test.getName(), "Power Fist");
    }
}

Test(PowerFist, attack, .init=redirect_all_std)
{
    if (1) {
        PowerFist test;
        test.attack();
        cr_assert_stdout_eq_str("* pschhh... SBAM! *\n");
    }
}