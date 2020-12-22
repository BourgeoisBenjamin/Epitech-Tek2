/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>

double double_list_get_elem_at_back(double_list_t list)
{
    doublelist_node_t *temp = NULL;

    if (double_list_is_empty(list))
        return (0);
    for (temp = list; temp->next; temp = temp->next);
    return (temp->value);
}