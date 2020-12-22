/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(rindex, test00, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    cr_assert_str_eq(rindex(str, 'C'), "CD");
    free(str);
}

Test(rindex, test01, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    cr_assert_str_eq(rindex(str, 'A'), "ABCD");
    free(str);
}

Test(rindex, test02)
{
    char *str = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    cr_assert_null(rindex(str, 'Z'));
    free(str);
}