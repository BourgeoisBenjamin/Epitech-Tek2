/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(RadScorpion, creation, .init=redirect_all_std)
{
    if (1)
        RadScorpion test;
    cr_assert_stdout_eq_str("* click click click *\n"
                            "* SPROTCH *\n");
}

Test(RadScorpion, getType, .init=redirect_all_std)
{
    if (1) {
        RadScorpion test;
        cr_assert_eq(test.getType(), "RadScorpion");
    }
}

Test(RadScorpion, getHP, .init=redirect_all_std)
{
    if (1) {
        RadScorpion test;
        cr_assert_eq(test.getHP(), 80);
    }
}

Test(RadScorpion, takeDamage, .init=redirect_all_std)
{
    if (1) {
        RadScorpion test;
        test.takeDamage(6);
        cr_assert_eq(test.getHP(), 74);
    }
}