/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Sorcerer, creation_test, .init=redirect_all_std)
{
    if (1)
        Sorcerer test("Booba", "L'empereur du sale");
    cr_assert_stdout_eq_str("Booba, L'empereur du sale, is born!\n"
                            "Booba, L'empereur du sale, is dead. Consequences"
                            " will never be the same!\n");
}

Test(Sorcerer, getName, .init=redirect_all_std)
{
    Sorcerer test("Booba", "L'empereur du sale");
    cr_assert_eq(test.getName(), "Booba");
}

Test(Sorcerer, getTitle, .init=redirect_all_std)
{
    Sorcerer test("Booba", "L'empereur du sale");
    cr_assert_eq(test.getTitle(), "L'empereur du sale");
}

Test(Sorcerer, Osredirect, .init=redirect_all_std)
{
    if (1) {
    Sorcerer test("Booba", "L'empereur du sale");
    std::cout << test;
    }
    cr_assert_stdout_eq_str("Booba, L'empereur du sale, is born!\n"
                            "I am Booba, L'empereur du sale, and I like "
                            "ponies!\n"
                            "Booba, L'empereur du sale, is dead. Consequences"
                            " will never be the same!\n");
}

Test(Sorcerer, polymorph, .init=redirect_all_std)
{
    if (1) {
        Sorcerer test("Booba", "L'empereur du sale");
        Victim test1("Kaaris");
        test.polymorph(test1);
    }
    cr_assert_stdout_eq_str("Booba, L'empereur du sale, is born!\n"
                            "Some random victim called Kaaris just popped!\n"
                            "Kaaris has been turned into a cute little sheep!\n"
                            "Victim Kaaris just died for no apparent reason!\n"
                            "Booba, L'empereur du sale, is dead. Consequences"
                            " will never be the same!\n");
}