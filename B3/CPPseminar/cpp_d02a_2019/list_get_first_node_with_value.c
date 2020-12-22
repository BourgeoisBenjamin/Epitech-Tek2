/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>

node_t *list_get_first_node_with_value(list_t list, void *value,
    value_comparator_t val_comp)
{
    if (list_is_empty(list))
        return (NULL);

    for (node_t *temp = list; temp; temp = temp->next)
        if (!(val_comp(temp->value, value)))
            return (temp);
    return (NULL);
}