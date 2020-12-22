/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stdlib.h>

bool list_delete_node(node_t *node)
{
    if (!node) return (true);
    free(node);
    return (true);
}