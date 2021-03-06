/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdlib.h>

bool list_delete_node(node_t *node);

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    node_t *to_delete = NULL;
    node_t *temp = NULL;
    unsigned int i = 0;

    if (list_is_empty(*front_ptr)) return (false);
    if (list_get_size(*front_ptr) <= (position)) return (false);
    if (!position) return (list_del_elem_at_front(front_ptr));
    if ((position - 1) == list_get_size(*front_ptr))
        return (list_del_elem_at_back(front_ptr));

    for (to_delete = *front_ptr; i != position; to_delete = to_delete->next,
        i++) {
        if (!to_delete) return (false);
        temp = to_delete;
    }
    temp->next = to_delete->next;
    list_delete_node(to_delete);
    return (true);
}