/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stdlib.h>

bool double_list_delete_node(doublelist_node_t *node)
{
    if (!node) return (true);
    free(node);
    return (true);
}