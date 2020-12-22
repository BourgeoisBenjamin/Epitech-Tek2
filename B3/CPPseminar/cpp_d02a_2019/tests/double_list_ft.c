/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>
#include <stdio.h>

void dl_populate_list(double_list_t *list_head)
{
    double_list_add_elem_at_back(list_head, 1);
    double_list_add_elem_at_back(list_head, 2);
    double_list_add_elem_at_back(list_head, 3);
    double_list_add_elem_at_back(list_head, 4);
    double_list_add_elem_at_back(list_head, 5);
    double_list_add_elem_at_position(list_head, 9, 6);
    double_list_del_elem_at_position(list_head, 3);
    printf("%lf\n", double_list_get_elem_at_position(*list_head, 2));
    double_list_del_elem_at_back(list_head);
}

void dl_test_size(double_list_t list_head)
{
    printf("There are %u elements in the list\n", double_list_get_size
    (list_head));
    double_list_dump(list_head);
}

void dl_test_del(double_list_t *list_head)
{
    double_list_del_elem_at_back(list_head);
    printf("There are %u elements in the list\n", double_list_get_size
    (*list_head));
    double_list_dump(*list_head);
}