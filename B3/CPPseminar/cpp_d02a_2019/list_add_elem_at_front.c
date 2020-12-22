/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>

node_t *list_create_node(void *elem);

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *new = list_create_node(elem);

    if (!new)
        return (false);
    new->next = *front_ptr;
    *front_ptr = new;

    return (true);
}