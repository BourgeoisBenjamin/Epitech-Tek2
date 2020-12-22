/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"

bool double_list_delete_node(doublelist_node_t *node);

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    doublelist_node_t *to_delete = *front_ptr;
    if (double_list_is_empty(*front_ptr)) return (false);

    *front_ptr = to_delete->next;
    double_list_delete_node(to_delete);
    return (true);
}