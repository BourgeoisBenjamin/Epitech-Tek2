/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(PlasmaRifle, creation, .init=redirect_all_std)
{
    if (1)
        PlasmaRifle test;
}

Test(PlasmaRifle, getType, .init=redirect_all_std)
{
    if (1) {
        PlasmaRifle test;
        cr_assert_eq(test.getName(), "Plasma Rifle");
    }
}

Test(PlasmaRifle, attack, .init=redirect_all_std)
{
    if (1) {
        PlasmaRifle test;
        test.attack();
        cr_assert_stdout_eq_str("* piouuu piouuu piouuu *\n");
    }
}