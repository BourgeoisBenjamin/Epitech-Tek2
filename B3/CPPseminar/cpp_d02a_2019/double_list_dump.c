/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"
#include <stdio.h>

void double_list_dump(double_list_t list)
{
    for (doublelist_node_t *temp = list; temp; temp = temp->next)
        printf("%f\n", temp->value);
}