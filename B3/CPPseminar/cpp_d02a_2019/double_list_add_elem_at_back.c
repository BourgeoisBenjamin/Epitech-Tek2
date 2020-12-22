/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>

doublelist_node_t *double_list_create_node(double elem);

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new = double_list_create_node(elem);
    doublelist_node_t *temp = NULL;

    if (!new) return (false);
    if (double_list_is_empty(*front_ptr)) {
        *front_ptr = new;
        return (true);
    }
    for (temp = *front_ptr; temp->next; temp = temp->next);
    temp->next = new;
    return (true);
}