/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list))
        return (0);
    return (list->value);
}