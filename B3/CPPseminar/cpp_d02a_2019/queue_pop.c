/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "queue.h"

bool queue_pop(queue_t *queue_ptr)
{
    return (list_del_elem_at_front(queue_ptr));
}