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

Test(Buzz, test_speak, .init=redirect_all_std)
{
    Buzz test("Benjamin", "./sample/alien.txt");
    test.speak("I speak for a test");
    cr_assert_stdout_eq_str("BUZZ: Benjamin \"I speak for a test\"\n");
}

Test(Buzz, test_speak_es, .init=redirect_all_std)
{
    Buzz test("Benjamin", "./sample/alien.txt");
    test.speak_es("I speak for a test");
    cr_assert_stdout_eq_str("BUZZ: Benjamin senorita \"I speak for a test\" "
                            "senorita\n");
}