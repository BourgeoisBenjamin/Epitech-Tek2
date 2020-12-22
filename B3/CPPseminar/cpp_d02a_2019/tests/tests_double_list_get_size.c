/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "double_list.h"

Test(double_list_get_size, test_one_node)
{
    double_list_t begin = malloc(sizeof(double_list_t));
    begin->next = NULL;
    cr_assert_eq(double_list_get_size(begin), 1);
    free(begin);
}

Test(double_list_get_size, test_no_node)
{
    cr_assert_eq(double_list_get_size(NULL), 0);
}

Test(double_list_get_size, test_two_node)
{
    double_list_t one = malloc(sizeof(double_list_t));
    double_list_t two = malloc(sizeof(double_list_t));
    one->next = two;
    two->next = NULL;
    cr_assert_eq(double_list_get_size(one), 2);
    free(one);
    free(two);
}