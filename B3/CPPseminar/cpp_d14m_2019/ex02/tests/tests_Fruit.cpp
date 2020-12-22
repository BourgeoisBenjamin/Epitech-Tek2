/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Fruit, creation_test, .init=redirect_all_std)
{
    Fruit test("Fruit", 22);
    cr_assert_eq(test.getName(), "Fruit");
    cr_assert_eq(test.getVitamins(), 22);
}
