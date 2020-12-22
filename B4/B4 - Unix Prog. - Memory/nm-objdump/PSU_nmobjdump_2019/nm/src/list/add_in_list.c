/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

list_t *nm_add_in_list(list_t *list, list_t *new)
{
    list_t *temp = NULL;

    if (!list)
        return (new);
    for (temp = list; temp->next; temp = temp->next);
    temp->next = new;
    return (list);
}