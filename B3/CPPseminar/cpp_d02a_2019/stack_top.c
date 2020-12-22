/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "stack.h"

void *stack_top(stack_t stack)
{
    return (list_get_elem_at_front(stack));
}