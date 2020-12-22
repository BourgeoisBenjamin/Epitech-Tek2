/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "queue.h"

void *queue_front(queue_t queue)
{
    return (list_get_elem_at_front(queue));
}