/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>

bool list_delete_node(node_t *node);

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *to_delete = NULL;
    if (list_is_empty(*front_ptr)) return (false);
    if (list_get_size(*front_ptr) == 1) {
        list_delete_node(*front_ptr);
        *front_ptr = NULL;
        return (true);
    }
    for (node_t *temp = *front_ptr; temp->next; temp = temp->next)
        to_delete = temp;
    list_delete_node(to_delete->next);
    to_delete->next = NULL;
    return (true);
}