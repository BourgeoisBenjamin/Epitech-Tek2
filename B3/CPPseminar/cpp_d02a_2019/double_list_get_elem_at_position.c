/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>

double double_list_get_elem_at_position(double_list_t list, unsigned int
position)
{
    doublelist_node_t *temp = NULL;
    unsigned int i = 0;

    if (double_list_is_empty(list)) return (0);
    if (!position) return (double_list_get_elem_at_front(list));
    if (double_list_get_size(list) <= (position)) return (0);

    for (temp = list->next, i = 1; i != position; temp = temp->next, i++);
    return (temp->value);
}