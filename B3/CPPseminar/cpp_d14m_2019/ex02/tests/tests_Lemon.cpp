/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Lemon, creation_test, .init=redirect_all_std)
{
    Lemon test;
    cr_assert_eq(test.getName(), "lemon");
    cr_assert_eq(test.getVitamins(), 3);
}
