/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Banana, creation_test, .init=redirect_all_std)
{
    Banana test;
    cr_assert_eq(test.getName(), "banana");
    cr_assert_eq(test.getVitamins(), 5);
}
