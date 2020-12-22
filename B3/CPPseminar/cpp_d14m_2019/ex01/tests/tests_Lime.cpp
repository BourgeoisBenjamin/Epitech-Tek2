/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Lime, creation_test, .init=redirect_all_std)
{
    Lime test;
    cr_assert_eq(test.getName(), "lime");
    cr_assert_eq(test.getVitamins(), 2);
}
