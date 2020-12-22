/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>

void *list_get_elem_at_back(list_t list)
{
    node_t *temp = NULL;

    if (list_is_empty(list)) return (0);
    for (temp = list; temp->next; temp = temp->next);
    return (temp->value);
}