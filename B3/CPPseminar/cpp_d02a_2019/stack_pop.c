/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "stack.h"

bool stack_pop(stack_t *stack_ptr)
{
    return (list_del_elem_at_back(stack_ptr));
}