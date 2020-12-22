/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/realloc.h"

void *realloc(void *ptr, size_t size)
{
    void *newptr = NULL;
    memblock_t *old_block = NULL;

    if (size == 0 && ptr) {
        free(ptr);
        return (NULL);
    }
    if (!ptr)
        return (malloc(size));
    old_block = get_mem_block(ptr);
    if (old_block == NULL)
        return (NULL);
    if (size <= old_block->size)
        return (ptr);
    newptr = malloc(size);
    if (!newptr)
        return (NULL);
    memcpy(newptr, ptr, old_block->size);
    free(ptr);
    return (newptr);
}