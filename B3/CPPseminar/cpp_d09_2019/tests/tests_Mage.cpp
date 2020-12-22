/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(creation, mage_creation_1, .init=redirect_all_std)
{
    Mage test("Benjamin", 56);
    cr_assert_eq(test.getLvl(), 56);
    cr_assert_eq(test.getPv(), 100);
    cr_assert_eq(test.getPower(), 100);
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin teleported\n");
}

Test(closeAttack, mage_closeAttack_1, .init=redirect_all_std)
{
    Mage test("Benjamin", 56);
    for (int i = 0; i < 11; i++)
        test.CloseAttack();
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin "
                            "teleported\nBenjamin blinks\nBenjamin "
                            "blinks\nBenjamin blinks\nBenjamin "
                            "blinks\nBenjamin blinks\nBenjamin "
                            "blinks\nBenjamin blinks\nBenjamin "
                            "blinks\nBenjamin blinks\nBenjamin "
                            "blinks\nBenjamin out of power\n");
}

Test(rangeAttack, mage_rangeAttack_1, .init=redirect_all_std)
{
    Mage test("Benjamin", 56);
    for (int i = 0; i < 5; i++)
        test.RangeAttack();
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin "
                            "teleported\nBenjamin launches a "
                            "fire ball\nBenjamin launches a "
                            "fire ball\nBenjamin launches a "
                            "fire ball\nBenjamin launches a fire "
                            "ball\nBenjamin "
                            "out of power\n");
}

Test(restorePower, mage_restorePower_1, .init=redirect_all_std)
{
    Mage test("Benjamin", 56);
    for (int i = 0; i < 3; i++)
        test.RestorePower();
    cr_assert_eq(test.getPower(), 100);
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin "
    "teleported\nBenjamin takes a mana potion\nBenjamin takes a mana "
    "potion\nBenjamin takes a mana potion\n");
}