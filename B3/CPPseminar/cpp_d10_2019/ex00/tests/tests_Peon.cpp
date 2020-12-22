/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Peon, creation_test, .init=redirect_all_std)
{
    if (1)
        Peon test("La Fouine");
    cr_assert_stdout_eq_str("Some random victim called La Fouine just popped!\n"
                            "Zog zog.\nBleuark...\n"
                            "Victim La Fouine just died for no apparent "
                            "reason!\n");
}

Test(Peon, getName, .init=redirect_all_std)
{
    Peon test("La Fouine");
    cr_assert_eq(test.getName(), "La Fouine");
}

Test(Peon, Osredirect, .init=redirect_all_std)
{
    if (1) {
        Peon test("La Fouine");
        std::cout << test;
    }
    cr_assert_stdout_eq_str("Some random victim called La Fouine just popped!\n"
                            "Zog zog.\n"
                            "I'm La Fouine and I like otters!\n"
                            "Bleuark...\n"
                            "Victim La Fouine just died for no apparent "
                            "reason!\n");
}

Test(Peon, getPolymorphed, .init=redirect_all_std)
{
    if (1) {
        Peon test("La Fouine");
        test.getPolymorphed();
    }
    cr_assert_stdout_eq_str("Some random victim called La Fouine just popped!\n"
                            "Zog zog.\n"
                            "La Fouine has been turned into a pink pony!\n"
                            "Bleuark...\n"
                            "Victim La Fouine just died for no apparent "
                            "reason!\n");
}