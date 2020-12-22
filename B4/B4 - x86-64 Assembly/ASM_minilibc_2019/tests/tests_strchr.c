/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strchr, test00, .init=redirect_all_std)
{
    cr_assert_str_eq(strchr("Test", 'e'), "est");
}

Test(strchr, test01, .init=redirect_all_std)
{
    cr_assert_eq(strchr("", 'f'), NULL);
}

Test(strchr, test02, .init=redirect_all_std)
{
    cr_assert_str_eq(strchr("Test\nTest", '\n'), "\nTest");
}

Test(strchr, test03, .init=redirect_all_std)
{
    cr_assert_str_eq(strchr("Hello World !", '!'), "!");
}

Test(strchr, test04, .init=redirect_all_std)
{
    cr_assert_str_eq(strchr("Hello World !", '!'), "!");
}