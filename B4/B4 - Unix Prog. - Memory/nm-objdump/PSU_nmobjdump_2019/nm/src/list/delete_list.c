/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/nm.h"

void nm_delete_list(list_t *list)
{
    list_t *to_delete = NULL;

    while (list) {
        to_delete = list;
        list = list->next;
        free(to_delete);
    }
    list = NULL;
}