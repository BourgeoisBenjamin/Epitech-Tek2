/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(strcmp, test00, .init=redirect_all_std)
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
    str2[3] = 'D';
    cr_assert_eq(strcmp(str, str2), 0);
    free(str);
    free(str2);
}

Test(strcmp, test01, .init=redirect_all_std)
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
    str2[3] = '\0';
    cr_assert_gt(strcmp(str, str2), -1);
    free(str);
    free(str2);
}

Test(strcmp, test02, .init=redirect_all_std)
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
    str2[3] = '\0';
    cr_assert_gt(1, strcmp(str2, str));
    free(str);
    free(str2);
}