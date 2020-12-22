/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strncmp, test00, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    char *str2 = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    str2[0] = 'A';
    str2[1] = 'B';
    str2[2] = 'C';
    str2[3] = 'Z';
    cr_assert_eq(strncmp(str, str2, 3), 0);
    free(str);
    free(str2);
}

Test(strncmp, test01, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    char *str2 = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    str2[0] = 'A';
    str2[1] = 'B';
    str2[2] = 'C';
    str2[3] = 'Z';
    cr_assert_lt(strncmp(str, str2, 4), 0);
    free(str);
    free(str2);
}

Test(strncmp, test02, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    char *str2 = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    str2[0] = 'A';
    str2[1] = 'B';
    str2[2] = 'C';
    str2[3] = 'Z';
    cr_assert_gt(strncmp(str2, str, 4), 0);
    free(str);
    free(str2);
}