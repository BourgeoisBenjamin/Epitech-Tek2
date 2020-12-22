/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdio.h>

void int_displayer(void *data)
{
    int value = *((int *)data);
    printf("%d\n", value);
}

void g_test_size(list_t list_head)
{
    printf("There are %u elements in the list\n", list_get_size(list_head));
    list_dump(list_head, &int_displayer);
}

void g_test_del(list_t *list_head)
{
    list_del_elem_at_back(list_head);
    printf("There are %u elements in the list\n", list_get_size(*list_head));
    list_dump(*list_head, &int_displayer);
}