/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Buzz, creation, .init=redirect_all_std)
{
    Buzz test("Benjamin", "./sample/buzz.txt");
    cr_assert_eq(test.getName(), "Benjamin");
    cr_assert_eq(test.getType(), Toy::BUZZ);
}