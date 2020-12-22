/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(creation, priest_creation_1, .init=redirect_all_std)
{
    Priest test("Benjamin", 74);
    cr_assert_eq(test.getLvl(), 74);
    cr_assert_eq(test.getPv(), 100);
    cr_assert_eq(test.getPower(), 100);
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin teleported\nBenjamin "
                            "enters in the order\n");
}

Test(closeAttack, priest_closeAttack_1, .init=redirect_all_std)
{
    Priest test("Benjamin", 56);
    for (int i = 0; i < 11; i++)
        test.CloseAttack();
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin "
                            "teleported\nBenjamin enters in the "
                            "order\nBenjamin uses a spirit "
                            "explosion\nBenjamin "
                            "uses a spirit explosion\nBenjamin "
                            "uses a spirit explosion\nBenjamin "
                            "uses a spirit explosion\nBenjamin uses a spirit explosion\nBenjamin "
                            "uses a spirit explosion\nBenjamin uses a spirit explosion\nBenjamin "
                            "uses a spirit explosion\nBenjamin uses a spirit explosion\nBenjamin "
                            "uses a spirit explosion\nBenjamin out of power\n");
}

Test(health, priest_health_1, .init=redirect_all_std)
{
    Priest test("Benjamin", 56);
    for (int i = 0; i < 11; i++)
        test.Heal();
    cr_assert_eq(test.getPv(), 100);
    cr_assert_eq(test.getPower(), 0);
    cr_assert_stdout_eq_str("Benjamin Created\nBenjamin "
                            "teleported\nBenjamin enters in the "
                            "order\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin casts a little heal "
                            "spell\nBenjamin out of power\n");
}