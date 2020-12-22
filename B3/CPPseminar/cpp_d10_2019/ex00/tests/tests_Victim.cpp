/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Victim, creation_test, .init=redirect_all_std)
{
    if (1)
        Victim test("Kaaris");
    cr_assert_stdout_eq_str("Some random victim called Kaaris just popped!\n"
                            "Victim Kaaris just died for no apparent "
                            "reason!\n");
}

Test(Victim, getName, .init=redirect_all_std)
{
    Victim test("Kaaris");
    cr_assert_eq(test.getName(), "Kaaris");
}

Test(Victim, Osredirect, .init=redirect_all_std)
{
    if (1) {
        Victim test("Kaaris");
        std::cout << test;
    }
    cr_assert_stdout_eq_str("Some random victim called Kaaris just popped!\n"
                            "I'm Kaaris and I like otters!\n"
                            "Victim Kaaris just died for no apparent "
                            "reason!\n");
}

Test(Victim, getPolymorphed, .init=redirect_all_std)
{
    if (1) {
        Victim test("Kaaris");
        test.getPolymorphed();
    }
    cr_assert_stdout_eq_str("Some random victim called Kaaris just popped!\n"
    "Kaaris has been turned into a cute little sheep!\n"
    "Victim Kaaris just died for no apparent "
    "reason!\n");
}