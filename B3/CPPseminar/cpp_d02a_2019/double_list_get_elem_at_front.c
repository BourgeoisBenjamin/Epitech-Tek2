/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (double_list_is_empty(list))
        return (0);
    return (list->value);
}