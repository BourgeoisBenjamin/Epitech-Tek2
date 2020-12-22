/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include <stdbool.h>
#include "generic_list.h"

bool list_is_empty(list_t list)
{
    if (list)
        return (false);
    return (true);
}