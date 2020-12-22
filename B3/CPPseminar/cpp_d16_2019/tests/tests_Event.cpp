/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

Test(Event, test00, .init=redirect_all_std)
{
    Event test;
}

Test(Event, test01, .init=redirect_all_std)
{
    Event test;
    Event test2(3, "Wake Up!");
    test = test2;
    cr_assert_eq(test.getEvent(), "Wake Up!");
    cr_assert_eq(test.getTime(), 3);
}

Test(Event, test02, .init=redirect_all_std)
{
    Event test;
    test.setEvent("Wake Up!");
    test.setTime(3);
    cr_assert_eq(test.getEvent(), "Wake Up!");
    cr_assert_eq(test.getTime(), 3);
}