/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>

bool double_list_delete_node(doublelist_node_t *node);

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    doublelist_node_t *to_delete = NULL;
    if (double_list_is_empty(*front_ptr)) return (false);
    if (double_list_get_size(*front_ptr) == 1) {
        double_list_delete_node(*front_ptr);
        *front_ptr = NULL;
        return (true);
    }

    for (doublelist_node_t *temp = *front_ptr; temp->next; temp = temp->next)
        to_delete = temp;
    double_list_delete_node(to_delete->next);
    to_delete->next = NULL;
    return (true);
}