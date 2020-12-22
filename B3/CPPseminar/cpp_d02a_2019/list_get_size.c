/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;

    for (node_t *node = list; node; node = node->next)
        size++;
    return (size);
}