/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>

bool double_list_delete_node(doublelist_node_t *node);

bool double_list_del_elem_at_position(double_list_t *front_ptr, unsigned int
position)
{
    doublelist_node_t *to_delete = NULL;
    doublelist_node_t *temp = NULL;
    unsigned int i = 0;

    if (double_list_is_empty(*front_ptr)) return (false);
    if (double_list_get_size(*front_ptr) <= (position)) return (false);
    if (!position) return (double_list_del_elem_at_front(front_ptr));
    if ((position - 1) == double_list_get_size(*front_ptr)) return
    (double_list_del_elem_at_back(front_ptr));

    for (to_delete = *front_ptr; i != position; to_delete = to_delete->next,
        i++) {
        if (!to_delete) return (false);
        temp = to_delete;
    }
    temp->next = to_delete->next;
    double_list_delete_node(to_delete);
    return (true);
}