/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdlib.h>

node_t *list_create_node(void *elem);

bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int pos)
{
    node_t *new = NULL;
    node_t *temp = *front_ptr;

    if (!pos) return (list_add_elem_at_front(front_ptr, elem));
    if (!(*front_ptr)) return (false);
    new = list_create_node(elem);
    if (!new) return (false);
    if (list_get_size(*front_ptr) < (pos)) return (false);

    for (unsigned int i = 1; i != pos; i++, temp = temp->next) {
        if (!temp) {
            free(new);
            return (false);
        }
    }
    new->next = temp->next;
    temp->next = new;
    return (true);
}