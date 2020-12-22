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

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *to_delete = *front_ptr;
    if (list_is_empty(*front_ptr)) return (false);

    *front_ptr = to_delete->next;
    free(to_delete);
    return (true);
}