/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.h"

Test(memcpy, test00, .init=redirect_all_std)
{
    char *str = malloc(sizeof(char) * 4);
    char *str2 = malloc(sizeof(char) * 4);
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';
    memcpy(str2, str, 4);
    cr_assert_eq(str2[2], 'C');
    free(str);
    free(str2);
}