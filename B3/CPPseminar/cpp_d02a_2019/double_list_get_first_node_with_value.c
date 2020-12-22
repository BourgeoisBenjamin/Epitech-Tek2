/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
    double value)
{
    if (double_list_is_empty(list))
        return (NULL);

    for (doublelist_node_t *temp = list; temp; temp = temp->next)
        if (temp->value == value) return (temp);
    return (NULL);
}