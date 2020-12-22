/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(memset, test00, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    memset(str, 'A', 4);
    cr_assert_eq(str[2], 'A');
    free(str);
}

Test(memset, test01, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 1000);
    memset(str, 'b', 1000);
    cr_assert_eq(str[789], 'b');
    cr_assert_eq(str[0], 'b');
    cr_assert_eq(str[999], 'b');
    free(str);
}

Test(memset, test02, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    memset(str, 'A', 4);
    memset(str, 'B', 2);
    cr_assert_eq(str[1], 'B');
    cr_assert_eq(str[3], 'A');
    free(str);
}

Test(memset, test03, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    memset(str, 0, 4);
    cr_assert_eq(str[2], 0);
    free(str);
}