/*
** EPITECH PROJECT, 2020
** cpp_d02a_2019
** File description:
** TODO: add description
*/

#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    double_list_t temp = list;
    int nb_node = 0;

    while (temp) {
        nb_node++;
        temp = temp->next;
    }
    return (nb_node);
}