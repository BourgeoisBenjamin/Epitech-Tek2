/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(creation, warrior_creation_1, .init=redirect_all_std)
{
    Warrior test("Benjamin", 34);
    cr_assert_eq(test.getLvl(), 34);
    cr_assert_eq(test.getPv(), 100);
    cr_assert_eq(test.getPower(), 100);
    cr_assert_stdout_eq_str("Benjamin Created\nI'm Benjamin "
                            "KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n");
}

Test(closeAttack, warrior_closeAttack_1, .init=redirect_all_std)
{
    Warrior test("Benjamin", 34);
    for (int i = 0; i < 5; i++)
        test.CloseAttack();
    cr_assert_stdout_eq_str("Benjamin Created\nI'm Benjamin "
    "KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nBenjamin strikes "
    "with his hammer\nBenjamin strikes with his hammer\nBenjamin strikes with"
    " his hammer\nBenjamin out of power\nBenjamin out of power\n");
}

Test(rangeAttack, warrior_rangeAttack_1, .init=redirect_all_std)
{
    Warrior test("Benjamin", 34);
    for (int i = 0; i < 11; i++)
        test.RangeAttack();
    cr_assert_stdout_eq_str("Benjamin Created\nI'm Benjamin "
    "KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nBenjamin "
    "intercepts\nBenjamin intercepts\nBenjamin intercepts\nBenjamin "
    "intercepts\nBenjamin intercepts\nBenjamin intercepts\nBenjamin "
    "intercepts\nBenjamin intercepts\nBenjamin intercepts\nBenjamin "
    "intercepts\nBenjamin out of power\n");
}