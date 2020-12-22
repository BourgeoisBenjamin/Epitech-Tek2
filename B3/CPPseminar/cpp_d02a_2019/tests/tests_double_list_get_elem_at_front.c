/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include "unittest.h"
#include "double_list.h"

Test(double_list_get_elem_at_front, test_one_node)
{
    double_list_t begin = malloc(sizeof(double_list_t));
    begin->next = NULL;
    begin->value = 5678;
    cr_assert_eq(double_list_get_elem_at_front(begin), 5678);
    free(begin);
}