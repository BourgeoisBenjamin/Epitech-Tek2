/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/malloc.h"
#include "../include/error.h"

memblock_t *get_mem_block(void *address)
{
    memblock_t *tmp = memmapsession->memsession;

    if (address == NULL)
        return (NULL);
    if (tmp->address == address)
        return (tmp);
    while (tmp != NULL) {
        if (tmp->address == address)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}