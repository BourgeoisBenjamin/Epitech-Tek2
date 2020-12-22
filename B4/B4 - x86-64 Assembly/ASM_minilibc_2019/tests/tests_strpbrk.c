/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strpbrk, test00, .init=redirect_all_std)
{
    cr_assert_str_eq(strpbrk("Chocolat", "gua"), "at");
}

Test(strpbrk, test01, .init=redirect_all_std)
{
    cr_assert_null(strpbrk("Chocolat", ""));
}

Test(strpbrk, test02, .init=redirect_all_std)
{
    cr_assert_null(strpbrk("", "gua"));
}

Test(strpbrk, test03, .init=redirect_all_std)
{
    cr_assert_str_eq(strpbrk("Chocolat", "gujdisqo"), "ocolat");
}