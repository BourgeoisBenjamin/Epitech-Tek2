/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Coconut, creation_test, .init=redirect_all_std)
{
    Coconut test;
    cr_assert_eq(test.getName(), "coconut");
    cr_assert_eq(test.getVitamins(), 15);
}
