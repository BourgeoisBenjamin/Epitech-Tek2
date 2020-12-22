/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strlen, test00, .init=redirect_all_std)
{
    cr_assert_eq(strlen("Test"), 4);
}

Test(strlen, test01, .init=redirect_all_std)
{
cr_assert_eq(strlen(""), 0);
}

Test(strlen, test02, .init=redirect_all_std)
{
cr_assert_eq(strlen("Test\nTest"), 9);
}

Test(strlen, test03, .init=redirect_all_std)
{
cr_assert_eq(strlen("Hello World !"), 13);
}

Test(strlen, test04, .init=redirect_all_std)
{
    cr_assert_eq(strlen("\0"), 0);
}