/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Skat_test, general_test, .init=redirect_all_std)
{
    Skat s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    cr_assert_stdout_eq_str("Soldier Junior\n"
        "Soldier Junior reporting 5 stimpaks remaining sir!\n"
        "Time to kick some ass and chew bubble gum.\n");
}

Test(Skat_test, Test00, .init=redirect_all_std)
{
    Skat s("Junior", 5);
    cr_assert_eq(s.stimPaks(), 5);
}

Test(Skat_test, Test01, .init=redirect_all_std)
{
    Skat s("Junior", 5);
    int test = 0;
    s.shareStimPaks(2, test);
    cr_assert_eq(test, 2);
    cr_assert_eq(s.stimPaks(), 3);
    cr_assert_stdout_eq_str("Keep the change.\n");
}

Test(Skat_test, Test02, .init=redirect_all_std)
{
    Skat s("Junior", 5);
    int test = 0;
    s.shareStimPaks(6, test);
    cr_assert_eq(test, 0);
    cr_assert_eq(s.stimPaks(), 5);
    cr_assert_stdout_eq_str("Don't be greedy\n");
}

Test(Skat_test, Test03, .init=redirect_all_std)
{
    Skat s("Junior", 5);
    s.addStimPaks(5);
    cr_assert_eq(s.stimPaks(), 10);
    s.addStimPaks(0);
    cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
}

Test(Skat_test, Test04, .init=redirect_all_std)
{
    Skat s("Junior", 0);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    cr_assert_stdout_eq_str("Soldier Junior\n"
    "Soldier Junior reporting 0 stimpaks remaining sir!\n"
    "Mediiiiiic\n");
}