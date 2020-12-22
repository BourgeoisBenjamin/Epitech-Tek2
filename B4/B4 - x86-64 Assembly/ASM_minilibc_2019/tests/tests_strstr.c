/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strstr, test00, .init=redirect_all_std)
{
    cr_assert_str_eq(strstr("Test", "est"), "est");
}

Test(strstr, test01, .init=redirect_all_std)
{
    cr_assert_str_eq(strstr("Bonjour je m'appelle Benjamin, et me voilà Benjamin", "Benjamin"), "Benjamin, et me voilà Benjamin");
}

Test(strstr, test02, .init=redirect_all_std)
{
    cr_assert_null(strstr("Hello, World!", "Terre"));
}

Test(strstr, test03, .init=redirect_all_std)
{
    cr_assert_str_eq(strstr("Hello World!", "Hello"), "Hello World!");
}