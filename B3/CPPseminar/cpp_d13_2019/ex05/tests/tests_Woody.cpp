/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Woody, creation, .init=redirect_all_std)
{
    Woody test("Benjamin", "./sample/woody.txt");
    cr_assert_eq(test.getName(), "Benjamin");
    cr_assert_eq(test.getType(), Toy::WOODY);
}

Test(Woody, test_speak, .init=redirect_all_std)
{
    Woody test("Benjamin", "./sample/alien.txt");
    test.speak("I speak for a test");
    cr_assert_stdout_eq_str("WOODY: Benjamin \"I speak for a test\"\n");
}