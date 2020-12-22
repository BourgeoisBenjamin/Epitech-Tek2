/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "double_list.h"

Test(double_list_is_empty, test_empty)
{
    double_list_t begin = NULL;
    cr_assert_eq(double_list_is_empty(begin), true);
}

Test(double_list_is_empty, test_no_empty)
{
    double_list_t begin = malloc(sizeof(double_list_t));
    begin->next = NULL;
    cr_assert_eq(double_list_is_empty(begin), false);
    free(begin);
}