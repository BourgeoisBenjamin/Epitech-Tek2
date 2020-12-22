/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strcspn, test00, .init=redirect_all_std)
{
    cr_assert_eq(strcspn("Chocolat", "gua"), 6);
}

Test(strcspn, test01, .init=redirect_all_std)
{
    cr_assert_eq(strcspn("Chocolat", ""), 8);
}

Test(strcspn, test02, .init=redirect_all_std)
{
    cr_assert_eq(strcspn("", "gua"), 0);
}

Test(strcspn, test03, .init=redirect_all_std)
{
    cr_assert_eq(strcspn("Chocolat", "gujdisq"), 8);
}