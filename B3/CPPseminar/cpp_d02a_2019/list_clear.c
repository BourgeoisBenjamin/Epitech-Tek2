/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include <stdbool.h>
#include <stddef.h>
#include "generic_list.h"

bool list_delete_node(node_t *node);

void list_clear(list_t *front)
{
    node_t *to_delete = NULL;

    while (*front) {
        to_delete = *front;
        *front = (*front)->next;
        list_delete_node(to_delete);
    }
    front = NULL;
}