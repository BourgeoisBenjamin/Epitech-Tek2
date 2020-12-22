/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stdlib.h>
#include <stddef.h>

doublelist_node_t *double_list_create_node(double elem)
{
    doublelist_node_t *new = malloc(sizeof(doublelist_node_t));

    if (!new) return (NULL);
    new->value = elem;
    new->next = NULL;

    return (new);
}