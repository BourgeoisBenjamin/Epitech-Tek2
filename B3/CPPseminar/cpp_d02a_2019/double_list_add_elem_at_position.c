/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stddef.h>
#include <stdlib.h>

doublelist_node_t *double_list_create_node(double elem);

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
    unsigned int position)
{
    doublelist_node_t *new = NULL;
    doublelist_node_t *temp = *front_ptr;

    if (!position) return (double_list_add_elem_at_front(front_ptr, elem));
    if (!(*front_ptr)) return (false);
    new = double_list_create_node(elem);
    if (!new) return (false);
    if (double_list_get_size(*front_ptr) < (position)) return (false);

    for (unsigned int i = 1; i != position; i++, temp = temp->next) {
        if (!temp) {
            free(new);
            return (false);
        }
    }
    new->next = temp->next;
    temp->next = new;
    return (true);
}