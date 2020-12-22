/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/free.h"
#include "../include/malloc.h"

void free(void *ptr)
{
    memblock_t *tmp = NULL;

    if (!memmapsession)
        return;
    if (ptr == NULL)
        return;
    tmp = memmapsession->memsession;
    if (tmp->address == ptr) {
        tmp->freed = true;
        return;
    }
    while (tmp != NULL) {
        if (tmp->address == ptr) {
            tmp->freed = true;
            return;
        }
        tmp = tmp->next;
    }
}