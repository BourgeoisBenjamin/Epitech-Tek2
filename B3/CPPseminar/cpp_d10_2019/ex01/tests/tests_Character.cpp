/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "unittest.hpp"

Test(Character, creation, .init=redirect_all_std)
{
    Character test("Gandalf");
    cr_assert_eq(test.getAp(), 40);
    cr_assert_eq(test.getName(), "Gandalf");
    cr_assert_null(test.getWeapon());
}