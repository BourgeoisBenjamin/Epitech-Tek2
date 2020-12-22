/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex03
*/

#ifndef STACK_H_
#define STACK_H_

#include "linked_list/generic_list.h"

typedef list_t mystack_t;

unsigned int stack_get_size(mystack_t stack);
bool stack_is_empty(mystack_t stack);

bool stack_push(mystack_t *stack_ptr, void *elem);
bool stack_pop(mystack_t *stack_ptr);

void *stack_top(mystack_t stack);

#endif /* STACK_H_ */
