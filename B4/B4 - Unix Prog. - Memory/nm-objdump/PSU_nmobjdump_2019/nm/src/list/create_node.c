/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

list_t *nm_create_node(void)
{
    list_t *new = malloc(sizeof(list_t));

    if (!new)
        return (NULL);
    new->name = NULL;
    new->st_info = 0;
    new->value = 0;
    new->next = NULL;
    return (new);
}