/*
** EPITECH PROJECT, 2020
** stack
** File description:
** ex03
*/

#include "linked_list/stack.h"
#include "linked_list/generic_list.h"

unsigned int stack_get_size(mystack_t stack)
{
    return (list_get_size(stack));
}

bool stack_is_empty(mystack_t stack)
{
    return (list_is_empty(stack));
}

bool stack_push(mystack_t *stack, void *elem)
{
    return (list_add_elem_at_front(stack, elem));
}

bool stack_pop(mystack_t *stack)
{
    return (list_del_elem_at_front(stack));
}

void *stack_top(mystack_t stack)
{
    return (list_get_elem_at_front(stack));
}
